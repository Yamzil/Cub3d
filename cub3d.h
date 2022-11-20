/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:58:48 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/20 09:52:08 by yamzil           ###   ########.fr       */
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

//PARSING
bool	check_char(char c);
void	decimal_value_floor(s_data *lst);
void	decimal_value_ceilling(s_data *lst);
char	**get_rgb_for_ceilling(s_data *lst);
char	**get_rgb_for_floor(s_data *lst);
int		check_max_rgb_floor(s_data *lst);
int		check_max_rgb_ceilling(s_data *lst);
void	check_extension(int ac, char **av);
int		check_file(s_data *lst, char **av);
char	**get_file(s_data *lst,char **av);
int		checkspace(s_data *lst);
int		count_duplicate_path(s_data *lst);
void	parsing_map(char **av);
char	**get_map(s_data *lst, int j);
int		check_map(s_data *lst);
int		get_data(s_data *lst, int *j);
int		found_space(char c);
int		check_dup(int i);
int		check_floor(s_data *lst);
int		check_ceilling(s_data *lst);
int		valid_celling_floor(s_data *lst);
void	check_ver(s_data *lst, int i);
void    valid_rgb(char **str, int i);

// GET NEXT LINE
char    *get_next_line(int fd);

#endif