/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:07:25 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/19 20:40:10 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	valid_data(s_data *lst)
{
	lst->north = ft_strtrim(lst->north, "NO ");
	if (open(lst->north, O_RDONLY, 0777) == -1)
	{
		write(2, "Path cannot opened\n", 20);
		exit (1);
	}
	lst->south = ft_strtrim(lst->south, "SO ");
	if (open(lst->south, O_RDONLY, 0777) == -1)
	{
		write(2, "Path cannot opened\n", 20);
		exit (1);
	}
	lst->west = ft_strtrim(lst->west, "WE ");
	if (open(lst->west, O_RDONLY, 0777) == -1)
	{
		write(2, "Path cannot opened\n", 20);
		exit (1);
	}
	lst->east = ft_strtrim(lst->east, "EA ");
	if (open(lst->east, O_RDONLY, 0777) == -1)
	{
		write(2, "Path cannot opened\n", 20);
		exit (1);
	}
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
		if (get_data(lst, i))
		{
			// valid_data(lst);
			// if (check_map(lst))
			// 	write(2, "Map is not closed by wall\n", 26);
		}
		return 1;
	}
	return 1;
}
