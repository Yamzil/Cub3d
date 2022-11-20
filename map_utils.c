/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:53:51 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/20 17:43:25 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Get_Next_line/get_next_line.h"
#include "cub3d.h"

int	check_valid(s_data *lst)
{
    int i;
    int j;

    i = 0;
    while (lst->map[i])
    {
        j = 0;
        while (lst->map[i][j])
        {
            if (lst->map[i][j] == '0')
            {
				if (j < (int)ft_strlen(lst->map[i + 1]) || j < (int)ft_strlen(lst->map[i - 1]))
				{
					if (check_char(lst->map[i][j - 1]))
						return (1);
					else if (check_char(lst->map[i][j + 1]))
						return (1);
					else if (check_char(lst->map[i - 1][j]))
						return (1);
					else if (check_char(lst->map[i + 1][j]))
						return (1);
				}
				else
					return (1);
            }
            j++;
        }
        i++;
    }
    return (0);
}

int	valid_map_elements(s_data *lst)
{
	int	i;
	int	j;

	i = 0;
	while (lst->map[i])
	{
		j = 0;
		while (lst->map[i][j]) 
		{
			if (lst->map[i][j] != '0' && lst->map[i][j] != '1' 
				&& lst->map[i][j] != 'N' && lst->map[i][j] != 'S' 
				&& lst->map[i][j] != 'W' && lst->map[i][j] != 'E' 
				&& lst->map[i][j] != ' ' && lst->map[i][j] != '\n')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	valid_player(s_data *lst)
{
	int	player;
	int	i;
	int	j;

	player = 0;
	i = 0;
	while (lst->map[i])
	{
		j = 0;
		while (lst->map[i][j])
		{
			if (lst->map[i][j] == 'N' || lst->map[i][j] == 'S' 
				|| lst->map[i][j] == 'W' || lst->map[i][j] == 'E')
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
		return (1);
	return (0);
}

int	valid_player_sourrnder(s_data *lst)
{
	int	i;
	int	j;

	i = 0;
	while (lst->map[i])
	{
		j = 0;
		while (lst->map[i][j])
		{
			if (lst->map[i][j] == 'N' || lst->map[i][j] == 'S' || lst->map[i][j] == 'W' || lst->map[i][j] == 'E')
			{
				if ((lst->map[i][j + 1] != '0' || lst->map[i][j - 1] != '0') && (lst->map[i][j + 1] != '1' || lst->map[i][j - 1] != '1') && (lst->map[i + 1][j] != '0' || lst->map[i - 1][j] != '0') && (lst->map[i - 1][j] != '1' || lst->map[i + 1][j] != '1'))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}