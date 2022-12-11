/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:13:28 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/06 00:24:51 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdbool.h>

bool	check_wall(t_data *data, double x, double y)
{
    int	map_x;
    int	map_y;

    map_y = (int)(y / TILE_SIZE) - 1;
    map_x = (int)(x / TILE_SIZE) - 1;
    if (data->map[map_y][map_x] != '0' && data->map[map_y][map_x] != 'N'
        && data->map[map_y][map_x] != 'S' && data->map[map_y][map_x] != 'W'
        && data->map[map_y][map_x] != 'E')
        return (true);
    return (false);
}

void	ray_casting(t_data *data)
{
	data->angle = sanitize_angle(data);
	horizontal(data);
	vertical(data);
	hit_wall_vertical(data);
	hit_wall_horizental(data);
	check_distance(data);
}
void	cast_rays(t_data *data)
{
	data->rays->fov_angle = 60 * M_PI / 180;
	data->rays->ray_angle = data->angle - data->rays->fov_angle / 2;
	data->rays->rayCasting_incrementAngle = data->rays->fov_angle / WIN_WIDTH;
	int	i;
	i = -1;
	while (++i)
	{
		ray_casting(data);
		data->rays->ray_angle += data->rays->rayCasting_incrementAngle;
	}
}