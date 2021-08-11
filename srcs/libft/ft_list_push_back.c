/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 21:05:40 by msamual           #+#    #+#             */
/*   Updated: 2021/01/13 21:18:28 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *i;

	i = *begin_list;
	if (!begin_list)
		return ;
	if (!(*begin_list))
		*begin_list = ft_create_elem(data);
	else
	{
		while (i->next)
			i = i->next;
		i->next = ft_create_elem(data);
	}
}
