# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 15:58:39 by yamzil            #+#    #+#              #
#    Updated: 2022/11/21 19:20:38 by yamzil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	cub3D

INC =	cub3d.h

SRC =	cub3d.c\
		Get_Next_line/get_next_line.c\
		Get_Next_line/get_next_line_utils.c\
		floor_ceilling.c\
		parsing_map.c\
		parsing_path.c\
		file_utils.c\
		parsing_utils.c\
		parsing_utils1.c\
		map_utils.c\
		ceilling_floor_utils.c\
		map_utils1.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra -g #-fsanitize=address

all : $(NAME)

$(NAME) : $(INC) $(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) $(SRC) libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean : 
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re :fclean all