/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:02:20 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/29 15:47:50 by yamzil           ###   ########.fr       */
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
    while (i < 10)
    {
        j = 0;
        while (j < 10)
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
    y = 10;
    while (data->map[i])
    {
        j = 0;
		x = 10;
        while (data->map[i][j])
        {
            if (data->map[i][j] == '0' || data->map[i][j] == 'N')
                draw_square(lst, x, y, 16777215);
			if (data->map[i][j] == '1')
				draw_square(lst, x , y, 8421504);
            if (flag && data->map[i][j] == 'N'){
                data->px = x;
                data->py = y;
            }
			x += 10;
			j++;	
        }
		y  += 10; 
		i++;
    }
    
    draw_player(lst, data->px, data->py, 14335);
    dda_algo(data, data->px + cos(data->angle) * 10,data->py + sin(data->angle) * 10);
}
