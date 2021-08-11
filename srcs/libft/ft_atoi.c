/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:46:11 by msamual           #+#    #+#             */
/*   Updated: 2020/10/29 21:37:09 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int				neg;
	unsigned long	res;
	unsigned long	lim;

	neg = 0;
	res = 0;
	lim = FT_LONG_MAX / 10;
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	if (*str == '-')
		neg++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str > 47 && *str < 58)
	{
		if ((res > lim || (res == lim && (*str - 48) > 7)) && !neg)
			return (-1);
		else if ((res > lim || (res == lim && (*str - 48) > 8)) && neg)
			return (0);
		res = res * 10 + (*str - 48);
		str++;
	}
	if (neg)
		return (-res);
	return (res);
}
