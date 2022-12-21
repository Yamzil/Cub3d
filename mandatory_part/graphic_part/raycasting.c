/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:13:28 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/21 18:11:31 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdio.h>

void draw_line(int x1, int y1, int y2, t_map *lst,t_data *data, t_cast *info)
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

void    draw_wall(t_cast *info, double  x, t_map *lst, t_data *data)
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
    double deg = data->angle - (30 * RAD);
    double incr = (((double)60  * RAD) / (double)WIN_WIDTH);
    info.dpp = ((double)WIN_WIDTH / 2) / tan(30 * RAD);
    int i = 0;
    while (i < WIN_WIDTH)
    { 
        deg = fmod(deg , (2 * M_PI));
        if (deg < 0)
            deg = (2 * M_PI) + deg;
        info.deg = deg;
        raycast(&info, data);
        draw_wall(&info, i, lst, data);
        dda_algo(data, info.wx, info.wy);
        deg += incr;
        i++;
    }
}
