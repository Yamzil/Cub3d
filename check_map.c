/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:34:28 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/24 15:37:56 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_valid(t_data *lst)
{
    int	i;
	int	j;

	i = lst->begin;
	if (!map_execite(lst))
	{
		while (lst->file[i])
		{
			j = 0;
			while (lst->file[i] && !ft_strncmp(lst->file[i], "\n", 2))
				i++;
			while (lst->file[i] && lst->file[i][j])
			{
				check_valid_util(lst, i, j);
				j++;
			}
			i++;
		}
	}
	return (0);
}

int	valid_map_elements(t_data *lst)
{
	int	i;
	int	j;

	i = 0;
	if (!map_execite(lst))
	{
		while (lst->file[i])
		{
			j = 0;
			while (lst->file[i] && !ft_strncmp(lst->file[i], "\n", 2))
				i++;
			while (lst->file[i] && lst->file[i][j]) 
			{
				if (lst->file[i][j] != '0' && lst->file[i][j] != '1' 
					&& lst->file[i][j] != 'N' && lst->file[i][j] != 'S' 
					&& lst->file[i][j] != 'W' && lst->file[i][j] != 'E' 
					&& lst->file[i][j] != ' ' && lst->file[i][j] != '\n')
					map_error(1);
				j++;
			}
			i++;
		}
	}
	return (0);
}

int	valid_player(t_data *lst)
{
	int	i;

	i = 0;
	if (!map_execite(lst))
	{
		while (lst->file[i])
		{
			while (lst->file[i] && !ft_strncmp(lst->file[i], "\n", 2))
				i++;
			check_player_util(lst, i);
			i++;
		}
	}
	return (0);
}

int	valid_player_sourrnder(t_data *lst)
{
	int	i;
	int	j;

	i = 0;
	if (!map_execite(lst))
	{
		while (lst->file[i])
		{
			j = 0;
			while(lst->file[j] && !ft_strncmp(lst->file[i], "\n", 2))
				i++;
			checking_player_sourrender(lst, i);	
			i++;
		}
	}
	return (0);
}

void    check_map( t_data *lst)
{
	check_valid(lst);
	valid_map_elements(lst);
	valid_player(lst);
	valid_player_sourrnder(lst);
}