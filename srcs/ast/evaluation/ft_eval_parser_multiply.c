/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_parser_multiply.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 20:42:51 by aalves            #+#    #+#             */
/*   Updated: 2019/03/29 15:23:07 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ast.h"

static inline t_mpc_multiply	*get_p_multiply(t_parser *parser)
{
	return (&parser->parser.multiply);
}

bool		ft_eval_parser_multiply(t_parser *parser, t_token_queue *queue)
{
	t_mpc_multiply	*inner;
	void			*save;

	inner = get_p_multiply(parser);
	while (42)
	{
		save = queue->pos;
		printf("MULT ATE\n");
		if (!ft_eval_parser(inner->parser, queue))
		{
			queue->pos = save;
			return (true);
		}
	}
}
