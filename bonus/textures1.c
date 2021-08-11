/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:44:42 by msamual           #+#    #+#             */
/*   Updated: 2021/01/20 20:42:34 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		check_color(t_all *all)
{
	if (all->color->cred < 0 || all->color->cred > 255)
		return (0);
	if (all->color->cgreen < 0 || all->color->cgreen > 255)
		return (0);
	if (all->color->cblue < 0 || all->color->cblue > 255)
		return (0);
	if (all->color->fred < 0 || all->color->fred > 255)
		return (0);
	if (all->color->fgreen < 0 || all->color->fgreen > 255)
		return (0);
	if (all->color->fblue < 0 || all->color->fblue > 255)
		return (0);
	all->color->floor = all->color->fred * 65536 + all->color->fgreen * 256
			+ all->color->fblue;
	all->color->ceiling = all->color->cred * 65536 + all->color->cgreen * 256
		+ all->color->cblue;
	return (1);
}

int		path_tex(char **tex, char *path)
{
	if (*tex == NULL)
		*tex = ft_strdup(path);
	else
		return (puterror("duplicate path to texture"));
	return (1);
}

int		check_duplicate(t_list *lst)
{
	int		r;
	int		c;
	int		f;
	char	*str;

	r = 0;
	c = 0;
	f = 0;
	while (lst)
	{
		str = lst->data;
		if (*str == 'R')
			r++;
		if (*str == 'C')
			c++;
		if (*str == 'F')
			f++;
		lst = lst->next;
	}
	if (r > 1 || f > 1 || c > 1)
		return (puterror("duplicate params"));
	return (0);
}

void	clear_color(char ***color)
{
	char **ptr;

	ptr = *color;
	while (*color++)
		free(**color);
	free(ptr);
}

int		load_textures(t_all *all)
{
	if (load_north(all) || load_west(all) || load_south(all)
	|| load_east(all) || load_sprite(all) || load_floor(all))
		return (-1);
	return (0);
}
