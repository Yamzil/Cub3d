/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:24:07 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/21 15:41:01 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int mx(int *j, int i)
{
	if(*j < i)
		*j = i;
	return 1;
}

int	get_data(s_data *lst, int *j)
{
	int	i;

	i = 0;
	if (!check_max_rgb_ceilling(lst) && !check_max_rgb_floor(lst))
	{
		while (lst->file[i])
		{
			if (!ft_strncmp(lst->file[i], "NO", 2))
				lst->north = lst->file[i];
			else if (!ft_strncmp(lst->file[i], "SO", 2) && mx(j, i))
				lst->south = lst->file[i];
			else if (!ft_strncmp(lst->file[i], "WE", 2) && mx(j, i))
				lst->west = lst->file[i];
			else if (!ft_strncmp(lst->file[i], "EA", 2) && mx(j, i))
				lst->east = lst->file[i];
			else if (!ft_strncmp(lst->file[i], "F", 1) && mx(j, i))
				lst->color_floor = lst->file[i];
			else if (!ft_strncmp(lst->file[i], "C", 1) && mx(j, i))
				lst->color_celleing = lst->file[i];
			i++;
		}
		return 1;
	}
	return 0;
}

void	decimal_value_floor(s_data *lst)
{
	char	**rgb;
	int		decimal;

	rgb = get_rgb_for_floor(lst);
	if (rgb)
	{
		rgb[0] = ft_strtrim(rgb[0], "F ");
		decimal = (ft_atoi(rgb[0]) * 256 * 256) + (ft_atoi(rgb[1]) * 256)
		+ ft_atoi(rgb[2]);
		lst->floor = decimal;
	}
}

void	decimal_value_ceilling(s_data *lst)
{
	char	**rgb;
	int		decimal;

	rgb = get_rgb_for_ceilling(lst);
	if (rgb)
	{
		rgb[0] = ft_strtrim(rgb[0], "C ");
		decimal = (ft_atoi(rgb[0]) * 256 * 256) + (ft_atoi(rgb[1]) * 256)
		+ ft_atoi(rgb[2]);
		lst->ceilling = decimal;
	}
}