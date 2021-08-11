/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:39:57 by msamual           #+#    #+#             */
/*   Updated: 2020/10/28 13:44:50 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t loc)
{
	int i;
	int k;

	i = 0;
	if (!(*needle))
		return ((char *)haystack);
	while (haystack[i])
	{
		k = 0;
		while (needle[k] && haystack[i + k] == needle[k] &&
				(i + k) < (int)loc)
			k++;
		if (!needle[k])
			return ((char *)(&(haystack[i])));
		i++;
	}
	return (NULL);
}
