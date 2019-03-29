/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 06:33:42 by aalves            #+#    #+#             */
/*   Updated: 2019/03/29 10:43:25 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ast.h"

static inline bool	is_whitespace(char c)
{
    return (c == ' ' || c == '\n' || c == ',');
}

static inline bool	is_delimiter(char c)
{
    if (ft_strchr(TOKEN_DELIMITER, c))
		return (true);
	return (false);
}

static inline bool	is_array_splice(char *s)
{
	return (*s == '~' && *(s + 1) == '@');
}

static inline void	push_current_token(t_token_queue *queue, char *string, size_t size)
{
	t_token	t;

	if (!size)
		return ;
	t.size = size;
	t.s = string;
	ft_push_token(queue, &t);
	size = 0;
}

static inline bool	is_quote(char c)
{
	return (c == '"');
}

static inline size_t	get_quote_size(char *s)
{
	size_t	size;

	size = 1;
	s++;
	while (*s)
	{
		if (*s == '\\' && is_quote(*(s + 1)))
		{
			s += 2;
			size += 2;
			continue;
		}
		else if (is_quote(*s))
			return (size + 1);
        s++;
		size++;
	}
	ft_error(1, (char *[]){"Tokenization : unmatched quote"}, -1);
	return (0);
}

static inline bool	is_comment(char c)
{
    return (c == ';');
}

static inline size_t	get_comment_size(char *s)
{
	size_t	size;
	size = 0;

	while (*s)
	{
		if (*s == '\n')
			return (size);
		s++;
		size++;
	}
	return (size);
}

static	bool		tokenize_rec(t_token_queue *queue, char *string, char *current, size_t size)
{
	if (!string)
		return (false);
	if (!*string)
	{
		push_current_token(queue, current, size);
		return (true);
	}
	if (is_whitespace(*string))
	{
		push_current_token(queue, current, size);
        return (tokenize_rec(queue, string + 1, string + 1, 0));
	}
	else if (is_array_splice(string))
	{
		push_current_token(queue, current, size);
		push_current_token(queue, string, 2);
        return (tokenize_rec(queue, string + 2, string + 2, 0));
	}
	else if (is_delimiter(*string))
	{
		push_current_token(queue, current, size);
		push_current_token(queue, string, 1);
        return (tokenize_rec(queue, string + 1, string + 1, 0));
	}
	else if (is_quote(*string))
	{
		push_current_token(queue, current, size);
		if (!(size = get_quote_size(string)))
			return (false);
		push_current_token(queue, string, size);
        return (tokenize_rec(queue, string + size, string + size, 0));
	}
	else if (is_comment(*string))
	{
		push_current_token(queue, current, size);
		size = get_comment_size(string);
		push_current_token(queue, string, size);
		return (tokenize_rec(queue, string + size, string + size, 0));
	}
    return (tokenize_rec(queue, string + 1, current, size + 1));
}

/*
**	Array based queue implementation
**  Realloc itself when full
**	Both self and the array are on the heap
*/

t_token_queue		*ft_tokenize(char *string)
{
	t_token_queue	*queue;

	if (!(queue = ft_new_token_queue(4096)))
	{
		ft_error(1, (char *[]){"Token queue allocation failed"}, -1);
		return (NULL);
	}
	if (!tokenize_rec(queue, string, string, 0))
	{
		ft_error(1, (char *[]){"Tokenization failed"}, -1);
		return (NULL);
	}
	printf("TOKEN QUEUE\n");
    ft_print_token_queue(queue);
	return (queue);
}
