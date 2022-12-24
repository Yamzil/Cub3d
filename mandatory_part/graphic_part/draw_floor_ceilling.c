/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceilling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:25:12 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/21 21:04:07 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	draw_celling(int x1, int y1, t_map *lst, t_data *data)
{
    int i;

    i = 0;
    while (i < y1)
    {
        writing_pxl_to_img(lst, x1, i, data->ceilling);
        i++;
    }
}

void	draw_floor(int x1, int y1, t_map *lst, t_data *data)
{

    while (y1 + 1 < WIN_HEIGHT)
    {
        writing_pxl_to_img(lst, x1, y1, data->floor);
        y1++;
    }
}