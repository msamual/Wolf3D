/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 22:21:21 by msamual           #+#    #+#             */
/*   Updated: 2020/08/03 22:34:03 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new;

	if (!begin_list)
		return ;
	new = ft_create_elem(data);
	new->next = *begin_list;
	*begin_list = new;
}
