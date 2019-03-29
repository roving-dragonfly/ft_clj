/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sexp_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 05:58:17 by aalves            #+#    #+#             */
/*   Updated: 2019/03/29 15:23:16 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ast.h"

/*
**	Clojure-like grammar
**	Crafted by assembling combinatorial micro-parsers
*/

t_parser	*ft_get_sexp_ref(void)
{
	static t_parser	*p;

	if (!p)
		p = ft_sexp_parser();
	return (ft_get_parser_ref(p));
}

t_parser	*ft_get_list_ref(void)
{
	static t_parser	*p;

	if (!p)
		p = ft_list_parser();
	return (ft_get_parser_ref(p));
}


t_parser	*ft_sexp_parser(void)
{
	return (ft_get_parser_or_n(2, (t_parser *[])
			   {NULL,
			   ft_get_parser_str_any()}));
}

t_parser	*ft_list_parser(void)
{
	return (ft_get_parser_and_n(3, (t_parser *[])
				{ft_get_parser_onechar('('),
						ft_get_parser_multiply(ft_get_sexp_ref()),
						ft_get_parser_onechar(')')}));
}

t_parser	*ft_get_clojure_grammar(void)
{
	t_parser	*p;

	//Needed in order to not stack overflow on init, fix this better you lazy fkr
	p = ft_get_sexp_ref();
	p->parser.ref.ref->parser.or.parsers[0] = ft_get_list_ref();
	return (p);
}
