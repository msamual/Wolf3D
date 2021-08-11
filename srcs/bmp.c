/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 13:40:50 by msamual           #+#    #+#             */
/*   Updated: 2021/01/16 20:30:00 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	bmp_data(t_all *all, int fd)
{
	int				end;
	int				i;
	int				j;
	unsigned char	buf[all->resolution->width * all->resolution->height * 4];

	i = 0;
	end = all->win->line_l * (all->resolution->height - 1);
	while (end >= 0)
	{
		j = 0;
		while (j < all->resolution->width * 4)
			buf[i++] = (((unsigned char *)all->win->addr + end)[j++]);
		end -= all->win->line_l;
	}
	write(fd, buf, all->resolution->width * all->resolution->height * 4);
}

void	header_bmp(t_all *all, int fd)
{
	int				size;
	unsigned char	head[54];

	ft_bzero(head, 54);
	head[0] = 'B';
	head[1] = 'M';
	size = all->resolution->width * all->resolution->height * 4 + 54;
	*(int *)(head + 2) = size;
	*(int *)(head + 10) = 54;
	*(int *)(head + 14) = 40;
	*(int *)(head + 18) = all->resolution->width;
	*(int *)(head + 22) = all->resolution->height;
	*(int *)(head + 26) = 1;
	*(int *)(head + 28) = 32;
	write(fd, head, 54);
	bmp_data(all, fd);
}
