/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:13:28 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/26 20:05:38 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	draw_line(int x1, int y1, int y2, t_map *lst,t_data *data, t_cast *info)
{
	if (y1 < 0)
		y1 = 0;
	else
		draw_celling(x1, y1, lst, data);
	if (y2 >= WIN_HEIGHT || y2 < 0)
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

void	draw_wall(t_cast *inf, double x, t_map *lst, t_data *data)
{
	double	deg;

	deg = data->angle;
	deg = fmod(deg, (2 * M_PI));
	if (deg < 0)
		deg = (2 * M_PI) + deg;
	inf->wallHeight = (TILE_SIZE / (inf->dis * cos(deg - inf->deg))) * inf->dpp;
	inf->TopPixel = (WIN_HEIGHT - inf->wallHeight) / 2;
	inf->BotPixel = WIN_HEIGHT - inf->TopPixel;
	draw_line(x, inf->TopPixel, inf->BotPixel, lst, data, inf);
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
	t_cast	info;
	double	deg;
	double	incr;
	int		i;

	deg = data->angle - (30 * RAD);
	incr = (((double)60 * RAD) / (double)WIN_WIDTH);
	info.dpp = ((double)WIN_WIDTH / 2) / tan(30 * RAD);
	i = 0;
	while (i < WIN_WIDTH)
	{
		deg = fmod(deg, (2 * M_PI));
		if (deg < 0)
			deg = (2 * M_PI) + deg;
		info.deg = deg;
		raycast(&info, data);
		draw_wall(&info, i, lst, data);
		deg += incr;
		i++;
	}
}
