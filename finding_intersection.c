/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_intersection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:23:20 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/05 23:50:47 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    horizontal(t_data *data)
{

	if (rayisup(data))
		data->rays->ay_horizontal = floor(data->player->py / TILE_SIZE) \
		* TILE_SIZE;
	else if (rayisdown(data))
		data->rays->ay_horizontal = floor(data->player->py / TILE_SIZE) \
		* TILE_SIZE + TILE_SIZE;
	data->rays->ax_horizontal = data->player->px + (data->player->py - \
	data->rays->ay_horizontal /  tan(data->angle));
	if (rayisup(data))
		data->rays->step_horizentaly -= TILE_SIZE;
	else if (rayisdown(data))
		data->rays->step_horizentaly = TILE_SIZE;
	data->rays->step_horizentalx= TILE_SIZE / tan(data->angle);
}

void	vertical(t_data *data)
{
	if (rayisright(data))
		data->rays->ax_vertical = floor(data->player->px / TILE_SIZE) \
		* TILE_SIZE + TILE_SIZE;
	else if (rayisleft(data))
		data->rays->ax_vertical = floor(data->player->py /  TILE_SIZE) \
		* TILE_SIZE;
	if (rayisright(data))
		data->rays->step_verticalx = TILE_SIZE;
	else if (rayisleft(data))
		data->rays->step_verticalx -= TILE_SIZE;
	data->rays->step_verticaly = TILE_SIZE * tan(data->angle);
}

void	hit_wall_vertical(t_data *data)
{
	while (1)
	{
		if (check_wall(data, data->rays->step_verticalx, \
			data->rays->step_verticaly))
		{
			data->rays->hit_wall_xvertical = data->rays->step_verticalx;
			data->rays->hit_wall_yvertical = data->rays->step_verticaly;
		}
		else 
		{
			data->rays->step_verticalx += data->rays->step_verticalx;
			data->rays->step_verticaly += data->rays->step_verticaly;
		}
	}
}

void	hit_wall_horizental(t_data *data)
{
	while (1)
	{
		if (check_wall(data, data->rays->step_horizentalx, \
			data->rays->step_horizentaly))
		{
			data->rays->hit_wall_xhorizental = data->rays->step_horizentalx;
			data->rays->hit_wall_yhorizental = data->rays->step_horizentaly;
		}
		else 
		{
			data->rays->step_horizentalx += data->rays->step_horizentalx;
			data->rays->step_horizentaly += data->rays->step_horizentaly;
		}
	}
}

