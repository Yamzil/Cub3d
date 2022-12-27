/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_hor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:12:18 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/26 19:49:15 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	find_hor_inter(t_cast *info, t_data *d)
{
	info->yA = (int)(d->player->py / TILE_SIZE) * TILE_SIZE;
	if (info->deg < M_PI && info->deg > 0)
		info->yA += TILE_SIZE;
	info->xA = d->player->px + ((info->yA - d->player->py) / tan(info->deg));
}

void	find_hor_step(t_cast *info)
{
	info->ystep = TILE_SIZE;
	if (info->deg > M_PI && info->deg < (2 * M_PI))
		info->ystep *= -1;
	info->xstep = TILE_SIZE / tan(info->deg);
	if (((info->deg > (M_PI / 2) && info->deg < ((3 * M_PI) / 2)) \
		&& info->xstep > 0) || ((info->deg < (M_PI / 2) \
		|| info->deg > ((3 * M_PI) / 2)) && info->xstep < 0))
		info->xstep *= -1;
}

void	find_hor_point(t_cast *info, t_d *data)
{
	double	tmpx;
	double	tmpy;

	tmpx = info->xA;
	tmpy = info->yA;
	if (info->deg > M_PI && info->deg < (2 * M_PI))
		tmpy -= 0.000001;
	while (tmpx >= 0 && tmpy >= 0 && !check_wall(data, tmpx, tmpy))
	{
		tmpx += info->xstep;
		tmpy += info->ystep;
	}
	info->hwallX = tmpx;
	info->hwallY = tmpy;
	info->hdis = distance(data->player->px, data->player->py, \
	info->hwallX, info->hwallY);
}
