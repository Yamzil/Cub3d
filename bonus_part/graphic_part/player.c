/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <mjlem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:10:08 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/27 23:08:38 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

char	map_direction(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N')
				return ('N');
			else if (data->map[i][j] == 'E')
				return ('E');
			else if (data->map[i][j] == 'W')
				return ('W');
			else if (data->map[i][j] == 'S')
				return ('S');
			j++;
		}
		i++;
	}
	return ('\\');
}

double	player_direction(t_data *data)
{
	char	direction;

	direction = map_direction(data);
	if (direction == 'N')
		return (3 * M_PI / 2);
	else if (direction == 'S')
		return (M_PI / 2);
	else if (direction == 'E')
		return (0);
	else if (direction == 'W')
		return (M_PI);
	return (-1);
}

void	get_playerposition(t_data *d)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (d->map[i])
	{
		j = 0;
		x = 0;
		while (d->map[i][j])
		{
			if (d->map[i][j] == 'N' || d->map[i][j] == 'S' \
				|| d->map[i][j] == 'E' || d->map[i][j] == 'W')
			{
				d->p->x = x;
				d->p->y = y;
			}
			j++;
			x += TILE_SIZE;
		}
		i++;
		y += TILE_SIZE;
	}
}

void	draw_player(t_map *lst, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < PLAYER_SQUARE)
	{
		j = 0;
		while (j < PLAYER_SQUARE)
		{
			if ((x + i) >= WIN_WIDTH || (y + j) >= WIN_HEIGHT)
				return ;
			writing_pxl_to_img(lst, (x + i), (y + j), color);
			j++;
		}
		i++;
	}
}

void	check_player_position(t_data *l)
{
	double	x;
	double	y;

	l->angle += 0.0523599 * l->p->rotate_cam;
	if (l->p->move_a_d == -1)
	{
		y = l->p->y + cos(l->angle) * l->step;
		x = l->p->x - sin(l->angle) * l->step;
	}
	else if (l->p->move_a_d == 1)
	{
		y = l->p->y - cos(l->angle) * l->step;
		x = l->p->x + sin(l->angle) * l->step;
	}
	else
	{
		y = l->p->y + sin(l->angle) * l->step * l->p->move_w_s;
		x = l->p->x + cos(l->angle) * l->step * l->p->move_w_s;
	}
	if (!check_wall(l, x, l->p->y))
		l->p->x = x;
	if (!check_wall(l, l->p->x, y))
		l->p->y = y;
}
