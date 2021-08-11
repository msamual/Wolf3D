/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:01:00 by msamual           #+#    #+#             */
/*   Updated: 2021/01/13 21:05:56 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		get_index(t_all *all, t_vec sdir, t_sprite *sprite)
{
	t_vec	vec;
	double	inv;
	int		res;

	inv = 1.0 / (all->plr->plane->x * all->plr->dir->y -
					all->plr->dir->x * all->plr->plane->y);
	vec.x = inv * (all->plr->dir->y * sdir.x - all->plr->dir->x * sdir.y);
	vec.y = inv * (-all->plr->plane->y * sdir.x + all->plr->plane->x * sdir.y);
	sprite->transx = vec.x;
	sprite->transy = vec.y;
	res = (int)((all->resolution->width / 2) * (1 + vec.x / vec.y));
	return (res);
}

double	c_dist(double angle)
{
	double a;

	if (!angle)
		return (1);
	a = angle / (PI / 2 - angle);
	return (sqrt(pow(a, 2) + 1));
}

int		in_view(t_all *all, t_vec sdir)
{
	t_vec	left;
	t_vec	right;

	left = *all->plr->dir;
	right = *all->plr->dir;
	turn_vector(&left, -0.5);
	turn_vector(&right, 0.5);
	if (mul_scl(sdir, left) >= 0 && mul_scl(sdir, right) >= 0)
		return (1);
	return (0);
}

void	put_sprite(t_all *all, t_sprite *sprite)
{
	t_vec		sdir;
	int			i;

	i = 0;
	sdir.x = sprite->pos.x - all->plr->pos->x;
	sdir.y = sprite->pos.y - all->plr->pos->y;
	if (in_view(all, sdir))
	{
		i = get_index(all, sdir, sprite);
		if (sprite->transy > 0)
			print_sprite(all, i, sprite);
	}
}

void	draw_sprites(t_all *all)
{
	t_list		*lst;
	t_sprite	*sprite;

	lst = all->sprites;
	while (lst)
	{
		sprite = (t_sprite *)lst->data;
		put_sprite(all, sprite);
		lst = lst->next;
	}
}
