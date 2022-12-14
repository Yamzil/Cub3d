# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjlem <mjlem@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 15:58:39 by yamzil            #+#    #+#              #
#    Updated: 2022/12/27 23:12:55 by mjlem            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	cub3D

NAME_SRC =	cub3D_bonus

INC =	mandatory_part/cub3d.h

INC_BNS = bonus_part/cub3d_bonus.h

SRC =	mandatory_part/cub3d.c\
		mandatory_part/parsing_part/check_map_utils.c\
		mandatory_part/parsing_part/free.c\
		mandatory_part/parsing_part/allocate_file.c\
		mandatory_part/parsing_part/parsing_utils.c\
		mandatory_part/parsing_part/parsing_error.c\
		mandatory_part/parsing_part/parsing_file.c\
		mandatory_part/parsing_part/storing_data.c\
		mandatory_part/parsing_part/check_file.c\
		mandatory_part/parsing_part/check_map.c\
		mandatory_part/graphic_part/draw_floor_ceilling.c\
		mandatory_part/graphic_part/intersection_ver.c\
		mandatory_part/graphic_part/intersection_hor.c\
		mandatory_part/graphic_part/raycasting_utils.c\
		mandatory_part/graphic_part/raycasting.c\
		mandatory_part/graphic_part/hook_utils.c\
		mandatory_part/graphic_part/distance.c\
		mandatory_part/graphic_part/minimap.c\
		mandatory_part/graphic_part/texture.c\
		mandatory_part/graphic_part/player.c\
		mandatory_part/graphic_part/mlx.c\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c\

BNC_SRC =	bonus_part/cub3d_bonus.c\
			bonus_part/parsing_part/check_map_utils.c\
			bonus_part/parsing_part/allocate_file.c\
			bonus_part/parsing_part/free.c\
			bonus_part/parsing_part/parsing_utils.c\
			bonus_part/parsing_part/parsing_error.c\
			bonus_part/parsing_part/parsing_file.c\
			bonus_part/parsing_part/storing_data.c\
			bonus_part/parsing_part/check_file.c\
			bonus_part/parsing_part/check_map.c\
			bonus_part/graphic_part/draw_floor_ceilling.c\
			bonus_part/graphic_part/intersection_ver.c\
			bonus_part/graphic_part/intersection_hor.c\
			bonus_part/graphic_part/raycasting_utils.c\
			bonus_part/graphic_part/raycasting.c\
			bonus_part/graphic_part/hook_utils.c\
			bonus_part/graphic_part/distance.c\
			bonus_part/graphic_part/minimap.c\
			bonus_part/graphic_part/texture.c\
			bonus_part/graphic_part/player.c\
			get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c\

OBJ = $(SRC:.c=.o)

OBJ_BNC = $(BNC_SRC:.c=.o)

MLX = -lmlx -framework OpenGL -framework AppKit

CC = cc

CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(INC) $(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) $(SRC) libft/libft.a $(MLX) -o $(NAME)

bonus : $(NAME_SRC)

$(NAME_SRC) :  $(INC_BNS) $(OBJ_BNC)
	make -C libft/
	$(CC) $(CFLAGS) $(BNC_SRC) libft/libft.a $(MLX) -o $(NAME_SRC)

clean : 
	@-rm -rf $(OBJ) $(OBJ_BNC)

fclean : clean
	make fclean -C libft
	@-rm -rf $(NAME) $(NAME_SRC)

re :fclean all