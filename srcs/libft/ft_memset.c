/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:14:13 by msamual           #+#    #+#             */
/*   Updated: 2020/10/28 13:14:18 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	ch;

	ch = (unsigned char)c;
	str = (unsigned char *)b;
	while (len)
	{
		*str = ch;
		str++;
		len--;
	}
	return (b);
}
