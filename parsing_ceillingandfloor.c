/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ceillingandfloor.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:21:52 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/19 20:32:09 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>

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

int check_floor(s_data *lst)
{
	int	i;

	i = 0;
	if (!valid_celling_floor(lst))
	{
		while(lst->file[i])
		{
			if (!ft_strncmp(lst->file[i], "F", 1))
				check_ver(lst, i);
			i++;
		}
	}
	return (0);
}

int check_ceilling(s_data *lst)
{
	int	i;

	i = 0;
	if (!valid_celling_floor(lst))
	{
		while(lst->file[i])
		{
			if (!ft_strncmp(lst->file[i], "C", 1))
				check_ver(lst, i);
			i++;
		}
	}
	return (0);
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

int	check_max_rgb_floor(s_data *lst)
{
	char	**floor;
	int		i;

	floor = get_rgb_for_floor(lst);
	i = 0;
	while (floor[i] && floor != NULL)
	{	
		floor[i] = ft_strtrim(floor[i], "F ");
		valid_rgb(floor, i);
		i++;
	}
	return (0);
}

int	check_max_rgb_ceilling(s_data *lst)
{
	char	**ceilling;
	int		i;

	ceilling = get_rgb_for_ceilling(lst);
	i = 0;
	while (ceilling[i] && ceilling != NULL)
	{	
		ceilling[i] = ft_strtrim(ceilling[i], "C ");
		valid_rgb(ceilling, i);
		i++;
	}
	return (0);
}
