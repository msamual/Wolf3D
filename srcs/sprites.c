/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:41:16 by msamual           #+#    #+#             */
/*   Updated: 2021/01/13 21:41:32 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	add_sprite(t_all *all, double x, double y)
{
	t_sprite *sprite;

	sprite = (t_sprite *)ft_calloc(1, sizeof(t_sprite));
	sprite->pos.x = x;
	sprite->pos.y = y;
	ft_list_push_back(&all->sprites, sprite);
}

void	init_sprites(t_all *all)
{
	int		x;
	int		y;

	y = 0;
	while (all->map[y])
	{
		x = 0;
		while (all->map[y][x])
		{
			if (all->map[y][x] == '2')
				add_sprite(all, x + 0.5, y + 0.5);
			x++;
		}
		y++;
	}
}

void	get_dist(t_all *all)
{
	t_sprite	*sprite;
	t_list		*lst;
	double		x;
	double		y;

	lst = all->sprites;
	while (lst)
	{
		sprite = (t_sprite *)lst->data;
		x = fabs(sprite->pos.x - all->plr->pos->x);
		y = fabs(sprite->pos.y - all->plr->pos->y);
		sprite->dist = hypot(x, y);
		lst = lst->next;
	}
}

int		sprite_cmp(void *s1, void *s2)
{
	t_sprite *a;
	t_sprite *b;

	a = (t_sprite *)s1;
	b = (t_sprite *)s2;
	if (a->dist >= b->dist)
		return (0);
	return (1);
}

void	sprites(t_all *all)
{
	get_dist(all);
	ft_list_sort(&all->sprites, &sprite_cmp);
	draw_sprites(all);
}
