/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:07:25 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/21 22:36:00 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include <sys/fcntl.h>

void	valid_data(s_data *lst)
{
	lst->north = ft_strtrim(lst->north, "NO \n");
	if (open(lst->north, O_RDONLY) == -1)
		error_msg(3);
	lst->south = ft_strtrim(lst->south, "SO \n");
	if (open(lst->south, O_RDONLY) == -1)
		error_msg(3);
	lst->west = ft_strtrim(lst->west, "WE \n");
	if (open(lst->west, O_RDONLY) == -1)
		error_msg(3);
	lst->east = ft_strtrim(lst->east, "EA \n");
	if (open(lst->east, O_RDONLY) == -1)
		error_msg(3);
}

void	check_map(char **av, s_data *lst, int *j)
{
	check_valid(av, lst, j);
	// valid_map_elements(av, lst, &j);
	// valid_player(av, lst, &j);
	// valid_player_sourrnder(av, lst, &j);// TO DOO
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
			check_map(av, lst, &i);
			get_map(lst, i);
			for (int i = 0; lst->map[i]; i++)
				printf("%s", lst->map[i]);
		}
		return 1;
	}
	return 0;
}
