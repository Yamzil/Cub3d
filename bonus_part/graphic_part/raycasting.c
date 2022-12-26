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

void	writing_pxl_to_img3(t_map *list, int x, int y, t_data *data, int t)
{
	char	*adr;
	int		color;

    list->addr = mlx_get_data_addr(list->img, &list->bits, &list->size,&list->end);
    adr = list->addr + (y * list->size + x * (list->bits / 8));
	color = data->door_arr[t].addr[(int)(data->door_arr[t].yofset * data->door_arr[t].width + data->door_arr[t].xofset)];
    if (color != 16711935)
        *(unsigned int *) adr = color;
}

void	texture1(t_data *data, t_cast *info, double y1, int t)
{
	int		distance_top;
    double  xofset;
    double  yofset;
	double	y;

	y = y1;
	xofset = 0.0;
    if (info->hdoor)
		xofset = ((info->my_door->x - ((int)(info->my_door->x / TILE_SIZE) * TILE_SIZE)) * data->door_arr[t].width) / TILE_SIZE;
	else if (info->vdoor)
		xofset = ((info->my_door->y - ((int)(info->my_door->y / TILE_SIZE) * TILE_SIZE)) * data->door_arr[t].width) / TILE_SIZE;
	distance_top = y + (info->doorHeight / 2) - ((double)WIN_HEIGHT / 2);
	yofset = distance_top * data->door_arr[t].height / info->doorHeight;
	data->door_arr[t].xofset = abs((int)xofset);
	data->door_arr[t].yofset = abs((int)yofset);
}

void	draw_line2(int x1, int y1, int y2, t_map *lst,t_data *data, t_cast *info, int t)
{
    if (y1 < 0)
        y1 = 0;
    if (y2 >= WIN_HEIGHT)
        y2 = WIN_HEIGHT - 1;
    if (info->wallHeight < info->doorHeight){
        while (y1 <= y2)
        {
            texture1(data, info, y1, t);
            writing_pxl_to_img3(lst, x1, y1, data, t);
            y1++;
        }
    }
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

void    draw_wall(t_cast *info, double x, t_map *lst, t_data *data)
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

void    draw_door(t_cast *info, double x, t_map *lst, t_data *data, int t)
{
    double  deg;

    deg = data->angle;
    deg = fmod(deg , (2 * M_PI));
    if (deg < 0)
        deg = (2 * M_PI) + deg;
    info->doorHeight = (TILE_SIZE / (info->my_door->distance * cos(deg - info->deg))) * info->dpp;
    info->tdPixel = (WIN_HEIGHT - info->doorHeight) / 2;
    info->bdPixel = WIN_HEIGHT - info->tdPixel;
    draw_line2(x, info->tdPixel, info->bdPixel, lst, data, info, t);
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
    info.my_door = malloc(sizeof(t_door));
    double deg = data->angle - (30 * RAD);
    double incr = (((double)60  * RAD) / (double)WIN_WIDTH);
    info.dpp = ((double)WIN_WIDTH / 2) / tan(30 * RAD);
    data->rays = 0;
    int t;
    while (data->rays < WIN_WIDTH)
    {
        deg = fmod(deg , (2 * M_PI));
        if (deg < 0)
            deg = (2 * M_PI) + deg;
        info.deg = deg;
        info.doors = false;
        raycast(&info, data); // find door && calcul dst && make bool false 
	   draw_wall(&info, data->rays, lst, data);
        t = open_door(data);
       if(info.doors)
	     draw_door(&info, data->rays, lst, data, t);
	//    open_door(data);
     //    dda_algo(data, info.wx, info.wy);
        deg += incr;
        data->rays++;
    }
}
