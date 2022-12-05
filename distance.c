/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:51:05 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/06 00:04:53 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    check_distance(t_data *data)
{
    data->rays->vertical_dst = sqrt(pow(data->player->px \
    - data->rays->ax_vertical, 2) 
    + pow(data->player->py - data->rays->ay_vertical, 2));
	data->rays->horizental_dst = sqrt(pow(data->player->px \
    - data->rays->ax_horizontal, 2) 
    + pow(data->player->py - data->rays->ay_horizontal, 2));
}