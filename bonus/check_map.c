/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 20:55:27 by msamual           #+#    #+#             */
/*   Updated: 2021/01/13 20:57:45 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include <stdio.h>

int		map_size(char **map)
{
	int	res;

	res = 0;
	while (map[res])
		res++;
	return (res + 1);
}

int		check_valid_characters(char **map, int *posx, int *posy)
{
	int		player_count;
	int		pos[2];

	player_count = 0;
	pos[0] = -1;
	while (map[++pos[0]])
	{
		pos[1] = -1;
		while (map[pos[0]][++pos[1]])
		{
			if (!ft_strchr(" 01245NWSE", map[pos[0]][pos[1]]))
				return (puterror("invalid symbol on map"));
			if (ft_strchr("NWSE", map[pos[0]][pos[1]]))
			{
				*posx = pos[1];
				*posy = pos[0];
				player_count++;
			}
		}
	}
	if (player_count != 1)
		return (puterror("there is no player on map, or player is not alone"));
	return (0);
}

int		copy_map(char **map, char ***copy)
{
	int		i;
	int		j;
	char	**res;

	if (!(res = (char **)ft_calloc(map_size(map) + 1, sizeof(char *))))
		return (puterror("allocation error in copy_map"));
	i = 0;
	while (map[i])
	{
		if (!(res[i] = (char *)ft_calloc(ft_strlen(map[i]) + 1, sizeof(char))))
			return (puterror("allocation error in copy_map"));
		j = 0;
		while (map[i][j])
		{
			res[i][j] = map[i][j];
			j++;
		}
		res[i][j] = '\0';
		i++;
	}
	res[i] = NULL;
	*copy = res;
	return (0);
}

int		fill_map(char **map, int x, int y)
{
	if (!map[y] || !map[y][x] || !ft_strchr("012345WESN", map[y][x]))
		return (puterror("invalid map"));
	if (map[y][x] == '3' || map[y][x] == '1')
		return (0);
	map[y][x] = '3';
	if (!fill_map(map, x + 1, y) && !fill_map(map, x - 1, y)
			&& !fill_map(map, x, y + 1) && !fill_map(map, x, y - 1))
		return (0);
	return (-1);
}

int		check_map(t_all *all)
{
	int		posx;
	int		posy;
	char	**copy;
	int		i;

	copy = NULL;
	if (check_valid_characters(all->map, &posx, &posy) == -1)
		return (-1);
	if (copy_map(all->map, &copy) == -1)
		return (-1);
	if (fill_map(copy, posx, posy) == -1)
		return (-1);
	i = -1;
	while (copy[++i])
		free(copy[i]);
	free(copy);
	init_player(all, posx, posy);
	return (0);
}
