# **************************************************************************** #
#																			  #
#														 :::	  ::::::::	#
#	Makefile										   :+:	  :+:	:+:	#
#													 +:+ +:+		 +:+	  #
#	By: msamual <marvin@42.fr>					 +#+  +:+	   +#+		 #
#												 +#+#+#+#+#+   +#+			#
#	Created: 2020/12/10 13:22:36 by msamual		   #+#	#+#			  #
#	Updated: 2020/12/17 18:59:36 by msamual		  ###   ########.fr		#
#																			  #
# **************************************************************************** #

.PHONY: libft minilibx

NAME = cub3D
BONUS = cub3D_bonus

SRCS = srcs/main.c \
		srcs/GNL/get_next_line.c \
		srcs/GNL/get_next_line_utils.c \
		srcs/parse_map.c \
		srcs/parse_info.c \
		srcs/init.c \
		srcs/check_map.c \
		srcs/put_map_in_window.c \
		srcs/key_handle.c \
		srcs/pixel_put.c \
		srcs/key_handle_arrow.c \
		srcs/init_player.c \
		srcs/vectors.c \
		srcs/put_vert_line.c \
		srcs/texture.c \
		srcs/print_tools.c \
		srcs/mouse_handle.c \
		srcs/move.c \
		srcs/draw_rays.c \
		srcs/dda.c \
		srcs/sprites.c \
		srcs/textures1.c \
		srcs/draw_sprites.c \
		srcs/vectors1.c \
		srcs/print_sprite.c \
		srcs/bmp.c

SRC_BONUS = bonus/main.c \
		bonus/GNL/get_next_line.c \
		bonus/GNL/get_next_line_utils.c \
		bonus/parse_map.c \
		bonus/parse_info.c \
		bonus/init.c \
		bonus/check_map.c \
		bonus/put_map_in_window.c \
		bonus/key_handle.c \
		bonus/pixel_put.c \
		bonus/key_handle_arrow.c \
		bonus/init_player.c \
		bonus/vectors.c \
		bonus/put_vert_line.c \
		bonus/texture.c \
		bonus/print_tools.c \
		bonus/mouse_handle.c \
		bonus/move.c \
		bonus/draw_rays.c \
		bonus/dda.c \
		bonus/sprites.c \
		bonus/textures1.c \
		bonus/draw_sprites.c \
		bonus/vectors1.c \
		bonus/print_sprite.c \
		bonus/bmp.c \
		bonus/port.c \
		bonus/floor_filling.c

INC = includes/header.h \
		includes/get_next_line.h \
		includes/libft.h \
		includes/mlx.h

FLAGS = -Wall -Wextra -Werror -g

CC = gcc $(FLAGS)

OBJ = $(SRCS:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: libft minilibx $(NAME)

bonus: libft minilibx $(BONUS)

libft:
	make -C srcs/libft

minilibx:
	make -C minilibx

$(%.o): $(%.c)
	$(CC) -o $@ -c $^

$(NAME): $(OBJ) $(INC)
	cp minilibx/libmlx.dylib .
	$(CC) -o $@ $(OBJ) -L . -lmlx -framework OPENGL -framework Appkit -lm -Lsrcs/libft -lft

$(BONUS): $(OBJ_BONUS) $(INC)
	cp minilibx/libmlx.dylib .
	$(CC) -o $@ $(OBJ_BONUS) -L . -lmlx -framework OPENGL -framework Appkit -lm -Lsrcs/libft -lft

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	rm -f libmlx.dylib
	make -C srcs/libft/ clean
	make -C minilibx/ clean

fclean: clean
	rm -f $(NAME) $(BONUS)
	make -C srcs/libft/ fclean
	make -C minilibx/ clean

re: fclean all
