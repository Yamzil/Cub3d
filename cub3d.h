/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:58:48 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/25 18:09:14 by yamzil           ###   ########.fr       */
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
#include "Get_Next_line/get_next_line.h"

typedef struct s_data{
	char	**file;
	char	**map;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor;
	char	*ceilling;
	int		begin;
	int		end;
}t_data;

// LIBFT
int     ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
void	*ft_memset(void *b, int c, size_t len);
char	**ft_split(char const *s, char c);
void	ft_putendl_fd(char *s, int fd);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *s1);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
char	*ft_itoa(int n);

// AllOCATE FILE
char	**get_file(t_data *lst,char **av);
void	countline(t_data *lst, char **av);

// MAIN
void	messages_error(int i);
void	error_msg(int i);

// GET NEXT LINE
char    *get_next_line(int fd);

// PARSING FILE
char	**getting_color_ceilling(t_data *lst);
char	**getting_color_floor(t_data *lst);
int		parsing_ceilling(t_data *lst);
int		parsing_floor(t_data *lst);
int		parsing_path(t_data *lst);

// PARSING ERROR
void    parsing_error(int i);
void    map_error(int i);

// PARSING UTILS
int		checking_color_ceilling(t_data *lst);
int		checking_color_floor(t_data *lst);
void	check_ver(t_data *lst, int i);
int		mx(int *j, int i);
int		check_dup(int i);

// STORING DATA
int		storing_colors_ceilling(t_data *lst);
int		storing_path(t_data *lst, int *j);
int		storing_colors_floor(t_data *lst);

// CHECK FILE
int		check_storing_file_data(t_data *lst);

// CHECK MAP
int		valid_player_position(t_data *lst);
int		valid_map_elements(t_data *lst);
int		valid_player(t_data *lst);
int		check_valid(t_data *lst);
void    check_map(t_data *lst);

// CHECK MAP UTILS
void	checking_player_position(t_data *lst, int i);
void    check_valid_util(t_data *lst, int i, int j);
void	check_player_util(t_data *lst, int i);
bool	check_char(char c);
#endif