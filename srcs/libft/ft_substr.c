/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:40:02 by msamual           #+#    #+#             */
/*   Updated: 2020/10/31 13:51:35 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strnew(size_t size)
{
	return ((char *)ft_calloc(size, sizeof(char)));
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *res;

	if (!s || (!(res = ft_strnew(len + 1))))
		return (NULL);
	if (start < ft_strlen(s))
		ft_strlcpy(res, &(s[start]), len + 1);
	return (res);
}
