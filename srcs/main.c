/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 03:25:55 by aalves            #+#    #+#             */
/*   Updated: 2019/03/29 14:45:37 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_clj.h"

int	main(int argc, char **argv)
{
    char			*line;
	t_token_queue	*queue;
	t_parser		*grammar;

	grammar = ft_get_clojure_grammar();
    ft_put_parser(grammar);
	while (42)
	{
		//Stops the REPL on EOF
		if (!(line = ft_read()))
			return (0);
        queue = ft_tokenize(line);
		if (ft_eval(grammar, queue))
            printf("Valid\n");
		else
			printf("Invalid\n");
	}
	return (0);
}
