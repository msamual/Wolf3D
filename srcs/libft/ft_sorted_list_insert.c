/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 21:29:58 by msamual           #+#    #+#             */
/*   Updated: 2020/08/04 21:35:48 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*list;
	t_list	*new;

	list = *begin_list;
	if (!list)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	while (list->next && (*cmp)(data, list->next->data) > 0)
		list = list->next;
	new = ft_create_elem(data);
	new->next = list->next;
	list->next = new;
}
