/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 23:35:35 by msamual           #+#    #+#             */
/*   Updated: 2020/08/03 23:44:33 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_clear(t_list **begin_list)
{
	if (*begin_list && (*begin_list)->next)
		ft_list_clear(&(*begin_list)->next);
	if ((*begin_list)->data)
		free((*begin_list)->data);
	free(*begin_list);
	*begin_list = NULL;
}
