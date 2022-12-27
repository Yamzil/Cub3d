/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <mjlem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:34:28 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/27 23:10:48 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
			if (lst->file[i][j] != ' ' && lst->file[i][j] != '1')
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
		if (lst->file[i][0] == '\n')
			map_error(lst, 0);
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
			if (x != '0' && x != '1' && x != 'N' && x != 'S'
				&& x != 'W' && x != 'E'
				&& x != ' ' && x != '\n')
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

void	valid_player_position(t_data *l)
{
	int		i;
	int		j;

	i = l->begin + 1;
	while (l->file[i] && !ft_strncmp(l->file[i], "\n", 2))
		i++;
	l->begin = i;
	while (l->file[i])
	{
		j = -1;
		while (l->file[i][++j])
		{
			if (l->file[i][j] == 'S' || l->file[i][j] == 'N'
				|| l->file[i][j] == 'W' || l->file[i][j] == 'E')
			{
				if (i == l->begin || i == l->end - 1 || j == 0
					|| (l->file[i][j + 1] != '1' && l->file[i][j + 1] != '0')
					|| (l->file[i + 1][j] != '0' && l->file[i + 1][j] != '1')
					|| (l->file[i - 1][j] != '0' && l->file[i - 1][j] != '1')
					|| (l->file[i][j - 1] != '0' && l->file[i][j - 1] != '1'))
					map_error(l, 2);
			}
		}
		i++;
	}
}
