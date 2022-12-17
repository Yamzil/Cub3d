/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:31:37 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/17 10:29:47 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		arr_len(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

bool	check_wall(t_data *data, double x, double y)
{
    int	map_x;
    int	map_y;

	if (x < 0 && y < 0)
		return true;
	if (y >= WIN_HEIGHT || x >= WIN_WIDTH)
		return true;
    map_y = floor(y / TILE_SIZE);
    map_x = floor(x / TILE_SIZE);
	if (map_y >= arr_len(data->map))
		return true;
	if (map_x >= ft_strlen(data->map[map_y]))
		return true;
    if (data->map[map_y][map_x] == '1')
        return (true);
    return (false);
}

double  check_deg(double deg)
{
    if (deg < 0)
        deg *= -1;
    if (deg >  (2 * M_PI))
        deg -= (2 * M_PI);
    return deg;
}
