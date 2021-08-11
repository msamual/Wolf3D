/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   port.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 12:27:23 by msamual           #+#    #+#             */
/*   Updated: 2021/01/17 14:55:32 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	change(t_all *all)
{
	int tmp;

	tmp = all->port->out.x;
	all->port->out.x = all->port->in.x;
	all->port->in.x = tmp;
	tmp = all->port->out.y;
	all->port->out.y = all->port->in.y;
	all->port->in.y = tmp;
}

void	port(t_all *all)
{
	int x;
	int y;

	y = -1;
	while (all->map[++y])
	{
		x = -1;
		while (all->map[y][++x])
		{
			if (all->map[y][x] == '4')
			{
				all->port->in.x = x;
				all->port->in.y = y;
			}
			if (all->map[y][x] == '5')
			{
				all->port->out.x = x;
				all->port->out.y = y;
			}
		}
	}
}
