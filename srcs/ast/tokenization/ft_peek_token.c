/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_peek_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 08:10:38 by aalves            #+#    #+#             */
/*   Updated: 2019/03/29 10:24:46 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ast.h"

t_token	*ft_peek_token(t_token_queue *queue)
{
	if (!queue->pos || ft_empty_queue(queue))
		return (NULL);
	return (queue->pos);
}
