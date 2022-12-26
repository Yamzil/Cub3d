/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_ver.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:09:56 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/23 18:34:51 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	find_ver_inter(t_cast *info, t_data *data)
{
    info->vxA = (int)(data->player->px / TILE_SIZE) * TILE_SIZE;
    if (info->deg < (M_PI / 2) || info->deg > ((3 * M_PI )/ 2))
        info->vxA += TILE_SIZE;
    info->vyA = data->player->py + ((info->vxA - data->player->px) \
	* tan(info->deg));
}

void	find_ver_step(t_cast *info)
{
    info->vxstep = TILE_SIZE;
    if (info->deg > (M_PI / 2) && info->deg < ((3 * M_PI )/ 2))
        info->vxstep *= -1;
    info->vystep = TILE_SIZE * tan(info->deg);
    if ((info->deg > M_PI && info->deg < (2 * M_PI) && info->vystep > 0) \
		|| (info->deg < M_PI && info->deg > 0 && info->vystep < 0)) 
        info->vystep *= -1;
}

void	find_ver_point(t_cast *info, t_data *data)
{
    double  tmpX;
    double  tmpY;

    tmpX = info->vxA;
    tmpY = info->vyA;
    info->my_doors = NULL;
	// info->doors = false;
    if (info->deg > (M_PI / 2) && info->deg < ((3 * M_PI )/ 2))
        tmpX -= 0.1;
    while (tmpX >= 0 && tmpY >= 0 && !check_wall(data, tmpX, tmpY))
    {
        tmpX += info->vxstep;
        tmpY += info->vystep;
    }
    info->vwallX = tmpX;
    info->vwallY = tmpY;
    info->vdis = distance(data->player->px, data->player->py, info->vwallX, info->vwallY);
}