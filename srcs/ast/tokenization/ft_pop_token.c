/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 07:04:28 by aalves            #+#    #+#             */
/*   Updated: 2019/03/29 10:27:30 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ast.h"

t_token		*ft_pop_token(t_token_queue *queue)
{
	t_token	*ret;

	if (ft_empty_queue(queue))
	{
        ft_error(1, (char *[]){"Tokenization failed, tried to pop empty queue"}, -1);
		return (NULL);
	}
	ret = queue->pos;
	queue->pos += sizeof(t_token);
	return (ret);
}
