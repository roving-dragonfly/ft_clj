/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 21:48:55 by aalves            #+#    #+#             */
/*   Updated: 2019/01/29 21:48:55 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	tmp_c;
	unsigned long	*longword_ptr;
	unsigned long	magicbit;

	i = 0;
	tmp_c = (unsigned char)c;
	magicbit = (~0UL / 255) * (unsigned char)c;
	while (i < len % 8)
		((unsigned char*)b)[i++] = tmp_c;
	longword_ptr = (unsigned long*)(b + i);
	while (i < len)
	{
		*longword_ptr++ = magicbit;
		i += 8;
	}
	return (b);
}
