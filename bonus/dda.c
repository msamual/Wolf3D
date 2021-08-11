/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 20:57:58 by msamual           #+#    #+#             */
/*   Updated: 2021/01/13 20:58:23 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	dda(t_ray *ray, t_all *all)
{
	int wall;

	wall = 0;
	while (!wall)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->mapx += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->mapy += ray->step_y;
			ray->side = 1;
		}
		if (all->map[ray->mapy][ray->mapx] == '1')
			wall = 1;
	}
}
