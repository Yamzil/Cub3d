/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:07:25 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/17 19:00:13 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Get_Next_line/get_next_line.h"
#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <unistd.h>

void    CheckExtension(int ac, char **av)
{
    size_t	len;

    len = ft_strlen(av[1]);
    if (ac == 2)
    {
        if (av[1][len - 1] != 'b' || av[1][len - 2] != 'u' || av[1][len - 3] != 'c' || av[1][len - 4] != '.')
			write(2, "Error in extension , expected '.cub' \n", 39);
    }
}

int	countline(char **av)
{
	int		count;
	char	*map;
	int		fd;

	fd = open(av[1], O_RDONLY, 0777);
	map = get_next_line(fd);
	count = 0;
	while (map)
	{
		map = get_next_line(fd);
		count++;
	}
	return count;
}

char	**get_map(char **av)
{
	char	**full_map;
	int		line;
	int		fd;
	int		i;

	line = countline(av);
	fd = open(av[1], O_RDONLY, 0777);
	full_map = malloc((line + 1) * sizeof(char *));
	if (!full_map)
		return (NULL);
	i = 0;
	while (1) 
	{
		full_map[i] = get_next_line(fd);
		if (full_map[i] == 0)
			break ;
		i++;
	}
	full_map[i] = NULL;
	return (full_map);
}

void	checkduplicatepath(char **av)
{
	char	**map;
	char	tab[4];
	int		i;

	map = get_map(av);
	i = 0;
	ft_memset(tab, 0, sizeof(tab));
	while (map[i])
	{
		if (!ft_strncmp(map[i], "NO", 2)){
			if (tab[0] == 0)
				tab[0] = 1;
			else
				write(2, "Duplicate Path NO\n", 19);
		}
		else if (!ft_strncmp(map[i], "SO", 2)){
			if (tab[1] == 0)
				tab[1] = 1;
			else
				write(2, "Duplicate Path SO\n", 19);
		}
		else if (!ft_strncmp(map[i], "WE", 2)){
			if (tab[2] == 0)
				tab[2] = 1;
			else
				write(2, "Duplicate Path WE\n", 19);
		}
		else if (!ft_strncmp(map[i], "EA", 2)){
			if (tab[3] == 0)
				tab[3] = 1;
			else
				write(2, "Duplicate Path EA\n", 19);
		}
		i++;
	}
}

void	countpath(char **av)
{
	char	**map;
	int		count;
	int		i;

	map = get_map(av);
	count = 0;
	i = 0;
	while (map[i])
	{
		if (!ft_strncmp(map[i], "NO", 2))
			count++;
		else if (ft_strncmp(map[i], "SO", 2))
			count++;
		else if (ft_strncmp(map[i], "WE", 2))
			count++;
		else if (ft_strncmp(map[i], "EA", 2))
			count++;
		i++;
	}
	if (count != 4)
		write(2, "Missing a path\n", 16);
}

void	checkspace(char **av)
{
	char	**map;
	int 	i;

	map = get_map(av);
	i = 0;
	while (map[i])
	{
		if (!ft_strncmp(map[i], "NO", 2)){
			if (map[i][2] != ' ')
				write(2, "No space has been found\n", 25);
		}
		else if (!ft_strncmp(map[i], "SO", 2)){
			if (map[i][2] != ' ')
				write(2, "No space has been found\n", 25);
		}
		else if (!ft_strncmp(map[i], "WE", 2)){
			if (map[i][2] != ' ')
				write(2, "No space has been found\n", 25);
		}
		else if (!ft_strncmp(map[i], "EA", 2)){
			if (map[i][2] != ' ')
				write(2, "No space has been found\n", 25);
		}
		i++;
	}
}

