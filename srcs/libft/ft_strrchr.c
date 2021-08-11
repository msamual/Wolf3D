/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:34:05 by msamual           #+#    #+#             */
/*   Updated: 2020/10/28 13:39:01 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char ch;
	char *res;

	ch = (char)c;
	res = NULL;
	while (*s)
	{
		if (*s == ch)
			res = (char *)s;
		s++;
	}
	if (*s == ch)
		res = (char *)s;
	return (res);
}
