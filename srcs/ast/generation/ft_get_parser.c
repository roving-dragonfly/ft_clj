/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 18:58:36 by sclolus           #+#    #+#             */
/*   Updated: 2019/03/29 05:54:30 by aalvess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ast.h"

t_parser	*ft_get_undefined_parser(void)
{
	t_parser	*parser;

	if (!(parser = (t_parser*)malloc(sizeof(t_parser))))
		exit(EXIT_FAILURE);
	parser->id = UNDEFINED;
	parser->retained = UNRETAINED;
	parser->alloc = ALONE;
	parser->name = NULL;
	return (parser);
}
