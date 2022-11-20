/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:07:25 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/20 17:05:02 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	valid_data(s_data *lst)
{
	lst->north = ft_strtrim(lst->north, "NO ");
	// if (open(lst->north, O_RDONLY, 0777) == -1)
	// {
	// 	write(2, "Path cannot opened\n", 20);
	// 	exit (1);
	// }
	lst->south = ft_strtrim(lst->south, "SO ");
	// if (open(lst->south, O_RDONLY, 0777) == -1)
	// {
	// 	write(2, "Path cannot opened\n", 20);
	// 	exit (1);
	// }
	lst->west = ft_strtrim(lst->west, "WE ");
	// if (open(lst->west, O_RDONLY, 0777) == -1)
	// {
	// 	write(2, "Path cannot opened\n", 20);
	// 	exit (1);
	// }
	lst->east = ft_strtrim(lst->east, "EA ");
	// if (open(lst->east, O_RDONLY, 0777) == -1)
	// {
	// 	write(2, "Path cannot opened\n", 20);
	// 	exit (1);
	// }
}

int	check_map(s_data *lst)
{
	if (check_valid(lst))
	{
		puts("1");
		return 1;
	}
	else if (valid_map_elements(lst))
	{
		puts("2");
		return (1);
	}
	else if (valid_player(lst))
	{
		puts("3");
		return (1);
	}
	else if (valid_player_sourrnder(lst))
	{
		puts("4");
		return (1);
	}
	return 0;
}

int	check_file(s_data *lst)
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
			get_map(lst, i + 2);
			if (check_map(lst))
			{
				write(2, "Map Error\n", 11);
				exit (1);
			}
		}
		return 1;
	}
	return 1;
}
