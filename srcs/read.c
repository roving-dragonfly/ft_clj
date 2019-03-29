/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 04:25:45 by aalves            #+#    #+#             */
/*   Updated: 2019/03/29 04:39:34 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_clj.h"

char *ft_read(void)
{
	static char	*line;

	//Maybe do some init on readline later
	if (line)
	{
		free(line);
		line = NULL;
	}
	line = readline("user>");
	if (line && *line)
	{
		add_history(line);
	}
	return (line);
}
