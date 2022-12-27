/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:08:58 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/26 20:10:57 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	writing_pxl_to_img2(t_map *l, int x, int y, t_data *data)
{
	char	*adr;
	int		color;

	color = 0;
	if (data->arr[data->ti].yofset >= data->arr[data->ti].width)
		data->arr[data->ti].yofset = data->arr[data->ti].width - 1;
	l->addr = mlx_get_data_addr(l->img, &l->bits, &l->size, &l->end);
	if (l->addr == NULL)
		exit(EXIT_FAILURE);
	adr = l->addr + (y * l->size + x * (l->bits / 8));
	color = data->arr[data->ti].addr[(int)(data->arr[data->ti].yofset \
		* data->arr[data->ti].width + data->arr[data->ti].xofset)];
	*(unsigned int *) adr = color;
}

void	texture(t_data *d, t_cast *in, double y1)
{
	int		distance_top;
	double	xofset;
	double	yofset;
	double	y;

	y = y1;
	xofset = 0.0;
	d->ti = choose_texture(in);
	if (in->horizontal_inter)
	{
		xofset = ((in->wx - ((int)(in->wx / TILE_SIZE) * TILE_SIZE)) \
			* d->arr[d->ti].width) / TILE_SIZE;
	}
	else if (in->vertical_inter)
	{
		xofset = ((in->wy - ((int)(in->wy / TILE_SIZE) * TILE_SIZE)) \
			* d->arr[d->ti].width) / TILE_SIZE;
	}
	distance_top = y + (in->wallHeight / 2) - ((double)WIN_HEIGHT / 2);
	yofset = distance_top * d->arr[d->ti].height / in->wallHeight;
	d->arr[d->ti].xofset = abs((int)xofset);
	d->arr[d->ti].yofset = abs((int)yofset);
}

void	loading_textures(t_data *d)
{
	d->arr[NORTH].img = mlx_xpm_file_to_image(d->mlx, d->north, \
		&d->arr[NORTH].width, &d->arr[NORTH].height);
	d->arr[SOUTH].img = mlx_xpm_file_to_image(d->mlx, d->south, \
		&d->arr[SOUTH].width, &d->arr[SOUTH].height);
	d->arr[WEST].img = mlx_xpm_file_to_image(d->mlx, d->west, \
		&d->arr[WEST].width, &d->arr[WEST].height);
	d->arr[EAST].img = mlx_xpm_file_to_image(d->mlx, d->east, \
		&d->arr[EAST].width, &d->arr[EAST].height);
	d->arr[NORTH].addr = (int *)mlx_get_d_addr(d->arr[NORTH].img, \
		&d->arr[NORTH].bits, &d->arr[NORTH].size, &d->arr[NORTH].end);
	d->arr[SOUTH].addr = (int *)mlx_get_d_addr(d->arr[SOUTH].img, \
		&d->arr[SOUTH].bits, &d->arr[SOUTH].size, &d->arr[SOUTH].end);
	d->arr[WEST].addr = (int *)mlx_get_d_addr(d->arr[WEST].img, \
		&d->arr[WEST].bits, &d->arr[WEST].size, &d->arr[WEST].end);
	d->arr[EAST].addr = (int *)mlx_get_d_addr(d->arr[EAST].img, \
		&d->arr[EAST].bits, &d->arr[EAST].size, &d->arr[EAST].end);
}

int	choose_texture(t_cast *info)
{
	info->deg = fmod(info->deg, (2 * M_PI));
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
	return (-1);
}
