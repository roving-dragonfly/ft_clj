/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_parser_or.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:24:15 by aalves            #+#    #+#             */
/*   Updated: 2019/03/29 14:41:58 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ast.h"

static inline t_mpc_or_n	*get_p_or(t_parser *parser)
{
	return (&parser->parser.or);
}

bool				ft_eval_parser_or(t_parser *parser, t_token_queue *queue)
{
	uint32_t	i;
	t_mpc_or_n	*inner;
	void		*save;

	i = 0;
	inner = get_p_or(parser);
	save = queue->pos;
	while (i < inner->n)
	{
		queue->pos = save;
		if (ft_eval_parser(inner->parsers[i], queue))
			return (true);
		i++;
	}
	queue->pos = save; // not necessary if invariant holds: good luck.
	return (false);
}
