/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:42:35 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/28 18:54:38 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	render_player(t_player *player, t_map *map)
{
	writing_pxl_to_img(map, player->x, player->y, 14335);
}

void draw_player(t_map *lst, int x, int y, int color)
{
    int i;
	int	j;

    i = 0;
    while (i < 5)
    {
        j = 0;
        while (j < 5)
        {
			writing_pxl_to_img(lst, x + i, y + j, color);
			j++;	
        }
		i++;
    }
}
