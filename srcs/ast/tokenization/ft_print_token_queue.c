/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_token_queue.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 07:12:51 by aalves            #+#    #+#             */
/*   Updated: 2019/03/29 15:00:24 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ast.h"

void	ft_print_token_queue(t_token_queue *queue)
{
    t_token	*t;

	queue->pos = queue->base;
	while ((t = ft_pop_token(queue)))
	{
        		printf("Size : %lu\tValue : %.*s\n", t->size, (int)t->size, t->s);
		t++;
	}
}
