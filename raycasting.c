/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:13:28 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/13 20:52:01 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    raycast(t_cast   *info, t_data *data)
{
    find_hor_inter(info, data);
    find_hor_step(info);
    find_hor_point(info, data);
    find_ver_inter(info, data);
    find_ver_step(info);
    find_ver_point(info, data);
    find_dis(info);
}

void    draw_fov(t_data *data)
{
    t_cast	info;
    double	deg;
    double	incr;
	int		i;

    i = 0;
	deg = data->angle - (30 * RAD);
	incr = (((double)60  * RAD) / (double)WIN_WIDTH);
    while (i < WIN_WIDTH)
    { 
        deg = fmod(deg , (2 * M_PI));
        if (deg < 0)
            deg = (2 * M_PI) + deg;
        info.deg = deg;
        raycast(&info, data);
        dda_algo(data, info.wx, info.wy);
        deg += incr;
        i++;
    }
}