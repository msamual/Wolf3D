/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:25:58 by msamual           #+#    #+#             */
/*   Updated: 2020/10/28 13:26:11 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	chr;
	unsigned char	*res;

	chr = (unsigned char)c;
	res = (unsigned char *)s;
	while (n--)
	{
		if (*res == chr)
			return (res);
		res++;
	}
	return (NULL);
}
