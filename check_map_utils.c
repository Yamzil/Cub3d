/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:37:05 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/24 15:56:17 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_char(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'W' && c != 'E' && c != 'S')
		return true;
	return false;
}

int	valid_map(t_data *lst, int j)
{
	if (j < lst->end)
	{
		if (!ft_strncmp(lst->file[j], "C ", 2) 
			|| !ft_strncmp(lst->file[j], "F ", 2))
			j++;
	}
	else
		map_error(3);
	return j;
}

int	map_execite(t_data *lst)
{
	int	i;

	i = 0;
	while(lst->file[i])
	{
		if (lst->file[i] && ft_strncmp(lst->file[i], "\n", 2))
		{
			i++;
			if (lst->file[i] == 0)
				map_error(3);
		}
		else if (i == lst->end) // lst->end = null
			map_error(3);
		i++;
	}
	return (0);
}
