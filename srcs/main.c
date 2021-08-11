/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:17:43 by msamual           #+#    #+#             */
/*   Updated: 2021/01/14 13:19:12 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		puterror(char *error_message)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(error_message, 2);
	return (-1);
}

int		ft_save(t_all *all)
{
	int fd;

	fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (fd < 0)
		return (puterror("can not create 'screenshot.bmp'"));
	header_bmp(all, fd);
	close(fd);
	return (0);
}

int		cube(char *filename, int save)
{
	t_all	*all;
	void	*mlx;

	mlx = mlx_init();
	if (init_all(&all) == -1)
		return (-1);
	if (parse(filename, all) == -1)
		return (-1);
	all->win->mlx = mlx;
	all->win->win = mlx_new_window(mlx, all->resolution->width,
		all->resolution->height, "Return to castle Wolfestein");
	init_image(all);
	if (load_textures(all) == -1)
		return (-1);
	draw(&all);
	if (save)
		return (ft_save(all));
	mlx_hook(all->win->win, 2, 1L << 0, key_handle, all);
	mlx_hook(all->win->win, 3, 10, key_release, all);
	mlx_hook(all->win->win, 17, 0, quit, NULL);
	mlx_loop_hook(all->win->mlx, to_window, &all);
	mlx_loop(all->win->mlx);
	return (0);
}

int		name_check(char *name)
{
	int		len;

	len = ft_strlen(name);
	if (!ft_strncmp(".cub", &name[len - 4], 5))
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		if (name_check(av[1]))
			return (cube(av[1], 0));
		return (puterror("invalid filename"));
	}
	else if (ac == 3)
	{
		if (!name_check(av[1]))
			return (puterror("invalid filename"));
		if (!ft_strncmp("--save", av[2], 10))
			return (cube(av[1], 1));
		else
			return (puterror("invalid flag"));
	}
	else if (ac > 3)
		return (puterror("to many arguments"));
	else
		return (puterror("insert path_to map as argument"));
	return (0);
}
