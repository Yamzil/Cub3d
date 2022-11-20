/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceilling_floor_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:30:41 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/20 18:31:23 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valid_celling_floor(s_data *lst)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while(lst->file[i])
	{
		if (!ft_strncmp(lst->file[i], "F", 1))
			count++;
		else if (!ft_strncmp(lst->file[i], "C", 1))
			count++;
		i++;
	}
	if (count != 2)
	{
		write (2, "Missing|dupliacte floor or ceilling\n", 36);
		exit (1);
	}
	return 0;
}

char	**get_rgb_for_floor(s_data *lst)
{
	char	**split;
	int		i;

	i = 0;
	if (!check_floor(lst))
	{
		while (lst->file[i])
		{
			if (!ft_strncmp(lst->file[i], "F", 1))
			{
				lst->file[i] = ft_strtrim(lst->file[i], "\n");
				split = ft_split(lst->file[i], ',');
			}
			i++;
		}
		return split;
	}
	return NULL;
}

char	**get_rgb_for_ceilling(s_data *lst)
{
	char	**split;
	int		i;

	i = 0;
	if (!check_ceilling(lst))
	{
		while (lst->file[i])
		{
			if (!ft_strncmp(lst->file[i], "C", 1))
			{
				lst->file[i] = ft_strtrim(lst->file[i], "\n");
				split = ft_split(lst->file[i], ',');
			}
			i++;
		}
		return split;
	}
	return NULL;
}
