/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:07:25 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/21 20:16:12 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include <sys/fcntl.h>

void	valid_data(s_data *lst)
{
	lst->north = ft_strtrim(lst->north, "NO \n");
	if (open(lst->north, O_RDONLY) == -1)
	{
		write(2, "Path cannot opened\n", 20);
		exit (1);
	}
	lst->south = ft_strtrim(lst->south, "SO \n");
	if (open(lst->south, O_RDONLY) == -1)
	{
		write(2, "Path cannot opened\n", 20);
		exit (1);
	}
	lst->west = ft_strtrim(lst->west, "WE \n");
	if (open(lst->west, O_RDONLY) == -1)
	{
		write(2, "Path cannot opened\n", 20);
		exit (1);
	}
	lst->east = ft_strtrim(lst->east, "EA \n");
	if (open(lst->east, O_RDONLY) == -1)
	{
		write(2, "Path cannot opened\n", 20);
		exit (1);
	}
}

int	check_map(char **av, s_data *lst, int j)
{
	if (check_valid(av, lst, j))
	{
		puts("check valid");
		return 1;
	}
	else if (valid_map_elements(av, lst, j))
	{
		puts("2");
		return (1);
	}
	else if (valid_player(av, lst, j))
	{
		puts("3");
		return (1);
	}
	else if (valid_player_sourrnder(av, lst, j)) // TODO
	{
		puts("4");
		return (1);
	}
	return 0;
}

int	check_file(char **av, s_data *lst)
{
	int	i;

	i = 0;
	if (!count_duplicate_path(lst) && !checkspace(lst))
	{
		if (get_data(lst, &i))
		{
			valid_data(lst);
			decimal_value_floor(lst);
			decimal_value_ceilling(lst);
			if (check_map(av, lst, i))
			{
				write(2, "Map Error\n", 11);
				exit (1);
			}
		}
		return 1;
	}
	return 1;
}
