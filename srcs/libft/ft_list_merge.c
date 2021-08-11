/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 15:07:01 by msamual           #+#    #+#             */
/*   Updated: 2020/08/04 19:31:53 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *i;

	i = *begin_list1;
	if (!begin_list1)
		return ;
	if (!i)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	while (i->next)
		i = i->next;
	i->next = begin_list2;
}
