/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_splice_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 21:48:45 by aalves            #+#    #+#             */
/*   Updated: 2019/01/29 21:48:45 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

void	ft_list_splice_init(t_list_head *to_add, t_list_head *head)
{
	t_list_head	*first;
	t_list_head	*last;
	t_list_head	*at;

	if (!ft_list_empty(to_add))
	{
		first = to_add->next;
		last = to_add->prev;
		at = head->next;
		head->next = first;
		first->prev = head;
		last->next = at;
		at->prev = last;
		to_add->next = (void *)0;
		to_add->prev = (void *)0;
	}
}
