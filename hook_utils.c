/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:48:40 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/30 01:24:35 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void move_right(t_data *lst)
{
	lst->py -= cos(lst->angle) * lst->step;
	lst->px += sin(lst->angle) * lst->step;
}

void	move_left(t_data *lst)
{
	lst->py += cos(lst->angle) * lst->step;
	lst->px -= sin(lst->angle) * lst->step;
}

void	move_forward(t_data *lst)
{
	lst->py += sin(lst->angle) * lst->step;
	lst->px += cos(lst->angle) * lst->step;
}

void	move_back(t_data *lst)
{
	lst->angle = fmod(lst->angle, 2 * M_PI);
	if (lst->angle < 0)
		lst->angle = lst->angle + 2 * M_PI;
	lst->px -= cos(lst->angle) * lst->step;
	lst->py -= sin(lst->angle) * lst->step;
}

void	left_arrow(t_data *lst)
{
	lst->angle -= (M_PI / 180) * lst->step;
	if (lst->angle <= 0)
		lst->angle = 6.28;	
}

void	right_arrow(t_data *lst)
{
	lst->angle += (M_PI / 180) * lst->step;
	if (lst->angle >= 6.28)
		lst->angle = 0;
}

int	key_start(int key, t_data  *lst)
{
	if (key == 53 || key == 17)
		exit (0);
	else if (key == 123)
		lst->player->moveStep = -1;
	else if (key == 124)
		lst->player->moveStep = 1;
	else if (key == 13)
		lst->player->move_w_s = 1;
	else if (key == 1)
		lst->player->move_w_s = -1;
	else if (key == 0)
		lst->player->move_a_d = 1;
	else if (key == 2)
		lst->player->move_a_d = -1;
	return (0);
}

int	key_press(t_data *lst)
{
	mlx_destroy_image(lst->mlx, lst->list->img);
	lst->list->img = mlx_new_image(lst->mlx, WIN_WIDTH, \
		 WIN_HEIGHT);
	if (lst->player->move_w_s == 1)
		move_forward(lst);
	if (lst->player->move_w_s == -1)
		move_back(lst);
	if (lst->player->move_a_d == 1)
		move_right(lst);
	if (lst->player->move_a_d == -1)
		move_left(lst);
	if (lst->player->moveStep == -1)
		left_arrow(lst);
	if (lst->player->moveStep == 1)
		right_arrow(lst);
	render(lst->list, lst, 0);
	mlx_put_image_to_window(lst->mlx, lst->windows,\
		lst->list->img, 0, 0);
	return (0);
}

int	key_realse(int key, t_data  *lst)
{
	if (key == 123)
		lst->player->moveStep = 0;
	else if (key == 124)
		lst->player->moveStep = 0;
	else if (key == 0)
		lst->player->move_a_d  = 0;
	else if (key == 2)
		lst->player->move_a_d = 0;
	else if (key == 13)
		lst->player->move_w_s = 0;
	else if (key == 1)
		lst->player->move_w_s = 0;
	return (0);
}

