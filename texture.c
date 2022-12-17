/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:08:58 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/17 12:59:15 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	texture(t_data *data, t_cast *info)
{
    double  xofset;
    double  yofset;
	double	ver;
	double	hor;
	int		y;

	y = info->TopPixel;
    if (info->horizontal_inter)
	{
		hor = distance(info->wx, info->wy, floor(info->wx), floor(info->wy));
		xofset = (data->img_width * hor) / TILE_SIZE;
	}
	else if (info->vertical_inter)
	{
		ver = distance(info->wx, info->wy, floor(info->wx), floor(info->wy));
		xofset = (data->img_width * ver) / TILE_SIZE;
		while (y < info->BotPixel)
		{
			yofset = (y - info->TopPixel)
			
		}
	}
}

void    get_texture(t_data *data)
{

    data->list->img = mlx_xpm_file_to_image(data->mlx, data->north, 
		&data->img_width, &data->img_height);
}