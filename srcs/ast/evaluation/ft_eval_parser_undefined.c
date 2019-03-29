/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_parser_undefined.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 21:03:34 by aalves            #+#    #+#             */
/*   Updated: 2019/03/29 11:53:22 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ast.h"

bool	ft_eval_parser_undefined(t_parser *parser, t_token_queue *queue)
{
	(void)parser;
	(void)queue;
	ft_putstr_fd("Tried to eval undefined parser\n", STDERR_FILENO);
    return (false);
}
