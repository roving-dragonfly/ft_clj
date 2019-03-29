/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_token_queue.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 09:57:52 by aalves            #+#    #+#             */
/*   Updated: 2019/03/29 10:35:34 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ast.h"

t_token_queue	*ft_new_token_queue(size_t size)
{
	t_token_queue	*new;

	if (!size)
		size = 1 << 12;
	if (!ft_is_power_of_two(size))
	{
        ft_error(1, (char *[]){"Token queue size must be initialized by a power of two"}, -1);
        return (NULL);
	}
    if (!(new = malloc(sizeof(t_token_queue))) || !(new->base = malloc(size)))
	{
		ft_error(2, (char *[]){"Token queue malloc failed"}, -1);
		return (NULL);
	}
	new->pos = new->base;
	new->last = new->base;
	new->max = size;
	return (new);
}
