/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 13:45:07 by msamual           #+#    #+#             */
/*   Updated: 2020/11/19 13:45:09 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 1000

typedef struct		s_lst
{
	struct s_lst	*next;
	int				fd;
	char			*reminder;
}					t_lst;

int					get_next_line(int fd, char **line);
char				*ft_strchr(const char *s, int c);
char				*ft_join(char *s1, char *s2, int code);
int					read_line(t_lst *lst, char **line);
int					check(char *str, char **line, t_lst *lst, int code);
void				clear(t_lst **begin_list, int fd);

#endif
