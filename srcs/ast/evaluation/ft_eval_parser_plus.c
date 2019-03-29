/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_parser_plus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:46:57 by sclolus           #+#    #+#             */
/*   Updated: 2019/03/29 11:53:33 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ast.h"

static inline t_mpc_plus	*get_p_plus(t_parser *parser)
{
	return (&parser->parser.plus);
}

bool	ft_eval_parser_plus(t_parser *parser, t_token_queue *queue)
{
	uint32_t    i;
	t_mpc_plus  *inner;
	void		*save;

	i = 0;
	inner = get_p_plus(parser);
	while (42)
	{
		save = queue->pos;
		if (!ft_eval_parser(inner->parser, queue))
		{
			queue->pos = save;
			return (i != 0 ? true : false);
		}
		i++;
	}
}
