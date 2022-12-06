/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:10:08 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/01 14:50:57 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_player(t_map *lst, int x, int y, int color)
{
    int i;
	int	j;

    i = 0;
    while (i < PLAYER_SQUARE)
    {
        j = 0;
        while (j < PLAYER_SQUARE)
        {
			writing_pxl_to_img(lst, x + i, y + j, color);
			j++;	
        }
		i++;
    }
}

void	check_player_position(t_data *lst)
{
	double x;
	double y;

	lst->angle += (M_PI / 180) * lst->step * lst->player->rotate_cam;
	if (lst->player->move_a_d == -1)
	{
		y = lst->player->py + cos(lst->angle) * lst->step;
		x = lst->player->px - sin(lst->angle) * lst->step;
	}
	else if (lst->player->move_a_d == 1)
	{
		y = lst->player->py - cos(lst->angle) * lst->step;
		x = lst->player->px + sin(lst->angle) * lst->step;
	}
	else
	{
		y = lst->player->py + sin(lst->angle) * lst->step * lst->player->move_w_s;
		x = lst->player->px + cos(lst->angle) * lst->step * lst->player->move_w_s;
	}
	if (!check_wall(lst, x, y))
	{
		lst->player->py = y;
		lst->player->px = x;
	}
}
