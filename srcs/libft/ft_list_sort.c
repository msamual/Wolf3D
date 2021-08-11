/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 19:44:49 by msamual           #+#    #+#             */
/*   Updated: 2020/08/04 20:03:53 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	swap(t_list *a, t_list *b)
{
	void *tmp;

	tmp = a->data;
	a->data = b->data;
	b->data = tmp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int		sort;
	t_list	*l;

	sort = 0;
	l = *begin_list;
	if (!l || !l->next)
		return ;
	while (sort != -1)
	{
		while (l->next)
		{
			if ((*cmp)(l->data, l->next->data) > 0)
			{
				swap(l, l->next);
				sort++;
			}
			l = l->next;
		}
		if (sort == 0)
			return ;
		l = *begin_list;
		sort = 0;
	}
}
