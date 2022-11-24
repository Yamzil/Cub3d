/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:25:43 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/24 22:49:40 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    check_valid_util(t_data *lst, int i, int j)
{
	if (lst->file[i][j] == '0')
	{
		if (i < (int)ft_strlen(lst->file[i + 1]) || i < (int)ft_strlen(lst->file[i - 1]))
		{
			if (check_char(lst->file[i][j - 1]))
				map_error(0);
			else if (check_char(lst->file[i][j + 1]))
				map_error(0);
			else if (check_char(lst->file[i - 1][j]))
				map_error(0);
			else if (check_char(lst->file[i + 1][j]))
				map_error(0);
		}
	}
}

void	check_player_util(t_data *lst, int i)
{
	int	player;
	int	j;

	player = 0;
	while (lst->file[i] && !ft_strncmp(lst->file[i], "\n", 2))
		i++;
	while (lst->file[i])
	{
		j = 0;
		while (lst->file[i] && lst->file[i][j])
		{
			if (lst->file[i][j] == 'N' || lst->file[i][j] == 'S' || lst->file[i][j] == 'W' || lst->file[i][j] == 'E')
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
		map_error(2);	
}

void	checking_player_sourrender(t_data *lst, int i)
{
	int	j;

	j = 0;
	while (lst->file[i][j])
	{
		if (lst->file[i][j] == 'N' || lst->file[i][j] == 'S' 
			|| lst->file[i][j] == 'W' || lst->file[i][j] == 'E')
		{
			if ((lst->file[i][j + 1] != '0'
				|| lst->file[i][j - 1] != '0') && (lst->file[i][j + 1] != '1'
				|| lst->file[i][j - 1] != '1') && (lst->file[i + 1][j] != '0'
				|| lst->file[i - 1][j] != '0') && (lst->file[i - 1][j] != '1'
				|| lst->file[i + 1][j] != '1'))
				map_error(2);
		}
		j++;
	}
}