/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:11:34 by msamual           #+#    #+#             */
/*   Updated: 2021/01/13 21:11:59 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	init_plane(t_all *all, int posx, int posy)
{
	if (all->map[posy][posx] == 'N')
	{
		all->plr->plane->x = ANGLE;
		all->plr->plane->y = 0;
	}
	if (all->map[posy][posx] == 'E')
	{
		all->plr->plane->x = 0;
		all->plr->plane->y = ANGLE;
	}
	if (all->map[posy][posx] == 'S')
	{
		all->plr->plane->x = -ANGLE;
		all->plr->plane->y = 0;
	}
	if (all->map[posy][posx] == 'W')
	{
		all->plr->plane->x = 0;
		all->plr->plane->y = -ANGLE;
	}
}

void	init_player(t_all *all, int posx, int posy)
{
	all->plr->pos->x = posx + 0.5;
	all->plr->pos->y = posy + 0.5;
	if (all->map[posy][posx] == 'N')
	{
		all->plr->dir->x = 0;
		all->plr->dir->y = -1;
	}
	if (all->map[posy][posx] == 'E')
	{
		all->plr->dir->x = 1;
		all->plr->dir->y = 0;
	}
	if (all->map[posy][posx] == 'S')
	{
		all->plr->dir->x = 0;
		all->plr->dir->y = 1;
	}
	if (all->map[posy][posx] == 'W')
	{
		all->plr->dir->x = -1;
		all->plr->dir->y = 0;
	}
	init_plane(all, posx, posy);
	all->map[posy][posx] = '0';
	rotate(all, 0.0000001);
}
