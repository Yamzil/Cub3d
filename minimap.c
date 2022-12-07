/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:02:20 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/05 22:42:45 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	writing_pxl_to_img(t_map *list, int x, int y, int color)
{
	char	*adr;
    adr = list->address + (y *  list->size_line + x * (list->bits_per_pxl / 8));
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

void    draw_fov(t_data *data){

    double deg = data->angle - (30 * RAD);
    double incr = (((double)60  * RAD) / (double)WIN_WIDTH);
    int i = 0;
    /*  */
    while (i < WIN_WIDTH)
    {
        dda_algo(data, data->player->px + cos(deg) * WIN_WIDTH,data->player->py + sin(deg) * WIN_WIDTH);
        deg += incr;
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
    y = 10;
    while (data->map[i])
    {
        j = 0;
		x = 10;
        while (data->map[i][j])
        {
            if (data->map[i][j] == '0' || data->map[i][j] == 'N')
                draw_square(lst, x, y, WHITE);
			if (data->map[i][j] == '1')
				draw_square(lst, x , y, BLACK);
            if (flag && data->map[i][j] == 'N')
            {
                data->player->px = x;
                data->player->py = y;
            }
			x += 10;
			j++;	
        }
		y  += 10; 
		i++;
    }
    draw_player(lst, data->player->px, data->player->py, BLUE);
    draw_fov(data);
    // dda_algo(data, data->player->px + cos(data->angle) * WIN_WIDTH,data->player->py + sin(data->angle) * WIN_WIDTH);
}
