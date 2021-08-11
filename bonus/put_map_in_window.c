/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map_in_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:35:45 by msamual           #+#    #+#             */
/*   Updated: 2021/01/13 21:37:24 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	print_dir(t_all *all, int scl)
{
	double	x;
	double	y;
	int		i;

	x = all->plr->pos->x;
	y = all->plr->pos->y;
	pixel_put(all, x * scl, y * scl, 0xff0000);
	i = -1;
	while (++i < 10)
	{
		x += all->plr->dir->x / 10;
		y += all->plr->dir->y / 10;
		pixel_put(all, x * scl, y * scl, 0xbbbbbb);
	}
}

void	put_line(t_all *all, char *line, int y, int scl)
{
	int	x;
	int	sc;

	x = 0;
	sc = 0;
	while (line[x])
	{
		if (line[x] == '1')
			pixel_put(all, x * scl + sc, y, 0xffaaff);
		sc++;
		if (sc == scl)
		{
			x++;
			sc = 0;
		}
	}
}

int		put_map(t_all *all, int scl)
{
	int	y;
	int	sc;

	y = 0;
	sc = 0;
	print_f_c(all);
	draw_rays(all);
	sprites(all);
	while (all->map[y] && scl)
	{
		put_line(all, all->map[y], y * scl + sc, scl);
		sc++;
		if (sc == scl)
		{
			y++;
			sc = 0;
		}
	}
	print_dir(all, scl);
	return (0);
}
