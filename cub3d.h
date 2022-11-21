/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:58:48 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/21 18:37:31 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/fcntl.h>
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
	int		floor;
	int		ceilling;
}s_data;

// LIBFT
int     ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
void	*ft_memset(void *b, int c, size_t len);
char	**ft_split(char const *s, char c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *s1);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

// FILE UTILS
char	**get_file(s_data *lst,char **av);
char 	**get_map(s_data *lst, int j);
int		countline(char **av);

// FLOOR CEILLING
int		check_max_rgb_ceilling(s_data *lst);
int		check_max_rgb_floor(s_data *lst);
int		check_ceilling(s_data *lst);
int		check_floor(s_data *lst);

// FLOOR CEILLING UTILS
char	**get_rgb_for_ceilling(s_data *lst);
char	**get_rgb_for_floor(s_data *lst);
int		valid_celling_floor(s_data *lst);
int		valid_celling(s_data *lst);
int		valid_floor(s_data *lst);

// MAP UTILS
int		valid_player_sourrnder(char **av, s_data *lst, int j);
int		valid_map_elements(char **av, s_data *lst, int j);
int		check_valid(char **av, s_data *lst, int j);
int		valid_player(char **av, s_data *lst, int j);

// PARSING MAP
int		check_map(char **av, s_data *lst, int j);
int		check_file(char **av, s_data *lst);
void	valid_data(s_data *lst);

// PARSING PATH
int		count_duplicate_path(s_data *lst);
int		checkspace(s_data *lst);

// PARSING UTILS
void	check_ver(s_data *lst, int i);
void    valid_rgb(char **str, int i);
bool	check_char(char c);
int		check_dup(int i);

// PARSING UTILS 1
void	decimal_value_ceilling(s_data *lst);
void	decimal_value_floor(s_data *lst);
int		get_data(s_data *lst, int *j);
int		found_space(char c);
int		mx(int *j, int i);

// MAP OUTILS 1

int		no_map(char **av, s_data *lst, int count, int j);
void    check_two(s_data *lst, int j);
void    check_one(int j, int count);

// GET NEXT LINE
char    *get_next_line(int fd);

#endif