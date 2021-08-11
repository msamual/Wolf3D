/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:25:37 by msamual           #+#    #+#             */
/*   Updated: 2021/01/13 21:26:35 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int			mouse_handle(t_all *all)
{
	int		x;
	int		y;
	int		d;

	d = all->screeny - all->resolution->width;
	mlx_mouse_get_pos(all->win->win, &x, &y);
	all->deltmx = x - 500;
	all->deltmy = y - 500;
	mlx_mouse_move(all->win->win, 500, 500 - all->dmouse);
	mlx_mouse_hide();
	return (0);
}
