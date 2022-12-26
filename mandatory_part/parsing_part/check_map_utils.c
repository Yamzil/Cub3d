/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:37:05 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/24 23:43:17 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

bool	check_char(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'W' && c != 'E' && c != 'S')
		return true;
	return false;
}

void    check_valid_util(t_data *lst, int i, int j)
{
	if (lst->file[i][j] == '0')
	{
		if (lst->file[i] || i < (int)ft_strlen(lst->file[i + 1])
			|| i < (int)ft_strlen(lst->file[i - 1]))
		{
			if (check_char(lst->file[i][j - 1]))
				map_error(lst, 0);
			else if (check_char(lst->file[i][j + 1]))
				map_error(lst, 0);
			else if (check_char(lst->file[i - 1][j]))
				map_error(lst, 0);
			else if (lst->file[i + 1] && check_char(lst->file[i + 1][j]))
				map_error(lst, 0);
		}
	}
}

void	check_player_util(t_data *lst, int i)
{
	int	player;
	int	j;

	player = 0;
	while (lst->file[i])
	{
		j = 0;
		while (lst->file[i] && lst->file[i][j])
		{
			if (lst->file[i][j] == 'N' || lst->file[i][j] == 'S'
				|| lst->file[i][j] == 'W' || lst->file[i][j] == 'E')
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
		map_error(lst, 2);
}