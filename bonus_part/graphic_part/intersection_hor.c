/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_hor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:12:18 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/23 18:34:46 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

bool	check_door(t_data *data, double x, double y)
{
    int	map_x;
    int	map_y;

	if (x < 0 && y < 0)
		return true;
	// if (y >= WIN_HEIGHT || x >= WIN_WIDTH)
	// 	return true;
    map_y = floor(y / TILE_SIZE);
    map_x = floor(x / TILE_SIZE);
	if (map_y >= arr_len(data->map))
		return true;
	if (map_x >= ft_strlen(data->map[map_y]))
		return true;
    if (data->map[map_y][map_x] == '2'){
        data->info->my_door->i = map_y;
        data->info->my_door->j = map_x;
        return (true);
    }
    return (false);
}

void	find_hor_inter(t_cast *info, t_data *data)
{
    info->yA = (int)(data->player->py / TILE_SIZE) * TILE_SIZE;
    if (info->deg < M_PI && info->deg > 0) 
        info->yA += TILE_SIZE;
    info->xA = data->player->px + ((info->yA - data->player->py) \
		/ tan(info->deg)); 
}

void	find_hor_step(t_cast *info)
{

    info->ystep = TILE_SIZE;
    if (info->deg > M_PI && info->deg < (2 * M_PI))
        info->ystep *= -1;
    info->xstep = TILE_SIZE / tan(info->deg);
    if (((info->deg > (M_PI / 2) && info->deg < ((3 * M_PI )/ 2)) \
		&& info->xstep > 0) || ((info->deg < (M_PI / 2) \
		|| info->deg > ((3 * M_PI )/ 2)) && info->xstep < 0))
        info->xstep *= -1;
}

void	find_hor_point(t_cast *info, t_data *data)
{
    double tmpX;
    double tmpY;

    tmpX = info->xA;
    tmpY = info->yA;
    info->hdoor = false;
    if (info->deg > M_PI && info->deg < (2 * M_PI))
        tmpY -= 0.0001;
    while (tmpX >= 0 && tmpY >= 0 && !check_wall(data, tmpX, tmpY))
    {
        if (check_door(data, tmpX, tmpY))
        {
            // ft_lstadd_front(&info->my_door,ft_newlst(tmpX, tmpY,distance(data->player->px, data->player->py, tmpX, tmpY)));
            info->my_door->distance = distance(data->player->px, data->player->py, tmpX, tmpY);
            info->my_door->x = tmpX;
            info->my_door->y = tmpY;
            data->info->doors = true;
            info->hdoor = true;
            // return true;
        }
        tmpX += info->xstep;
        tmpY += info->ystep;
    }
    info->hwallX = tmpX;
    info->hwallY = tmpY;
    info->hdis = distance(data->player->px, data->player->py, info->hwallX, info->hwallY);
}