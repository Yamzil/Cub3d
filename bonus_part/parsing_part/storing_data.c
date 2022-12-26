/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storing_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:34:16 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/21 21:04:07 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	storing_path(t_data *lst, int *j)
{
	int	i;

	i = 0;
	while (lst->file[i])
	{
		if (!ft_strncmp(lst->file[i], "NO", 2) &&  mx(j, i))
			lst->north = ft_strtrim(lst->file[i], "NO \n");
		else if (!ft_strncmp(lst->file[i], "SO", 2) &&  mx(j, i))
			lst->south = ft_strtrim(lst->file[i], "SO \n");
		else if (!ft_strncmp(lst->file[i], "WE", 2) &&  mx(j, i))
			lst->west = ft_strtrim(lst->file[i], "WE \n");
		else if (!ft_strncmp(lst->file[i], "EA", 2) &&  mx(j, i))
			lst->east = ft_strtrim(lst->file[i], "EA \n");
		i++;
	}
	if (open(lst->north, O_RDWR) == -1)
		parsing_error(2);
	else if (open(lst->south, O_RDWR) == -1)
		parsing_error(2);
	else if (open(lst->west, O_RDWR) == -1)
		parsing_error(2);
	else if (open(lst->east, O_RDWR) == -1)
		parsing_error(2);
	lst->begin = *j;
	return (i);
}

void	utils_storing_color_floor(t_data *lst, char **color, int i)
{
	if (ft_atoi(color[i]) < 0 || ft_atoi(color[i]) > 255)
		parsing_error(3);
	else
	{
		lst->floor = (ft_atoi(color[0]) * 256 * 256) + 
		(ft_atoi(color[1]) * 256) + ft_atoi(color[2]);
	}
}

void	utils_storing_color_ceilling(t_data *lst, char **color, int i) 
{
	if (ft_atoi(color[i]) < 0 || ft_atoi(color[i]) > 255)
		parsing_error(4);
	else
	{
		lst->ceilling = (ft_atoi(color[0]) * 256 * 256) + 
		(ft_atoi(color[1]) * 256) + ft_atoi(color[2]);
	}
}

int	storing_colors_floor(t_data *lst)
{
	char	**color;
	int		i;
	int		j;

	i = 0;
	color = getting_color_floor(lst);
	while (color[i])
	{
		j = 0;
		while (color[i][j])
		{
			if (ft_isdigit(color[i][j]))
				utils_storing_color_floor(lst, color, i);
			else
				parsing_error(3);
			j++;
		}
		i++;
	}
	return (0);
}

int	storing_colors_ceilling(t_data *lst)
{
	char	**color;
	int		i;
	int		j;

	i = 0;
	color = getting_color_ceilling(lst);
	while (color[i])
	{
		j = 0;
		while (color[i][j])
		{
			if (ft_isdigit(color[i][j]))
				utils_storing_color_ceilling(lst, color, i);
			else
				parsing_error(4);
			j++;
		}
		i++;
	}
	return (0);
}
