/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <mjlem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:03:41 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/27 23:07:16 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

#include "../cub3d_bonus.h"

int	dupli(t_data *lst, int i)
{
	static int	flag[4] = {};

	if (flag[i])
		parsing_error(lst, 0);
	flag[i] = 1;
	return (1);
}

int	mx(int *j, int i)
{
	if (*j < i)
		*j = i;
	return (1);
}

void	check_ver(t_data *lst, int i)
{
	int	count;
	int	j;

	j = 0;
	count = 0;
	while (lst->file[i][j])
	{
		if (lst->file[i][j] == ',')
			count++;
		j++;
	}
	if (count != 2)
		parsing_error(lst, 3);
}

int	checking_color_floor(t_data *lst)
{
	int	i;

	i = 0;
	if (!parsing_floor(lst))
	{
		while (lst->file[i])
		{
			if (ft_strchr(lst->file[i], 'F'))
				check_ver(lst, i);
			i++;
		}
	}
	return (0);
}

int	checking_color_ceilling(t_data *lst)
{
	int	i;

	i = 0;
	if (!parsing_floor(lst))
	{
		while (lst->file[i])
		{
			if (ft_strchr(lst->file[i], 'C'))
				check_ver(lst, i);
			i++;
		}
	}
	return (0);
}
