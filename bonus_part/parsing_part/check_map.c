/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:34:28 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/26 19:31:47 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_last_line(t_data *lst)
{
	int	i;
	int	j;

	i = lst->end - 1;
	while (lst->file[i])
	{
		j = 0;
		while (lst->file[i][j])
		{
			if (lst->file[i][j] != '1')
				map_error(lst, 0);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_valid(t_data *lst)
{
    int	i;
	int	j;

	i = lst->begin + 1;
	
	while (lst->file[i] && !ft_strncmp(lst->file[i], "\n", 2))
		i++;
	while (lst->file[i])
	{
		j = 0;
		while (lst->file[i] && lst->file[i][j])
		{
			check_valid_util(lst, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

int	valid_map_elements(t_data *lst)
{
	char	x;
	int		i;
	int		j;

	i = lst->begin + 1;
	while (lst->file[i] && !ft_strncmp(lst->file[i], "\n", 2))
		i++;
	while (lst->file[i])
	{
		j = 0;
		while (lst->file[i] && lst->file[i][j]) 
		{
			x = lst->file[i][j];
			if (x != '0' && x != '2' && x != '1' && x != 'N' && x != 'S' \
				&& x != 'W' && x != 'E' && x != ' ' && x != '\n')
				map_error(lst, 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	valid_player(t_data *lst)
{
	int	i;

	i = lst->begin + 1;
	while (lst->file[i] && !ft_strncmp(lst->file[i], "\n", 2))
		i++;
	check_player_util(lst, i);
	return (0);
}

int	valid_player_position(t_data *lst)
{
	char	x;
	int		i;
	int		j;

	i = lst->begin + 1;
	while (lst->file[i] && !ft_strncmp(lst->file[i], "\n", 2))
		i++;
	lst->begin = i;
	while (lst->file[i])
	{
		j = 0;
		while (lst->file[i][j])
		{
			x = lst->file[i][j];
			if (x == 'S' || x == 'N' || x == 'W' || x == 'E')
			{
				if (i == lst->begin || i == lst->end - 1 || j == 0
					|| (lst->file[i][j + 1] != '1' && lst->file[i][j + 1] != '0')
					|| (lst->file[i + 1][j] != '0' && lst->file[i + 1][j] != '1')
					|| (lst->file[i - 1][j] != '0' && lst->file[i - 1][j] != '1')
					|| (lst->file[i][j - 1] != '0' && lst->file[i][j - 1] != '1'))
						map_error(lst, 2);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void    check_map( t_data *lst)
{
	check_last_line(lst);
	check_valid(lst);
	valid_map_elements(lst);
	valid_player(lst);
	valid_player_position(lst);
}