/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:58:48 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/17 18:47:47 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include "./Get_Next_line/get_next_line.h"

typedef struct s_data{
	char	**file;
	char	**map;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*color_floor;
	char	*color_celleing;
}s_data;

// LIBFT
int     ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
void	*ft_memset(void *b, int c, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
int		ft_atoi(const char *str);

//PARSING
void	check_floor_ceilling_color(char **av);
char	**max_color_for_ceilling(char **av);
void	get_data(s_data *lst, char **av);
char    **max_color_for_floor(char **av);
void	checkduplicatepath(char **av);
void	check_max_rgb(char **av);
void	parsing_map(char **av);
void	checkspace(char **av);
void	countpath(char **av);
int		countline(char **av);
char	**get_map(char **av);
void	check_map(char **av);

// GET NEXT LINE
char    *get_next_line(int fd);

#endif