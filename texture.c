/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:08:58 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/21 13:33:56 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	writing_pxl_to_img2(t_map *list, int x, int y, t_data *data)
{
	char	*adr;
	int		color;

    list->addr = mlx_get_data_addr(list->img, &list->bits, &list->size,&list->end);
    adr = list->addr + (y * list->size + x * (list->bits / 8));
	// printf("in pxl img : %d\n", data->ti);
	color = data->arr[data->ti].addr[(int)(data->arr[data->ti].yofset * data->arr[data->ti].width + data->arr[data->ti].xofset)];
    *(unsigned int *) adr = color;
}

void	texture(t_data *data, t_cast *info, double y1)
{
	int		distance_top;
    double  xofset;
    double  yofset;
	double	y;

	y = y1;
	xofset = 0.0;
	data->ti = choose_texture(info);
	// printf("in texture : %d\n", data->ti);
    if (info->horizontal_inter)
		xofset = ((info->wx - ((int)(info->wx / TILE_SIZE) * TILE_SIZE)) * data->arr[data->ti].width) / TILE_SIZE;
	else if (info->vertical_inter)
		xofset = ((info->wy - ((int)(info->wy / TILE_SIZE) * TILE_SIZE)) * data->arr[data->ti].width) / TILE_SIZE;
	distance_top = y + (info->wallHeight / 2) - ((double)WIN_HEIGHT / 2);
	yofset = distance_top * data->arr[data->ti].height / info->wallHeight;
	data->arr[data->ti].xofset = (int)xofset;
	data->arr[data->ti].yofset = (int)yofset;
}

void	loading_img(t_data *data)
{
	data->arr[NORTH].img = mlx_xpm_file_to_image(data->mlx, data->north, &data->arr[NORTH].width,&data->arr[NORTH].height);
	data->arr[SOUTH].img = mlx_xpm_file_to_image(data->mlx, data->south, &data->arr[SOUTH].width,&data->arr[SOUTH].height);
	data->arr[WEST].img = mlx_xpm_file_to_image(data->mlx, data->west, &data->arr[WEST].width,&data->arr[WEST].height);
	data->arr[EAST].img = mlx_xpm_file_to_image(data->mlx, data->east, &data->arr[EAST].width,&data->arr[EAST].height);
	
	data->arr[NORTH].addr = (int *)mlx_get_data_addr(data->arr[NORTH].img, &data->arr[NORTH].bits,&data->arr[NORTH].size,&data->arr[NORTH].end);
	data->arr[SOUTH].addr = (int *)mlx_get_data_addr(data->arr[SOUTH].img, &data->arr[SOUTH].bits,&data->arr[SOUTH].size,&data->arr[SOUTH].end);
	data->arr[WEST].addr = (int *)mlx_get_data_addr(data->arr[WEST].img , &data->arr[WEST].bits,&data->arr[WEST].size,&data->arr[WEST].end);
	data->arr[EAST].addr = (int *)mlx_get_data_addr(data->arr[EAST].img, &data->arr[EAST].bits,&data->arr[EAST].size,&data->arr[EAST].end);
}

int	choose_texture(t_cast *info)
{
	info->deg = fmod(info->deg , (2 * M_PI));
	if (info->deg < 0)
		info->deg = (2 * M_PI) + info->deg;
	if (info->vertical_inter)
	{
		if (info->deg > M_PI / 2 && info->deg < 3 * M_PI / 2)
			return (WEST);
		else
			return (EAST);
	}
	if (info->horizontal_inter)
	{
		if (info->deg > 0 && info->deg < M_PI)
			return (SOUTH);
		else
			return (NORTH);
	}
	return -1;
}