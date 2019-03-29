/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 06:54:28 by aalves            #+#    #+#             */
/*   Updated: 2019/03/29 10:38:51 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ast.h"

static bool	realloc_queue(t_token_queue *queue)
{
    void	*new;

	if (!(new = malloc(queue->max << 1)))
	{
		ft_error(1, (char *[]){"Token queue malloc failed"}, -1);
        return (false);
	}
	queue->base = ft_memcpy(new, queue->base, queue->max);
	queue->max <<= 1;
#if DEBUG
    printf("Queue reallocated, size = %lu\n", queue->max);
#endif
	return (true);
}

bool		ft_push_token(t_token_queue *queue, t_token *token)
{
    if (queue->base + queue->max < queue->last + sizeof(t_token)
		&& !realloc_queue(queue))
		return (false);
//	printf("into %p\n%.*s\n", queue->last, (int)token->size, token->s);
	ft_memcpy(queue->last, token, sizeof(t_token));
	queue->last += sizeof(t_token);
	return (true);
}
