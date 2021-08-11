/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:19:08 by msamual           #+#    #+#             */
/*   Updated: 2020/10/29 13:39:24 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*destination;
	unsigned char	*source;

	if (!dst && !src)
		return (NULL);
	destination = (unsigned char*)dst;
	source = (unsigned char*)src;
	i = 0;
	if (source < destination)
		while (++i <= len)
			destination[len - i] = source[len - i];
	else
		while (len-- > 0)
			*(destination++) = *(source++);
	return (dst);
}
