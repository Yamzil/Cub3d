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

void	writing_pxl_to_img2(t_map *list, int x, int y, t_txtdata *txt)
{
	char	*adr;
	int		color;

    list->addr = mlx_get_data_addr(list->img, \
		&list->bits, &list->size,&list->end);
    adr = list->addr + (y *  list->size + x * (list->bits / 8));
	color = txt->addr[(int)(txt->yofset * txt->width + txt->xofset)];
    *(unsigned int *) adr = color;
	// printf("%d\n", color);
}

void	texture(t_cast *info, double y1, t_txtdata *txt)
{
    double  xofset = 0.0;
    double  yofset;
	double		y;

	y = y1;
    if (info->horizontal_inter)
		xofset = ((info->wx - ((int)(info->wx / TILE_SIZE) * TILE_SIZE)) * txt->width) / TILE_SIZE;
	else if (info->vertical_inter)
		xofset = ((info->wy - ((int)(info->wy / TILE_SIZE) * TILE_SIZE)) * txt->width) / TILE_SIZE;
	
	if (info->wallHeight > WIN_HEIGHT)
		y += (info->wallHeight / 2) - (WIN_HEIGHT / 2);
	yofset = ((y - info->TopPixel) * txt->height) / info->wallHeight;

	txt->xofset = (int)xofset;
	txt->yofset = (int)yofset;
}

void    get_texture(t_data *data)
{

    data->list->img = mlx_xpm_file_to_image(data->mlx, data->north, 
		&data->img_width, &data->img_height);
}