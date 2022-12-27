/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:10:08 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/26 20:36:05 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

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
				|| d->map[i][j] == 'E'|| d->map[i][j] == 'W')
			{
				d->player->px = x;
				d->player->py = y;
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
			writing_pxl_to_img(lst, (x + i), ( y + j), color);
			j++;
		}
		i++;
	}
}

void	check_player_position(t_data *l)
{
	double	x;
	double	y;

	l->angle += 0.0523599 * l->player->rotate_cam;
	if (l->player->move_a_d == -1)
	{
		y = l->player->py + cos(l->angle) * l->step;
		x = l->player->px - sin(l->angle) * l->step;
	}
	else if (l->player->move_a_d == 1)
	{
		y = l->player->py - cos(l->angle) * l->step;
		x = l->player->px + sin(l->angle) * l->step;
	}
	else
	{
		y = l->player->py + sin(l->angle) * l->step * l->player->move_w_s;
		x = l->player->px + cos(l->angle) * l->step * l->player->move_w_s;
	}
	if (!check_wall(l, x, l->player->py))
	{
		l->player->px = x;
	}
	if (!check_wall(l, l->player->px, y))
	{
		l->player->py = y;
	}
}
