/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:13:59 by msamual           #+#    #+#             */
/*   Updated: 2020/10/29 19:25:46 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	l1;
	size_t	l2;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	res = (char *)ft_calloc(l1 + l2 + 1, sizeof(char));
	if (!res)
		return (NULL);
	ft_memmove(res, s1, l1 * sizeof(char));
	ft_memmove(&(res[l1]), s2, l2 * sizeof(char));
	return (res);
}
