/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:42:01 by msamual           #+#    #+#             */
/*   Updated: 2021/01/13 21:44:08 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	load_north(t_all *all)
{
	char	*addr;

	all->textures->north.img = mlx_xpm_file_to_image(all->win->mlx,
												all->path->north,
												&all->textures->north.width,
												&all->textures->north.height);
	if (all->textures->north.img == NULL)
		return (puterror("failed to open file north texture"));
	addr = mlx_get_data_addr(all->textures->north.img,
												&all->textures->north.bpp,
												&all->textures->north.size_line,
												&all->textures->north.en);
	all->textures->north.addr = addr;
	return (0);
}

int	load_west(t_all *all)
{
	char	*addr;

	all->textures->west.img = mlx_xpm_file_to_image(all->win->mlx,
												all->path->west,
												&all->textures->west.width,
												&all->textures->west.height);
	if (all->textures->west.img == NULL)
		return (puterror("failed to open file west texture"));
	addr = mlx_get_data_addr(all->textures->west.img, &all->textures->west.bpp,
												&all->textures->west.size_line,
												&all->textures->west.en);
	all->textures->west.addr = addr;
	return (0);
}

int	load_south(t_all *all)
{
	char	*addr;

	all->textures->south.img = mlx_xpm_file_to_image(all->win->mlx,
												all->path->south,
												&all->textures->south.width,
												&all->textures->south.height);
	if (all->textures->south.img == NULL)
		return (puterror("failed to open file south texture"));
	addr = mlx_get_data_addr(all->textures->south.img,
												&all->textures->south.bpp,
												&all->textures->south.size_line,
												&all->textures->south.en);
	all->textures->south.addr = addr;
	return (0);
}

int	load_east(t_all *all)
{
	char	*addr;

	all->textures->east.img = mlx_xpm_file_to_image(all->win->mlx,
												all->path->east,
												&all->textures->east.width,
												&all->textures->east.height);
	if (all->textures->east.img == NULL)
		return (puterror("failed to open file east texture"));
	addr = mlx_get_data_addr(all->textures->east.img, &all->textures->east.bpp,
												&all->textures->east.size_line,
												&all->textures->east.en);
	all->textures->east.addr = addr;
	return (0);
}

int	load_sprite(t_all *all)
{
	char	*addr;

	all->textures->sprite.img = mlx_xpm_file_to_image(all->win->mlx,
												all->path->sprite,
												&all->textures->sprite.width,
												&all->textures->sprite.height);
	if (all->textures->sprite.img == NULL)
		return (puterror("failed to open file sprite texture"));
	addr = mlx_get_data_addr(all->textures->sprite.img,
											&all->textures->sprite.bpp,
											&all->textures->sprite.size_line,
											&all->textures->sprite.en);
	all->textures->sprite.addr = addr;
	return (0);
}
