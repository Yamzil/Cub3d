/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:08:24 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/27 19:15:31 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	writing_pxl_to_img2(t_map *li, int x, int y, t_data *d)
{
	char	*adr;
	int		color;

	li->addr = mlx_get_data_addr(li->img, &li->bits, &li->size, &li->end);
	adr = li->addr + (y * li->size + x * (li->bits / 8));
	color = d->arr[d->ti].addr[(int)(d->arr[d->ti].yofset \
		* d->arr[d->ti].width + d->arr[d->ti].xofset)];
	*(unsigned int *) adr = color;
}

void	texture(t_data *data, t_cast *info, double y1)
{
	int		distance_top;
	double	xofset;
	double	yofset;
	double	y;

	y = y1;
	xofset = 0.0;
	data->ti = choose_texture(info);
	if (info->horizontal_inter)
	{
		xofset = ((info->wx - ((int)(info->wx / TILE_SIZE) * TILE_SIZE)) \
			* data->arr[data->ti].width) / TILE_SIZE;
	}
	else if (info->vertical_inter)
	{
		xofset = ((info->wy - ((int)(info->wy / TILE_SIZE) * TILE_SIZE)) \
			* data->arr[data->ti].width) / TILE_SIZE;
	}
	distance_top = y + (info->wallheight / 2) - ((double)WIN_HEIGHT / 2);
	yofset = distance_top * data->arr[data->ti].height / info->wallheight;
	data->arr[data->ti].xofset = abs((int)xofset);
	data->arr[data->ti].yofset = abs((int)yofset);
}

void	loading_textures(t_data *r)
{
	r->arr[NORTH].img = mlx_xpm_file_to_image(r->mlx, r->north, \
		&r->arr[NORTH].width, &r->arr[NORTH].height);
	r->arr[SOUTH].img = mlx_xpm_file_to_image(r->mlx, r->south, \
		&r->arr[SOUTH].width, &r->arr[SOUTH].height);
	r->arr[WEST].img = mlx_xpm_file_to_image(r->mlx, r->west, \
		&r->arr[WEST].width, &r->arr[WEST].height);
	r->arr[EAST].img = mlx_xpm_file_to_image(r->mlx, r->east, \
		&r->arr[EAST].width, &r->arr[EAST].height);
	r->arr[NORTH].addr = (int *)mlx_get_data_addr(r->arr[NORTH].img, \
		&r->arr[NORTH].bits, &r->arr[NORTH].size, &r->arr[NORTH].end);
	r->arr[SOUTH].addr = (int *)mlx_get_data_addr(r->arr[SOUTH].img, \
		&r->arr[SOUTH].bits, &r->arr[SOUTH].size, &r->arr[SOUTH].end);
	r->arr[WEST].addr = (int *)mlx_get_data_addr(r->arr[WEST].img, \
		&r->arr[WEST].bits, &r->arr[WEST].size, &r->arr[WEST].end);
	r->arr[EAST].addr = (int *)mlx_get_data_addr(r->arr[EAST].img, \
		&r->arr[EAST].bits, &r->arr[EAST].size, &r->arr[EAST].end);
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
