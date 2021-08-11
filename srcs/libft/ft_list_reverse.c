/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 10:51:08 by msamual           #+#    #+#             */
/*   Updated: 2020/08/04 11:02:03 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list *tmp;
	t_list *prev;
	t_list *current;

	prev = NULL;
	tmp = NULL;
	if (!begin_list)
		return ;
	current = *begin_list;
	while (current)
	{
		tmp = current->next;
		current->next = prev;
		prev = current;
		current = tmp;
	}
	*begin_list = prev;
}
