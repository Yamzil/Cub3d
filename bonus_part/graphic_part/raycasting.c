/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:13:28 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/24 16:05:15 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	texture1(t_data *data, t_cast *info, double y1)
{
	int		distance_top;
    double  xofset;
    double  yofset;
	double	y;

	y = y1;
	xofset = 0.0;
    if (info->horizontal_inter)
		xofset = ((info->my_doors->x - ((int)(info->my_doors->x / TILE_SIZE) * TILE_SIZE)) * data->arr[4].width) / TILE_SIZE;
	else if (info->vertical_inter)
		xofset = ((info->my_doors->y - ((int)(info->my_doors->y / TILE_SIZE) * TILE_SIZE)) * data->arr[4].width) / TILE_SIZE;
	distance_top = y + (info->wallHeight / 2) - ((double)WIN_HEIGHT / 2);
	yofset = distance_top * data->arr[4].height / info->wallHeight;
	data->arr[4].xofset = abs((int)xofset);
	data->arr[4].yofset = abs((int)yofset);
}


void	draw_line(int x1, int y1, int y2, t_map *lst,t_data *data, t_cast *info)
{
    if (y1 < 0)
        y1 = 0;
    else
        draw_celling(x1, y1, lst, data);
    if (y2 >= WIN_HEIGHT)
        y2 = WIN_HEIGHT - 1;
    else
        draw_floor(x1, y2, lst, data);
    while (y1 <= y2)
	{
        texture(data, info, y1);
        writing_pxl_to_img2(lst, x1, y1, data);
        y1++;
    }
}

void    draw_wall_doors(t_cast *info, double x, t_map *lst, t_data *data)
{
    double  deg;

    deg = data->angle;
    deg = fmod(deg , (2 * M_PI));
    if (deg < 0)
        deg = (2 * M_PI) + deg;
    info->wallHeight = (TILE_SIZE / (info->dis * cos(deg - info->deg))) * info->dpp;
    info->TopPixel = (WIN_HEIGHT - info->wallHeight) / 2;
    info->BotPixel = WIN_HEIGHT - info->TopPixel;
    draw_line(x, info->TopPixel, info->BotPixel, lst, data, info);
}

void	raycast(t_cast *info, t_data *data)
{
    find_hor_inter(info, data);
    find_hor_step(info);
    find_hor_point(info, data);
    find_ver_inter(info, data);
    find_ver_step(info);
    find_ver_point(info, data);
    find_dis(info);
}

void	draw_fov(t_data *data, t_map *lst)
{
    t_cast  info;

    data->info = &info;
    double deg = data->angle - (30 * RAD);
    double incr = (((double)60  * RAD) / (double)WIN_WIDTH);
    info.dpp = ((double)WIN_WIDTH / 2) / tan(30 * RAD);
    data->rays = 0;
    while (data->rays < WIN_WIDTH)
    {
        deg = fmod(deg , (2 * M_PI));
        if (deg < 0)
            deg = (2 * M_PI) + deg;
        info.deg = deg;
        info.doors = false;
        raycast(&info, data); // find door && calcul dst && make bool false 
	   draw_wall_doors(&info, data->rays, lst, data);
	//    open_door(data);
     //    dda_algo(data, info.wx, info.wy);
        deg += incr;
        data->rays++;
    }
}
