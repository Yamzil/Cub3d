/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceilling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:26:52 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/21 12:59:14 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_floor(s_data *lst)
{
	int	i;

	i = 0;
	if (!valid_floor(lst))
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
	if (!valid_celling(lst))
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

int	check_max_rgb_floor(s_data *lst)
{
	char	**floor;
	int		i;

	floor = get_rgb_for_floor(lst);
	i = 0;
	if (floor)
	{
		while (floor[i])
		{	
			floor[i] = ft_strtrim(floor[i], "F ");
			valid_rgb(floor, i);
			i++;
		}
	}
	return (0);
}

int	check_max_rgb_ceilling(s_data *lst)
{
	char	**ceilling;
	int		i;

	ceilling = get_rgb_for_ceilling(lst);
	i = 0;
	if (ceilling)
	{
		while (ceilling[i])
		{
			ceilling[i] = ft_strtrim(ceilling[i], "C ");
			valid_rgb(ceilling, i);
			i++;
		}
	}
	return (0);
}
