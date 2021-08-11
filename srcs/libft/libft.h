/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:40:56 by msamual           #+#    #+#             */
/*   Updated: 2021/01/18 16:21:31 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define FT_ULONG_MAX	((unsigned long)(~0L))
# define FT_LONG_MAX	((long)(FT_ULONG_MAX >> 1))
# define FT_LONG_MIN	((long)(~FT_LONG_MAX))

int					g_error_code;

typedef struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

void				*ft_memset(void *b, int c, size_t len);
void				*ft_bzero(void *ptr, size_t size);
void				*ft_memcpy(void *dest, const void *src, size_t size);
void				*ft_memccpy(void *dest, const void *src, int c,
								size_t size);
void				*ft_memmove(void *dest, const void *source, size_t size);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(void *arr1, void *arr2, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *str);
size_t				ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, char const *append, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
								size_t loc);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_calloc(size_t count, size_t size);

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char const c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char *str);
void				ft_putendl(char *str);

t_list				*ft_create_elem(void *data);
void				ft_list_push_back(t_list **begin_list, void *data);
void				ft_list_push_front(t_list **begin_list, void *data);
int					ft_list_size(t_list *begin_list);
t_list				*ft_list_last(t_list *begin_list);
t_list				*ft_list_push_params(int ac, char **av);
void				ft_list_clear(t_list **begin_list);
t_list				*ft_list_at(t_list *begin_list, unsigned int nbr);
void				ft_list_reverse(t_list **begin_list);
void				ft_list_foreach(t_list *begin_list, void (*f)());
void				ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
								void *data_ref, int (*cmp)(void *, void *));
t_list				*ft_list_find(t_list *begin_list,
								void *data_ref, int (*cmp)());
void				ft_list_remove_if(t_list **begin_list, void *data_ref,
								int (*cmp)());
void				ft_list_merge(t_list **begin_list1, t_list *begin_list2);
void				ft_list_sort(t_list **begin_list,
								int (*cmp)(void *, void *));

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
								void (*del)(void *));
int					ft_isnumber(char *str);

#endif
