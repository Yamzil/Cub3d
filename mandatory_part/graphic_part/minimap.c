/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:02:20 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/27 19:14:19 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	writing_pxl_to_img(t_map *l, int x, int y, int color)
{
	char	*adr;

	l->addr = mlx_get_data_addr(l->img, &l->bits, &l->size, &l->end);
	adr = l->addr + (y * l->size + x * (l->bits / 8));
	*(unsigned int *) adr = color;
}

void	render(t_data *data, int flag)
{
	if (flag)
		get_playerposition(data);
	draw_fov(data);
}
