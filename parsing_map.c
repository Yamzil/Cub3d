/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:07:25 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/16 18:58:21 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Get_Next_line/get_next_line.h"
#include "cub3d.h"
#include <stdbool.h>
#include <stdio.h>

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
		if (!ft_strncmp(map[i], "NO", 2)){
			count++;
		}
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