/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:58:48 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/17 15:59:57 by yamzil           ###   ########.fr       */
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

// LIBFT
int     ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_strtrim(char const *s1, char const *set);
void	*ft_memset(void *b, int c, size_t len);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);

//PARSING
void	check_floor_ceilling_color(char **av);
char	**max_color_for_ceilling(char **av);
char    **max_color_for_floor(char **av);
void	checkduplicatepath(char **av);
void	check_max_rgb(char **av);
void	checkspace(char **av);
void	countpath(char **av);
int		countline(char **av);
char	**get_map(char **av);

// GET NEXT LINE
char    *get_next_line(int fd);

#endif