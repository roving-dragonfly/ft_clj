/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_implode_strings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 21:48:14 by aalves            #+#    #+#             */
/*   Updated: 2019/01/29 21:48:14 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static uint32_t	*ft_get_lens(char **strings, uint32_t *count, uint32_t *len)
{
	uint32_t	i;
	uint32_t	*lens;
	uint32_t	tmp;

	i = 0;
	*count = 0;
	while (strings[i++])
		(*count)++;
	if (!*count)
		return (NULL);
	if (!(lens = (uint32_t*)malloc(sizeof(uint32_t) * *count)))
		exit(EXIT_FAILURE);
	tmp = *count;
	i = 0;
	while (i < tmp)
	{
		lens[i] = ft_strlen(strings[i]);
		*len += lens[i++];
	}
	return (lens);
}

char			*ft_implode_strings(char **strings)
{
	char		*str;
	uint32_t	*lens;
	uint32_t	count;
	uint32_t	len;
	uint32_t	i;

	i = 0;
	len = 0;
	if (!strings || !(lens = ft_get_lens(strings, &count, &len)))
		return (NULL);
	if (!(str = ft_strnew(len)))
		exit(EXIT_FAILURE);
	i = 0;
	len = 0;
	while (i < count)
	{
		ft_memcpy(str + len, strings[i], lens[i]);
		len += lens[i++];
	}
	free(lens);
	return (str);
}
