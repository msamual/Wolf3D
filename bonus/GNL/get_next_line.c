/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:55:22 by msamual           #+#    #+#             */
/*   Updated: 2020/11/19 13:19:33 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

t_lst	*ft_lstnew(int fd)
{
	t_lst	*new;

	if (!(new = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	new->fd = fd;
	new->next = NULL;
	new->reminder = NULL;
	return (new);
}

t_lst	*find_fd(int fd, t_lst **lst)
{
	t_lst *tmp;

	if (*lst == NULL)
		if (!(*lst = ft_lstnew(fd)))
			return (NULL);
	tmp = *lst;
	while (tmp->next)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (tmp->fd == fd)
		return (tmp);
	tmp->next = ft_lstnew(fd);
	return (tmp->next);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != c)
		s++;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

int		check(char *str, char **line, t_lst *lst, int code)
{
	char	*nl;

	if (!str)
		return (0);
	if ((nl = ft_strchr(str, '\n')))
	{
		*nl++ = '\0';
		if (!(nl = ft_join(NULL, nl, 0)))
			return (-1);
		if (!(*line = ft_join(*line, str, code)))
			return (-1);
		lst->reminder = nl;
		return (1);
	}
	if (!(*line = ft_join(*line, str, code)))
		return (-1);
	lst->reminder = NULL;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static t_lst	*list;
	t_lst			*current;
	int				res;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0
			|| !line || !(current = find_fd(fd, &list))
			|| read(fd, NULL, 0) < 0)
		return (-1);
	*line = (char *)malloc(1);
	*line[0] = '\0';
	if ((res = check(current->reminder, line, current, 1)))
		return (res);
	res = read_line(current, line);
	if (res == 0)
	{
		if (current->reminder)
			free(current->reminder);
		clear(&list, fd);
	}
	return (res);
}
