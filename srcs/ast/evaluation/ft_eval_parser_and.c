/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_parser_and.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:31:10 by aalves            #+#    #+#             */
/*   Updated: 2019/03/29 14:57:46 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ast.h"

static inline t_mpc_and_n	*get_p_and(t_parser *parser)
{
	return (&parser->parser.and);
}

bool				ft_eval_parser_and(t_parser *parser, t_token_queue *queue)
{
	uint32_t		i;
	t_mpc_and_n		*inner;
    void			*save;

	i = 0;
	inner = get_p_and(parser);
	save = queue->pos;
	while (i < inner->n)
	{
		if (!ft_eval_parser(inner->parsers[i], queue))
		{
			queue->pos = save;
			return (false);
		}
		i++;
	}
	return (true);
}
