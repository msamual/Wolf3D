/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 20:16:15 by msamual           #+#    #+#             */
/*   Updated: 2020/08/04 22:08:58 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_swap(t_list *a, t_list *b)
{
	void *tmp;

	tmp = a->data;
	a->data = b->data;
	b->data = tmp;
}

int		list_size(t_list *begin_list)
{
	int		count;

	count = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		count++;
	}
	return (count);
}

t_list	*list_at(t_list *begin_list, unsigned int nbr)
{
	t_list *res;

	res = begin_list;
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

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*cur;
	t_list	*rev;
	int		size;
	int		i;

	if (!begin_list)
		return ;
	cur = begin_list;
	size = list_size(begin_list);
	i = -1;
	while (++i < size)
	{
		rev = list_at(begin_list, --size);
		ft_list_swap(cur, rev);
		cur = cur->next;
	}
}
