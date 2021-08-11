/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_filling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:38:31 by msamual           #+#    #+#             */
/*   Updated: 2021/01/20 13:21:38 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		load_floor(t_all *all)
{
	char	*addr;

	ft_putendl(all->path->floor);
	all->textures->floor.img = mlx_xpm_file_to_image(all->win->mlx,
												all->path->floor,
												&all->textures->floor.width,
												&all->textures->floor.height);
	if (all->textures->floor.img == NULL)
		return (puterror("failed to open file floor texture"));
	addr = mlx_get_data_addr(all->textures->floor.img,
											&all->textures->floor.bpp,
											&all->textures->floor.size_line,
											&all->textures->floor.en);
	all->textures->floor.addr = addr;
	return (0);
}

void	print_hline(t_all *all, t_fl fl, int y)
{
	int		x;
	int		tx;
	int		ty;
	int		color;

	x = 0;
	fl.dark = 1 - fl.rowdist / 15.0;
	if (fl.rowdist > 15.0)
		fl.dark = 0;
	while (x < all->resolution->width)
	{
		fl.cellx = (int)fl.realx;
		fl.celly = (int)fl.realy;
		tx = (int)(all->textures->floor.width * (fl.realx - fl.cellx)) &
					(all->textures->floor.width - 1);
		ty = (int)(all->textures->floor.height * (fl.realy - fl.celly)) &
					(all->textures->floor.height - 1);
		color = get_color(all->textures->floor, (double)ty, tx);
		get_dark(&color, fl.dark);
		pixel_put(all, x, y, color);
		fl.realx += fl.stepx;
		fl.realy += fl.stepy;
		x++;
	}
}

void	floor_filling(t_all *all)
{
	t_fl	fl;
	int		y;

	y = all->resolution->height / 2 + all->plr->view;
	while (y < all->resolution->height)
	{
		fl.raydirx0 = all->plr->dir->x - all->plr->plane->x;
		fl.raydiry0 = all->plr->dir->y - all->plr->plane->y;
		fl.raydirx1 = all->plr->dir->x + all->plr->plane->x;
		fl.raydiry1 = all->plr->dir->y + all->plr->plane->y;
		fl.p = y - all->resolution->height / 2 - all->plr->view;
		fl.posz = 0.5 * all->resolution->height;
		fl.rowdist = fl.posz / fl.p;
		fl.stepx = fl.rowdist * (fl.raydirx1 - fl.raydirx0)
								/ all->resolution->width;
		fl.stepy = fl.rowdist * (fl.raydiry1 - fl.raydiry0)
								/ all->resolution->width;
		fl.realx = all->plr->pos->x + fl.rowdist * fl.raydirx0;
		fl.realy = all->plr->pos->y + fl.rowdist * fl.raydiry0;
		print_hline(all, fl, y);
		y++;
	}
}
