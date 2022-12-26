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

int	open_door(t_data *data)
{
	if (fabs(data->player->px - data->info->my_door->x) <= 4 && fabs(data->info->my_door->y - data->player->py) <= 4)
		return 6;	
	if (fabs(data->player->px - data->info->my_door->x) <= 6 && fabs(data->info->my_door->y - data->player->py) <= 6)
		return 5;		
	if (fabs(data->player->px - data->info->my_door->x) <= 8 && fabs(data->info->my_door->y - data->player->py) <= 8)
		return 4;		
	if (fabs(data->player->px - data->info->my_door->x) <= 10 && fabs(data->info->my_door->y - data->player->py) <= 10)
		return 3;		
	if (fabs(data->player->px - data->info->my_door->x) <= 12 && fabs(data->info->my_door->y - data->player->py) <= 12)
		return 2;		
	if (fabs(data->player->px - data->info->my_door->x) <= 14 && fabs(data->info->my_door->y - data->player->py) <= 14)
		return 1;
	return 0;
}