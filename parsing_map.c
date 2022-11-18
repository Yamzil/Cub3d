/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:07:25 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/18 19:47:06 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Get_Next_line/get_next_line.h"
#include "cub3d.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <unistd.h>

void    check_extension(int ac, char **av)
{
    size_t	len;

    len = ft_strlen(av[1]);
    if (ac == 2)
    {
        if (av[1][len - 1] != 'b' || av[1][len - 2] != 'u' 
			|| av[1][len - 3] != 'c' || av[1][len - 4] != '.')
			write(2, "Error in extension \n", 21);
    }
}

int	get_data(s_data *lst)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	if (check_max_rgb(lst)) // maybe segfault here....
	{
		while (lst->file[i])
		{
			if (!ft_strncmp(lst->file[i], "NO", 2))
			{
				lst->north = lst->file[i];
				if (j < i)
					j = i;
			}
			else if (!ft_strncmp(lst->file[i], "SO", 2))
			{
				lst->south = lst->file[i];
				if (j < i)
					j = i;
			}
			else if (!ft_strncmp(lst->file[i], "WE", 2))
			{
				lst->west = lst->file[i];
				if (j < i)
					j = i;
			}
			else if (!ft_strncmp(lst->file[i], "EA", 2))
			{
				lst->east = lst->file[i];
				if (i < j)
					j = i;
			}
			else if (!ft_strncmp(lst->file[i], "F", 1))
			{
				lst->color_floor = lst->file[i];
				if (j < i)
					j = i;
			}
			else if (!ft_strncmp(lst->file[i], "C", 1))
			{
				lst->color_celleing = lst->file[i];
				if (j < i)
					j = i;
			}
			i++;
		}
		printf("%d", j);
		return j;
	}
	return 0;
}

bool	check_char(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'W' && c != 'E' && c != 'S')
		return true;
	return false;
}

int	check_map(s_data *lst)
{
	int	i;
	int	j;
	int player_nb;
	
	player_nb = 0;
	i = 0;
	while(lst->map[i])
	{
		j = 0;
		while(lst->map[i][j])
		{
			if (lst->map[i][j] == 0)
			{
				if(check_char(lst->map[i][j - 1]))
					return (1);
				else if (check_char(lst->map[i][j + 1]))
					return (1);
				else if (check_char(lst->map[i - 1][j]))
					return (1);
				else if (check_char(lst->map[i + 1][j - 1]))
					return (1);
			}
			if (lst->map[i][j] == 'N' || lst->map[i][j] == 'S' 
				|| lst->map[i][j] == 'E'|| lst->map[i][j] == 'W')
				player_nb++;
			if (player_nb > 1)
				return (1);
		}
	}
	return 0;
}

int	check_file(s_data *lst, char **av)
{
	(void) av;
	int i;

	i = 0;
	if (!count_duplicate_path(lst) && !checkspace(lst))
	{
		if (get_data(lst))
		{
			// if (check_map(lst))
			// 	write(2, "Map is not closed by wall\n", 26);
		}
		return 1;
	}
	return 1;
}
