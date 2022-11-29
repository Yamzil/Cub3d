/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:42:35 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/29 15:39:21 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
