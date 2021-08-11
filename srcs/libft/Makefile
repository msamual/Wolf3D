NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror -c
SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
ft_memset.c ft_strchr.c ft_strrchr.c ft_strdup.c ft_calloc.c ft_strlcpy.c \
ft_strlcat.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_tolower.c ft_toupper.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_create_elem.c ft_list_push_back.c \
ft_list_push_front.c ft_list_size.c ft_list_last.c ft_list_push_params.c \
ft_list_clear.c ft_list_at.c ft_list_reverse.c ft_list_foreach.c \
ft_list_foreach_if.c ft_list_find.c ft_list_remove_if.c ft_list_merge.c \
ft_list_sort.c ft_putstr.c ft_putendl.c ft_is_number.c
OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

.c.o:
	$(CC) $(FLAGS) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean fclean all
