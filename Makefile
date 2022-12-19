# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 15:58:39 by yamzil            #+#    #+#              #
#    Updated: 2022/12/17 11:26:42 by yamzil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	cub3D

INC =	cub3d.h

SRC =	cub3d.c\
		allocate_file.c\
		parsing_file.c\
		parsing_utils.c\
		parsing_error.c\
		storing_data.c\
		check_file.c\
		check_map.c\
		raycasting.c\
		dda.c\
		minimap.c\
		distance.c\
		intersection_ver.c\
		intersection_hor.c\
		draw_floor_ceilling.c\
		raycasting_utils.c\
		player.c\
		check_map_utils.c\
		hook_utils.c\
		Get_Next_line/get_next_line.c\
		Get_Next_line/get_next_line_utils.c\
		texture.c\

OBJ = $(SRC:.c=.o)

MLX = -lmlx -framework OpenGL -framework AppKit

CC = cc

CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address

all : $(NAME)

$(NAME) : $(INC) $(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) $(SRC) libft/libft.a $(MLX) -o $(NAME)

clean : 
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re :fclean all