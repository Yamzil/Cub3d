/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:13:28 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/05 00:02:26 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdbool.h>

bool	check_wall(t_data *data, double x, double y)
{
    int	map_x;
    int	map_y;

    map_y = floor(y / 10) - 1;
    map_x = floor(x / 10) - 1;
    if (data->map[map_y][map_x] != '0' && data->map[map_y][map_x] != 'N'
        && data->map[map_y][map_x] != 'S' && data->map[map_y][map_x] != 'W'
        && data->map[map_y][map_x] != 'E')
        return (true);
    return (false);
}

void	horizental_inter(t_data *data)
{
	double	x_inter;
	double	y_inter;
	double	x_step;
	double	y_step;
	double	next_xinter;
	double	next_yinter;
	double	Hitwallx;
	double	Hitwally;
	double	distance;
	bool	HitWall;

	HitWall =  false;
	Hitwallx = 0.0;
	Hitwally = 0.0;
	y_inter = floor(data->player->py / SQUARE_SIZE) * SQUARE_SIZE;
	if (rayisdown(data))
		y_inter += SQUARE_SIZE;
	x_inter = data->player->px + (data->player->py - y_inter) / tan(data->angle);
	y_step = SQUARE_SIZE;
	if (rayisup(data))
		y_step *= -1;
	x_step = SQUARE_SIZE / tan(data->angle);
	next_yinter = y_inter;
	next_xinter = x_inter;
	if (rayisleft(data) && x_step > 0)
		x_step *= -1;
	if (rayisright(data) && x_step < 0)
		x_step *= -1;
	if (rayisup(data))
		next_yinter--;
	while (next_xinter >= 0 && next_xinter <= WIN_WIDTH && next_yinter >= 0 && next_yinter <= WIN_HEIGHT)
	{
		if (check_wall(data, next_xinter, next_yinter))
		{
			HitWall =  true;
			Hitwallx = next_xinter;
			Hitwally = next_yinter;
			break ;
		}
		else
			next_xinter += x_step;
			next_yinter += y_step;
	}
	if (HitWall)
		distance = sqrt(pow((Hitwallx - data->player->px), 2) + pow(Hitwally - data->player->py, 2));
}

void	vertical_inter(t_data *data)
{
	double	x_inter;
	double	y_inter;
	double	x_step;
	double	y_step;
	double	next_xinter;
	double	next_yinter;
	double	Hitwallx;
	double	Hitwally;
	double	distance;
	bool	HitWall;

	HitWall =  false;
	Hitwallx = 0.0;
	Hitwally = 0.0;
	x_inter = floor(data->player->px / SQUARE_SIZE) * SQUARE_SIZE;
	if (rayisright(data))
		x_inter += SQUARE_SIZE;
	y_inter = data->player->py + (x_inter - data->player->py) * tan(data->angle);
	x_step = SQUARE_SIZE;
	if (rayisleft(data))
		x_step *= -1;
	y_step = SQUARE_SIZE * tan(data->angle);
	next_yinter = y_inter;
	next_xinter = x_inter;
	if (rayisup(data) && y_step > 0)
		y_step *= -1;
	if (rayisdown(data) && y_step < 0)
		y_step *= -1;
	if (rayisleft(data))
		next_xinter--;
	while (next_xinter >= 0 && next_xinter <= WIN_WIDTH && next_yinter >= 0 && next_yinter <= WIN_HEIGHT)
	{
		if (check_wall(data, next_xinter, next_yinter))
		{
			HitWall =  true;
			Hitwallx = next_xinter;
			Hitwally = next_yinter;
			break ;
		}
		else
			next_xinter += x_step;
			next_yinter += y_step;
	}
	if (HitWall)
		distance = sqrt(pow((Hitwallx - data->player->px), 2) + pow(Hitwally - data->player->py, 2));
}