void	check_floor_ceilling_color(char **av)
{
	char	**map;
	int		count;
	int		count_vergule;
	int		i;
	int		j;

	map = get_map(av);
	count_vergule = 0;
	count = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		if (!ft_strncmp(map[i], "F", 1))
			count++;
		else if (!ft_strncmp(map[i], "C", 1))
			count++;
		i++;
	}
	if (count != 2)
		write (2, "Missing Floor or Ceilling\n", 27);
	i = 0;
	while (map[i])
	{
		if (!ft_strncmp(map[i], "F", 1))
		{
			j = 0;
			while(map[i][j])
			{
				if (map[i][j] == ',')
					count_vergule++;
				j++;
			}
			if (count_vergule != 2)
				write(2, "Error in floor arguments\n", 25);
			count_vergule = 0;
		}
		else if (!ft_strncmp(map[i], "C", 1))
		{
			j = 0;
			while(map[i][j])
			{
				if (map[i][j] == ',')
					count_vergule++;
				j++;
			}
			if (count_vergule != 2)
				write(2, "Error in Ceilling arguments\n", 28);
		}
		i++;
	}
}

char	**max_color_for_floor(char **av)
{
	char	**map;
	char	**split;
	int		i;
	map = get_map(av);
	i = 0;
	while (map[i])
	{
		if (!ft_strncmp(map[i], "F", 1))
		{
			map[i] = ft_strtrim(map[i], "\n");
			split = ft_split(map[i], ',');
		}	
		i++;
	}
	return split;
}

char	**max_color_for_ceilling(char **av)
{
	char	**map;
	char	**split;
	int		i;
	map = get_map(av);
	i = 0;
	while (map[i])
	{
		if (!ft_strncmp(map[i], "C", 1))
		{
			map[i] = ft_strtrim(map[i], "\n");
			split = ft_split(map[i], ',');
		}	
		i++;
	}
	return split;
}

void	check_max_rgb(char **av)
{
	char	**floor;
	char	**ceilling;
	int		i;

	floor = max_color_for_floor(av);
	ceilling = max_color_for_ceilling(av);
	i = 0;
	while (floor[i])
	{	
		floor[i] = ft_strtrim(floor[i], "F ");
		if (ft_atoi(floor[i]) < 0 || ft_atoi(floor[i]) > 255)
			write(2, "Rgb color out of bounds\n", 25);
		i++;
	}
	i = 0;
	while (ceilling[i])
	{	
		ceilling[i] = ft_strtrim(ceilling[i], "C ");
		if (ft_atoi(ceilling[i]) < 0 || ft_atoi(ceilling[i]) > 255)
			write(2, "Rgb color out of bounds\n", 25);
		i++;
	}
}

void	check_map(char **av)
{
	char	**full_map;
	char	**map;
	int		i;
	int		j;
	int		fd;

	full_map = get_map(av);
	i = 0;
	map = malloc(10000);
	fd = open(av[1], O_RDONLY, 0777);
	map[i] = get_next_line(fd);
	while (full_map[i])
	{
		j = 0;
		while (full_map[i][j])
		{
			if (full_map[i][j] == '1' || full_map[i][j] == '0' || full_map[i][j] == 'N' || full_map[i][j] == ' ')
			{
				map[i] = get_next_line(fd);
			}
			j++;
		}
		i++;
	}
	for (int k = 0; map[k]; k++)
		printf("%s", map[k]);
}

void	get_data(s_data *lst, char **av)
{
	char	**map;
	int		i;

	map = get_map(av);
	i = 0;
	while (map[i])
	{
		if (!ft_strncmp(map[i], "NO", 2))
			lst->north = map[i];
		else if (!ft_strncmp(map[i], "SO", 2))
			lst->south = map[i];
		else if (!ft_strncmp(map[i], "WE", 2))
			lst->west = map[i];
		else if (!ft_strncmp(map[i], "EA", 2))
			lst->east = map[i];
		else if (!ft_strncmp(map[i], "F", 1))
			lst->color_floor = map[i];
		else if (!ft_strncmp(map[i], "C", 1))
			lst->color_celleing = map[i];
		i++;
	}
}
/* 
int	check_file(){
	int i = 0;
	if (check_path(....&i))
	{
		if (check_colors(.....&i))
		{
			if (check_map(....&i))
			{
				return 
			}
		}
	}
} */

/*
check path
	*/