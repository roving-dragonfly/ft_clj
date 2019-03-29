/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_parser_str_any.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:20:28 by aalves            #+#    #+#             */
/*   Updated: 2019/03/29 15:07:20 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ast.h"

static inline t_mpc_str_any	*get_p_str(t_parser *parser)
{
	return (&parser->parser.str_any);
}

bool ft_eval_parser_str_any(t_parser *parser, t_token_queue *queue)
{
	t_mpc_str_any   *inner;

	inner = get_p_str(parser);
	if (ft_empty_queue(queue))
        return (false);
	printf("ANY\n");
	ft_pop_token(queue);
	return (true);
}
