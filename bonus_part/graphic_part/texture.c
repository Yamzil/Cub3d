/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <mjlem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:08:24 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/27 23:08:33 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

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

void	loading_textures(t_data *d)
{
	d->arr[NORTH].img = mlx_xpm_file_to_image(d->mlx, d->north, \
		&d->arr[NORTH].width, &d->arr[NORTH].height);
	if (!d->arr[NORTH].img)
		exit(EXIT_FAILURE);
	d->arr[SOUTH].img = mlx_xpm_file_to_image(d->mlx, d->south, \
		&d->arr[SOUTH].width, &d->arr[SOUTH].height);
	if (!d->arr[SOUTH].img)
		exit(EXIT_FAILURE);
	d->arr[WEST].img = mlx_xpm_file_to_image(d->mlx, d->west, \
		&d->arr[WEST].width, &d->arr[WEST].height);
	if (!d->arr[WEST].img)
		exit(EXIT_FAILURE);
	d->arr[EAST].img = mlx_xpm_file_to_image(d->mlx, d->east, \
		&d->arr[EAST].width, &d->arr[EAST].height);
	if (!d->arr[EAST].img)
		exit(EXIT_FAILURE);
	d->arr[NORTH].addr = (int *)mlx_get_data_addr(d->arr[NORTH].img, \
		&d->arr[NORTH].bits, &d->arr[NORTH].size, &d->arr[NORTH].end);
	d->arr[SOUTH].addr = (int *)mlx_get_data_addr(d->arr[SOUTH].img, \
		&d->arr[SOUTH].bits, &d->arr[SOUTH].size, &d->arr[SOUTH].end);
	d->arr[WEST].addr = (int *)mlx_get_data_addr(d->arr[WEST].img, \
		&d->arr[WEST].bits, &d->arr[WEST].size, &d->arr[WEST].end);
	d->arr[EAST].addr = (int *)mlx_get_data_addr(d->arr[EAST].img, \
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
