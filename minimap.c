/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:02:20 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/17 11:12:55 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdbool.h>

void	writing_pxl_to_img(t_map *list, int x, int y, int color)
{
	char	*adr;
    list->addr = mlx_get_data_addr(list->img, \
		&list->bits, &list->size,&list->end);
    adr = list->addr + (y *  list->size + x * (list->bits / 8));
    *(unsigned int *) adr = color; 
}

void    draw_square(t_map *lst, int x, int y, int color)
{
    int i;
	int	j;

    i = 0;
    while (i < TILE_SIZE)
    {
        j = 0;
        while (j < TILE_SIZE)
        {
			writing_pxl_to_img(lst, x + i, y + j, color);
			j++;	
        }
		i++;
    }
}

void    render(t_map *lst, t_data *data, int flag)
{
    int i;
	int	j;
	int x;
	int y;
		
    i = 0;
    y = 0;
	if (flag)
		get_playerposition(data);
    draw_fov(data, lst);
    while (data->map[i])
    {
        j = 0;
		x = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == '0' || data->map[i][j] == 'N' \
				|| data->map[i][j] == 'S' || data->map[i][j] == 'E' \
				|| data->map[i][j] == 'W')
                draw_square(lst, 0.5 * x, 0.5 * y, WHITE);
			if (data->map[i][j] == '1')
				draw_square(lst, 0.5 * x , 0.5 * y, BLACK);
			x += TILE_SIZE;
			j++;	
        }
		y  += TILE_SIZE; 
		i++;
    }
    draw_player(lst, data->player->px, data->player->py, BLUE);
    dda_algo(data, data->player->px + cos(data->angle) * 20,data->player->py + sin(data->angle) * 20);
}
