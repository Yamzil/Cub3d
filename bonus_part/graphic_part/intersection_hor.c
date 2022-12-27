/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_hor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:12:18 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/26 12:56:55 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

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
        tmpY -= 0.1;
    while (tmpX >= 0 && tmpY >= 0 && !check_wall(data, tmpX, tmpY))
    {
        if (check_door(data, tmpX, tmpY))
        {
            info->my_door->distance = distance(data->player->px, data->player->py, tmpX, tmpY);
            info->my_door->x = tmpX;
            info->my_door->y = tmpY;
            data->info->doors = true;
            info->hdoor = true;
        }
        tmpX += info->xstep;
        tmpY += info->ystep;
    }
    info->hwallX = tmpX;
    info->hwallY = tmpY;
    info->hdis = distance(data->player->px, data->player->py, info->hwallX, info->hwallY);
}