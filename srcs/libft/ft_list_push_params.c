/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 23:07:44 by msamual           #+#    #+#             */
/*   Updated: 2020/08/04 13:53:57 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *i;

	if (!begin_list)
		return ;
	i = ft_create_elem(data);
	i->next = *begin_list;
	*begin_list = i;
}

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*new_list;
	int		i;

	i = -1;
	new_list = NULL;
	if (ac < 1)
		return (NULL);
	while (++i < ac)
		ft_list_push_front(&new_list, av[i]);
	return (new_list);
}
