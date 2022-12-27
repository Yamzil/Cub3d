/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <mjlem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:25:08 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/27 23:10:48 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**color_number_floor(t_data *lst, char **color)
{
	int	i;

	i = 0;
	while (color[i])
		i++;
	if (i != 3)
	{
		free_paths(lst);
		free_tab(color);
		parsing_error(lst, 3);
	}
	return (color);
}

char	**color_number_ceilling(t_data *lst, char **color)
{
	int	i;

	i = 0;
	while (color[i])
		i++;
	if (i != 3)
	{
		free_paths(lst);
		free_tab(color);
		parsing_error(lst, 4);
	}
	return (color);
}

int	check_storing_file_data(t_data *lst)
{
	parsing_path(lst);
	parsing_floor(lst);
	parsing_ceilling(lst);
	storing_colors_ceilling(lst);
	storing_colors_floor(lst);
	return (0);
}

void	check_map(t_data *lst)
{
	check_last_line(lst);
	check_valid(lst);
	valid_map_elements(lst);
	valid_player(lst);
	valid_player_position(lst);
}
