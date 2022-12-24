/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:10:33 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/24 15:53:03 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_door	*ft_newlst(double x, double y, int distance)
{
	t_door	*doors;

	doors = malloc(sizeof(t_door));
	if (!doors)
		return (NULL);
	doors->x = x;
	doors->y = y;
	doors->distance = distance;
	doors->next = NULL;
	return (doors);
}

void	ft_lstadd_front(t_door **lst, t_door *new)
{
	new->next = *lst;
	*lst = new;
}

void	open_door(t_data *data)
{
	int	half_rays = data->rays / 2;
	data->hit_door = '.';
	
	if (data->info->doors && data[half_rays].hit_door == '2')
	{
		data->map[data->open_y][data->open_x] = '0';
	}
}