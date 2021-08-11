/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:45:19 by msamual           #+#    #+#             */
/*   Updated: 2020/10/29 19:47:08 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{
	int				res;
	unsigned int	nb;

	res = 0;
	if (n < 0)
	{
		res++;
		nb = -n;
	}
	else
		nb = n;
	while (nb > 9)
	{
		res++;
		nb /= 10;
	}
	return (res + 1);
}

char		*ft_itoa(int n)
{
	char			*res;
	int				len;
	unsigned int	nb;

	len = intlen(n);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		nb = -n;
	}
	else
		nb = n;
	while (nb > 9)
	{
		res[--len] = nb % 10 + 48;
		nb /= 10;
	}
	res[len - 1] = nb + 48;
	return (res);
}
