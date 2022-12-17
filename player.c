/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:10:08 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/17 11:13:44 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
			if (data->map[i][j] ==  'N')
				return  'N';
			else if (data->map[i][j] == 'E')
				return  'E';
			else if (data->map[i][j] == 'W')
				return  'W';
			else if (data->map[i][j] == 'S')
				return  'S';
			j++;
		}
		i++;
	}
	return '\\';
}

double	player_direction(t_data *data)
{
	char	direction;
	
	direction = map_direction(data);
	if (direction == 'N')
		return 3 * M_PI / 2;
	else if (direction == 'S')
		return M_PI / 2;
	else if (direction == 'E')
		return 0;
	else if (direction == 'W')
		return M_PI;
	return (-1);
}

void	get_playerposition(t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (data->map[i])
	{
		j = 0;
		x = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S' \
				|| data->map[i][j] == 'E' \
				|| data->map[i][j] == 'W')
            {
                data->player->px = x;
                data->player->py = y;
            }
			j++;
			x += TILE_SIZE;
		}
		i++;
		y += TILE_SIZE;
	}
}

void draw_player(t_map *lst, int x, int y, int color)
{
    int i;
	int	j;

    i = 0;
    while (i < PLAYER_SQUARE)
    {
        j = 0;
        while (j < PLAYER_SQUARE)
        {
			writing_pxl_to_img(lst, 0.5 * (x + i), 0.5 *( y + j), color);
			j++;	
        }
		i++;
    }
}

void	check_player_position(t_data *lst)
{
	double x;
	double y;

	lst->angle += 0.026 * lst->player->rotate_cam;
	if (lst->player->move_a_d == -1)
	{
		y = lst->player->py + cos(lst->angle) * lst->step;
		x = lst->player->px - sin(lst->angle) * lst->step;
	}
	else if (lst->player->move_a_d == 1)
	{
		y = lst->player->py - cos(lst->angle) * lst->step;
		x = lst->player->px + sin(lst->angle) * lst->step;
	}
	else
	{
		y = lst->player->py + sin(lst->angle) * lst->step * lst->player->move_w_s;
		x = lst->player->px + cos(lst->angle) * lst->step * lst->player->move_w_s;
	}
	if (!check_wall(lst, x, lst->player->py))
	{
		lst->player->px = x;
	}
	if (!check_wall(lst, lst->player->px, y))
	{
		lst->player->py = y;
	}
}
