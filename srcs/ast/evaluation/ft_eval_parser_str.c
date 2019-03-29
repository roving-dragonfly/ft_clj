/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_parser_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 21:07:23 by aalves            #+#    #+#             */
/*   Updated: 2019/03/29 11:53:25 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ast.h"

static inline t_mpc_str	*get_p_str(t_parser *parser)
{
	return (&parser->parser.string);
}

bool ft_eval_parser_str(t_parser *parser, t_token_queue *queue)
{
	t_mpc_str   *inner;

	inner = get_p_str(parser);
	if (ft_strncmp(inner->str, ft_peek_token(queue)->s, inner->len))
	{
        ft_pop_token(queue);
		return (true);
	}
	return (false);
}
