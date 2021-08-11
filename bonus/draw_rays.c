/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 20:59:00 by msamual           #+#    #+#             */
/*   Updated: 2021/01/13 21:00:26 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	first_step(t_ray *ray)
{
	if (ray->dirx > 0)
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->mapx + 1.0 - ray->x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = -1;
		ray->side_dist_x = (ray->x - ray->mapx) * ray->delta_dist_x;
	}
	if (ray->diry > 0)
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->mapy + 1.0 - ray->y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = -1;
		ray->side_dist_y = (ray->y - ray->mapy) * ray->delta_dist_y;
	}
}

void	delta(t_ray *ray)
{
	ray->delta_dist_x = sqrt(1 + (ray->diry * ray->diry) /
			(ray->dirx * ray->dirx));
	ray->delta_dist_y = sqrt(1 + (ray->dirx * ray->dirx) /
			(ray->diry * ray->diry));
}

void	perp(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp = (ray->mapx - ray->x + (1 - ray->step_x) / 2) / ray->dirx;
	else
		ray->perp = (ray->mapy - ray->y + (1 - ray->step_y) / 2) / ray->diry;
}

void	ray(t_all *all, t_vec *dir, int i)
{
	t_ray	ray;

	ray.x = all->plr->pos->x;
	ray.y = all->plr->pos->y;
	ray.mapx = (int)ray.x;
	ray.mapy = (int)ray.y;
	ray.side = 0;
	ray.dirx = dir->x;
	ray.diry = dir->y;
	delta(&ray);
	first_step(&ray);
	dda(&ray, all);
	perp(&ray);
	all->z_buffer[i] = ray.perp;
	if (ray.side == 0)
		ray.wallx = ray.y + ray.perp * ray.diry;
	else
		ray.wallx = ray.x + ray.perp * ray.dirx;
	ray.wallx -= floor(ray.wallx);
	put_vert_line(all, &ray, i);
}

void	draw_rays(t_all *all)
{
	int		i;
	t_vec	start;

	i = 0;
	sub_three(&start, all->plr->dir, all->plr->plane, 1);
	while (i < all->resolution->width)
	{
		ray(all, &start, i);
		add_vector(&start, all->plr->plane, all->resolution->width / 2);
		i++;
	}
}
