/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_parser_not.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 20:37:44 by aalves            #+#    #+#             */
/*   Updated: 2019/03/29 11:42:27 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ast.h"

static inline t_mpc_not	*get_p_not(t_parser *parser)
{
	return (&parser->parser.not);
}

bool	ft_eval_parser_not(t_parser *parser, t_token_queue *queue)
{
    t_mpc_not	*inner;

	inner = get_p_not(parser);
	return (!ft_eval_parser(inner->parser, queue));
}
