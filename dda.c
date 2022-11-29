/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:43:43 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/29 15:44:05 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    dda_algo(t_data *data, double x1, double y1)
{
	double	dx;
	double	dy;
	double	step;
	double	xinc;
	double	yinc;
	double new_x;
	double new_y;


	dx = x1 - data->px;
	dy = y1 - data->py;
	new_x = data->px + 2.0;
	new_y = data->py + 2.0;
	if (fabs(dx) > fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	xinc = dx / step;
	yinc = dy / step;
	int i;

	i = 0;
	while (i < step)
	{
		new_x += xinc;
		new_y += yinc;
		writing_pxl_to_img(data->list, new_x, new_y , 14335);
		i++;
	}
}