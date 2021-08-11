/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:49:18 by msamual           #+#    #+#             */
/*   Updated: 2020/10/29 19:49:51 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	i = -1;
	if (!s)
		return (NULL);
	result = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!result)
		return (result);
	while (s[++i])
		result[i] = f(i, s[i]);
	result[i] = '\0';
	return (result);
}
