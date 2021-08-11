/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:25:32 by msamual           #+#    #+#             */
/*   Updated: 2020/10/31 12:34:18 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	char		*dsts;
	char const	*srcs;
	size_t		n;
	size_t		dstlen;

	dsts = dst;
	srcs = src;
	n = size;
	while (n-- && *dst)
		dst++;
	dstlen = dst - dsts;
	n = size - dstlen;
	if (!n--)
		return (dstlen + ft_strlen(src));
	while (*src)
	{
		if (n)
		{
			*dst++ = *src;
			n--;
		}
		src++;
	}
	*dst = '\0';
	return (dstlen + (src - srcs));
}
