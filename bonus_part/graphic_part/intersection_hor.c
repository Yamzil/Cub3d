/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_hor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:12:18 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/27 19:14:19 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	find_hor_inter(t_cast *info, t_data *d)
{
	info->ya = (int)(d->p->y / TILE_SIZE) * TILE_SIZE;
	if (info->deg < M_PI && info->deg > 0)
		info->ya += TILE_SIZE;
	info->xa = d->p->x + ((info->ya - d->p->y) / tan(info->deg));
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

void	find_hor_point(t_cast *in, t_data *d)
{
	double	tmpx;
	double	tmpy;

	tmpx = in->xa;
	tmpy = in->ya;
	in->hdoor = false;
	if (in->deg > M_PI && in->deg < (2 * M_PI))
		tmpy -= 0.000001;
	while (tmpx >= 0 && tmpy >= 0 && !check_wall(d, tmpx, tmpy))
	{
		tmpx += in->xstep;
		tmpy += in->ystep;
	}
	in->hwallx = tmpx;
	in->hwally = tmpy;
	in->hdis = distance(d->p->x, d->p->y, in->hwallx, in->hwally);
}
