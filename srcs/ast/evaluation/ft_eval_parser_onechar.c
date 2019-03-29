/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_parser_onechar.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:10:56 by aalves            #+#    #+#             */
/*   Updated: 2019/03/29 14:32:42 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ast.h"

static inline t_mpc_onechar	*get_p_str(t_parser *parser)
{
	return (&parser->parser.onechar);
}

bool						ft_eval_parser_onechar(t_parser *parser, t_token_queue *queue)
{
	t_mpc_onechar	*inner;
	t_token			*val;

	inner = get_p_str(parser);
	if (ft_empty_queue(queue))
		return (false);
	val = ft_peek_token(queue);
	printf("ONECHAR\nSize : %lu\tValue : %.*s\n", val->size, (int)val->size, val->s);
	if (val->size == 1 && *(val->s) == parser->parser.onechar.c)
	{
        ft_pop_token(queue);
		return (true);
	}
	return (false);
}
