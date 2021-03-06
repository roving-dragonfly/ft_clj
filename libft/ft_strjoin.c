/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 21:49:12 by aalves            #+#    #+#             */
/*   Updated: 2019/01/29 21:49:12 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	s1_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen((char*)s1);
	len = s1_len + ft_strlen((char*)s2);
	if (!(str = ft_strnew(len)))
		return (0);
	ft_strcpy(str, s1);
	ft_strcpy(str + s1_len, s2);
	return (str);
}
