/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:34:18 by msamual           #+#    #+#             */
/*   Updated: 2021/01/20 13:22:51 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	print_line_sprite(t_all *all, int i, t_line line, t_sprite *sprite)
{
	int		color;
	int		*img;
	double	step;
	double	j;

	img = (int *)all->textures->sprite.addr;
	if (sprite->transy < all->z_buffer[i])
	{
		step = 1.0 * all->textures->sprite.height / line.height;
		j = (line.start - all->resolution->height / 2 + line.height /
				2 - all->plr->view) * step;
		sprite->dark = 1 - sprite->dist / 15.0;
		if (sprite->dist > 15)
			sprite->dark = 0;
		while (line.start < line.end && line.start < all->resolution->height)
		{
			color = (int)img[(int)(j) * all->textures->sprite.size_line
					/ 4 + (int)line.i];
			get_dark(&color, sprite->dark);
			if (color != 0 && i >= 0)
				pixel_put(all, i, line.start, color);
			line.start++;
			j += step;
		}
	}
}

void	print_sprite(t_all *all, int i, t_sprite *sprite)
{
	t_line	line;
	double	view;
	int		j;
	double	step;

	view = all->plr->view;
	line.height = (int)(all->resolution->height / sprite->transy);
	line.width = line.height;
	line.start = -line.height / 2 + all->resolution->height / 2 + view;
	if (line.start < 0)
		line.start = 0;
	line.end = line.height / 2 + all->resolution->height / 2 + view;
	if (line.end >= all->resolution->height)
		line.end = all->resolution->height - 1;
	line.i = 0;
	step = 1.0 * all->textures->sprite.width / line.width;
	i -= line.width / 2;
	j = line.width;
	while (j--)
	{
		if (i < all->resolution->width)
			print_line_sprite(all, i++, line, sprite);
		line.i += step;
	}
}
