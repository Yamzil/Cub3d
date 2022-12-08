/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:31:37 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/04 23:58:34 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

double	sanitize_angle(t_data *data)
{
	data->angle = fmod(data->angle, (2 * M_PI));
	if (data->angle < 0)
		data->angle = (2 * M_PI) + data->angle;
	return data->angle;
}

bool	rayisdown(t_data *data)
{
	if (data->angle > 0 && data->angle < M_PI)
		return (true);
	return (false);
}

bool	rayisup(t_data *data)
{
	if (!rayisdown(data))
		return (true);
	return (false);
}

bool	rayisright(t_data *data)
{
	if (data->angle < 0.5 * M_PI || data->angle > 1.5 * M_PI)
		return (true);
	return (false);
}

bool	rayisleft(t_data *data)
{
	if (!rayisright(data))
		return (true);
	return (false);
}
