/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:13:28 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/01 01:14:31 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h>

bool	check_wall(t_data *data, double x, double y)
{
    int	map_x;
    int	map_y;

    map_y = floor(y / 10) - 1;
    map_x = floor(x / 10) - 1;
    if (data->map[map_y][map_x] != '0' && data->map[map_y][map_x] != 'N')
        return (true);
    return (false);
}