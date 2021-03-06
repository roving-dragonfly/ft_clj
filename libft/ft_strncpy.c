/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 21:49:16 by aalves            #+#    #+#             */
/*   Updated: 2019/01/29 21:49:16 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned long	*longword_ptr;
	unsigned long	*longword_dst;
	unsigned int	i;
	unsigned int	n;

	n = ft_strlen(src);
	n = n > len ? len : n;
	i = 0;
	while (src[i] && i < n % 8)
	{
		dst[i] = src[i];
		i++;
	}
	longword_ptr = (unsigned long*)(src + i);
	longword_dst = (unsigned long*)(dst + i);
	while (i < n)
	{
		*longword_dst++ = *longword_ptr++;
		i += 8;
	}
	while (i < len)
		dst[i++] = 0;
	return (dst);
}
