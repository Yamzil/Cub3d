/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_ver.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:09:56 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/27 19:14:19 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	find_ver_inter(t_cast *info, t_data *d)
{
	info->vxa = (int)(d->p->x / TILE_SIZE) * TILE_SIZE;
	if (info->deg < (M_PI / 2) || info->deg > ((3 * M_PI) / 2))
		info->vxa += TILE_SIZE;
	info->vya = d->p->y + ((info->vxa - d->p->x) * tan(info->deg));
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

	tmpx = in->vxa;
	tmpy = in->vya;
	if (in->deg > (M_PI / 2) && in->deg < ((3 * M_PI) / 2))
		tmpx -= 0.000001;
	while (tmpx >= 0 && tmpy >= 0 && !check_wall(d, tmpx, tmpy))
	{
		tmpx += in->vxstep;
		tmpy += in->vystep;
	}
	in->vwallx = tmpx;
	in->vwally = tmpy;
	in->vdis = distance(d->p->x, d->p->y, in->vwallx, in->vwally);
}
