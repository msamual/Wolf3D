/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:27:21 by msamual           #+#    #+#             */
/*   Updated: 2020/10/29 15:29:25 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	if (!dst)
		return (0);
	i = 0;
	len = ft_strlen(src);
	if (!dstsize)
		return (len);
	while (*src && i < dstsize - 1)
	{
		dst[i] = *src;
		src++;
		i++;
	}
	dst[i] = '\0';
	return (len);
}
