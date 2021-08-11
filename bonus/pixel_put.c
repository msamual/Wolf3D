/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:33:17 by msamual           #+#    #+#             */
/*   Updated: 2021/01/13 21:33:32 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	pixel_put(t_all *all, int x, int y, int color)
{
	char	*adr;
	int		*img;

	if (x < 0 || x >= all->resolution->width)
		return ;
	if (y < 0 || y >= all->resolution->height)
		return ;
	adr = (char *)all->win->addr;
	img = (int *)(adr + y * all->win->line_l + x * 4);
	*img = color;
}
