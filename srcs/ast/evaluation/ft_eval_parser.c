/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 19:15:19 by aalves            #+#    #+#             */
/*   Updated: 2019/03/29 15:26:32 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ast.h"

/* bool	ft_eval_input(t_parser *parser, char **string) */
/* { */
/*         uint32_t        ret; */

/*         if ((ret = ft_eval_parser(parser, string)) && !**string) */
/*                 return (true); */
/*         return (false); */
/* } */

bool	ft_eval_parser(t_parser *parser, t_token_queue *queue)
{
	bool		ret;

	static const t_eval_parser	eval_parsers[18] = {
		{&ft_eval_parser_undefined}, {&ft_eval_parser_ref},
		{&ft_eval_parser_onechar}, {&ft_eval_parser_str},
		{NULL}, {NULL},
		{NULL}, {NULL},
		{NULL}, {NULL},
		{&ft_eval_parser_str_any}, {NULL},
		{NULL}, {&ft_eval_parser_and},
		{&ft_eval_parser_or}, {&ft_eval_parser_not},
		{&ft_eval_parser_plus}, {&ft_eval_parser_multiply}};
	ret = eval_parsers[parser->id].f(parser, queue);
		if (parser->id == REF)
		printf("REF>");
	if (parser->id == ONECHAR)
		printf("ONECHAR>");
	if (parser->id == AND)
		printf("AND>");
	if (parser->id == OR)
		printf("OR>");

	if (ret)
		printf("OK\n");
	else
		printf("FAILED\n");
	return (ret);
}

bool	ft_eval(t_parser *parser, t_token_queue *queue)
{
	bool	ret;

    queue->pos = queue->base;
	ret = ft_eval_parser(parser, queue);
	if (ret && ft_empty_queue(queue))
		return (true);
#if DEBUG
	printf("TOKENS LEFT:\n");
	while (!ft_empty_queue(queue))
	{
		t_token *t = ft_pop_token(queue);
		printf("Size : %lu\tValue : %.*s\n", t->size, (int)t->size, t->s);
	}
#endif
	return (false);
}
