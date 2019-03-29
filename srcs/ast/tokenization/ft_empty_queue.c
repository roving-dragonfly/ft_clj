/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_empty_queue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 10:22:48 by aalves            #+#    #+#             */
/*   Updated: 2019/03/29 10:40:49 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ast.h"

bool	ft_empty_queue(t_token_queue *queue)
{
	if (queue->pos > queue->last - sizeof(t_token))
		return (true);
	return (false);
}
