/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 23:50:46 by msamual           #+#    #+#             */
/*   Updated: 2020/08/04 10:23:48 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list *res;

	res = begin_list;
	if (!begin_list)
		return (NULL);
	while (nbr > 0)
	{
		if (res->next)
		{
			res = res->next;
			nbr--;
		}
		else
			return (NULL);
	}
	return (res);
}
