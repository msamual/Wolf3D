/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 22:30:26 by msamual           #+#    #+#             */
/*   Updated: 2020/08/04 22:30:33 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *list_ptr;
	t_list *tmp;

	if (!begin_list)
		return ;
	while (*begin_list && (*cmp)((*begin_list)->data, data_ref) == 0)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	}
	if (!(*begin_list))
		return ;
	list_ptr = *begin_list;
	while (list_ptr && list_ptr->next)
	{
		if ((*cmp)(list_ptr->next->data, data_ref) == 0)
		{
			tmp = list_ptr->next->next;
			free(list_ptr->next);
			list_ptr->next = tmp;
		}
		else
			list_ptr = list_ptr->next;
	}
}
