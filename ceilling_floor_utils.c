/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceilling_floor_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:30:41 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/21 13:05:21 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valid_floor(s_data *lst)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while(lst->file[i])
	{
		if (!ft_strncmp(lst->file[i], "F", 1))
			count++;
		i++;
	}
	if (count != 1)
	{
		write (2, "Missing or dupliacte floor\n", 28);
		exit (1);
	}
	return 0;
}

int	valid_celling(s_data *lst)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while(lst->file[i])
	{
	
		if (!ft_strncmp(lst->file[i], "C", 1))
			count++;
		i++;
	}
	if (count != 1)
	{
		write (2, "Missing or dupliacte ceilling\n", 29);
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
			else
				return (NULL);
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
			else
				return NULL;
			i++;
		}
		return split;
	}
	return NULL;
}
