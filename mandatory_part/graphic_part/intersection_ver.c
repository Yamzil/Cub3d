/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_ver.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:09:56 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/26 19:51:40 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	find_ver_inter(t_cast *info, t_data *d)
{
	info->vxA = (int)(d->player->px / TILE_SIZE) * TILE_SIZE;
	if (info->deg < (M_PI / 2) || info->deg > ((3 * M_PI) / 2))
		info->vxA += TILE_SIZE;
	info->vyA = d->player->py + ((info->vxA - d->player->px) * tan(info->deg));
}

void	find_ver_step(t_cast *info)
{
	info->vxstep = TILE_SIZE;
	if (info->deg > (M_PI / 2) && info->deg < ((3 * M_PI) / 2))
		info->vxstep *= -1;
	info->vystep = TILE_SIZE * tan(info->deg);
	if ((info->deg > M_PI && info->deg < (2 * M_PI) && info->vystep > 0) \
		|| (info->deg < M_PI && info->deg > 0 && info->vystep < 0))
		info->vystep *= -1;
}

void	find_ver_point(t_cast *in, t_data *d)
{
	double	tmpx;
	double	tmpy;

	tmpx = in->vxA;
	tmpy = in->vyA;
	if (in->deg > (M_PI / 2) && in->deg < ((3 * M_PI) / 2))
		tmpx -= 0.000001;
	while (tmpx >= 0 && tmpy >= 0 && !check_wall(d, tmpx, tmpy))
	{
		tmpx += in->vxstep;
		tmpy += in->vystep;
	}
	in->vwallX = tmpx;
	in->vwallY = tmpy;
	in->vdis = distance(d->player->px, d->player->py, in->vwallX, in->vwallY);
}
