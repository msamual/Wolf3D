/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:12:35 by msamual           #+#    #+#             */
/*   Updated: 2021/01/13 21:13:54 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		key_handle(int keycode, t_all *all)
{
	if (keycode == 126)
		all->move->up = 1;
	if (keycode == 125)
		all->move->down = 1;
	if (keycode == 257)
		all->move->run = 1;
	if (keycode == 53)
		all->move->exit = 1;
	if (keycode == 13)
		all->move->forward = 1;
	if (keycode == 1)
		all->move->back = 1;
	if (keycode == 0)
		all->move->left = 1;
	if (keycode == 2)
		all->move->right = 1;
	if (keycode == 123)
		all->move->turn_left = 1;
	if (keycode == 124)
		all->move->turn_right = 1;
	return (0);
}

int		get_scale(t_all *all)
{
	int		y;
	int		x;
	int		scl;
	int		maxx;

	y = 0;
	scl = all->resolution->width / 150;
	while (all->map[y])
		y++;
	while (scl * y >= all->resolution->height)
		scl *= 0.9;
	y = 0;
	maxx = 0;
	while (all->map[y])
	{
		x = 0;
		while (all->map[y][x])
			x++;
		if (x > maxx)
			maxx = x;
		y++;
	}
	while (scl * maxx >= all->resolution->width)
		scl *= 0.9;
	return (scl);
}

void	draw(t_all **all)
{
	put_map((*all), (*all)->scl);
	print_crist(*all);
	mlx_put_image_to_window((*all)->win->mlx, (*all)->win->win,
										(*all)->win->img, 0, 0);
	mlx_do_sync((*all)->win->mlx);
}

int		to_window(t_all **all)
{
	mouse_handle(*all);
	move(*all);
	if ((*all)->move->run)
		move(*all);
	draw(all);
	return (0);
}
