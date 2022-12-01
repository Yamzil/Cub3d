/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:48:40 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/01 01:33:35 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdio.h>

void	check_player_position(t_data *lst)
{
	double x, y;

	lst->angle += (M_PI / 180) * lst->step * lst->player->moveStep;
	if (lst->player->move_a_d == -1)
	{
		y = lst->py + cos(lst->angle) * lst->step;
		x = lst->px - sin(lst->angle) * lst->step;
	}
	else if (lst->player->move_a_d == 1)
	{
		y = lst->py - cos(lst->angle) * lst->step;
		x = lst->px + sin(lst->angle) * lst->step;
	}
	else
	{
		y = lst->py + sin(lst->angle) * lst->step * lst->player->move_w_s;
		x = lst->px + cos(lst->angle) * lst->step * lst->player->move_w_s;
	}
	if (!check_wall(lst, x, y))
	{
		lst->py = y;
		lst->px = x;
	}
}

int	key_press(t_data *lst)
{
	mlx_destroy_image(lst->mlx, lst->list->img);
	lst->list->img = mlx_new_image(lst->mlx, WIN_WIDTH, \
		 WIN_HEIGHT);
	check_player_position(lst);
	render(lst->list, lst, 0);
	mlx_put_image_to_window(lst->mlx, lst->windows,\
		lst->list->img, 0, 0);
	return (0);
}

int	key_start(int key, t_data  *lst)
{
	if (key == ESCHAP || key == RED_CROSS)
		exit (0);
	else if (key == LEFT_ARROW)
		lst->player->moveStep = -1;
	else if (key == RIGHT_ARROW)
		lst->player->moveStep = 1;
	else if (key == FORWARD)
		lst->player->move_w_s = 1;
	else if (key == BACKWARD)
		lst->player->move_w_s = -1;
	else if (key == LEFT)
		lst->player->move_a_d = 1;
	else if (key == RIGHT)
		lst->player->move_a_d = -1;
	return (0);
}


int	key_realse(int key, t_data  *lst)
{
	if (key == LEFT_ARROW)
		lst->player->moveStep = 0;
	else if (key == RIGHT_ARROW)
		lst->player->moveStep = 0;
	else if (key == LEFT)
		lst->player->move_a_d  = 0;
	else if (key == RIGHT)
		lst->player->move_a_d = 0;
	else if (key == FORWARD)
		lst->player->move_w_s = 0;
	else if (key == BACKWARD)
		lst->player->move_w_s = 0;
	return (0);
}

