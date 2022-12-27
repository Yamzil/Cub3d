/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:02:20 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/27 19:14:19 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	writing_pxl_to_img(t_map *li, int x, int y, int color)
{
	char	*adr;

	if (x < 0 || y < 0)
		printf("x%d | y%d\n", x, y);
	li->addr = mlx_get_data_addr(li->img, &li->bits, &li->size, &li->end);
	adr = li->addr + (y * li->size + x * (li->bits / 8));
	*(unsigned int *) adr = color;
}

void	draw_square(t_map *lst, int x, int y, int color)
{
	int	i;
	int	j;

	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return ;
	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			writing_pxl_to_img(lst, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	minimap(t_data *d, t_map *lst)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (d->map[i] && y - (d->p->y - 80) < 160)
	{
		j = 0;
		x = 0;
		while (d->map[i][j] && x - (d->p->x - 80) < 160)
		{
			if (d->map[i][j] == '0' || d->map[i][j] == 'N'
			|| d->map[i][j] == 'S'
				|| d->map[i][j] == 'E' || d->map[i][j] == 'W')
				draw_square(lst, x - (d->p->x - 80), y - (d->p->y - 80), WHITE);
			if (d->map[i][j] == '1')
				draw_square(lst, x - (d->p->x - 80), y - (d->p->y - 80), BLACK);
			x += TILE_SIZE;
			j++;
		}
		y += TILE_SIZE;
		i++;
	}
}

void	render(t_map *lst, t_data *d, int flag)
{
	if (flag)
		get_playerposition(d);
	draw_fov(d);
	minimap(d, lst);
	draw_player(lst, (d->p->x - (d->p->x - 80)), \
		(d->p->y - (d->p->y - 80)), ORANGE);
}
