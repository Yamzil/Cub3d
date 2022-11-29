/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:48:40 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/29 17:38:46 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void move_right(t_data *lst)
{
	mlx_destroy_image(lst->mlx, lst->list->img);
	lst->list->img = mlx_new_image(lst->mlx, WIN_WIDTH, \
		 WIN_HEIGHT);
	lst->py -= cos(lst->angle) * lst->step;
	lst->px += sin(lst->angle) * lst->step;
	render(lst->list, lst, 0);
	mlx_put_image_to_window(lst->mlx, lst->windows,\
		lst->list->img, 0, 0);
	
}

void	move_left(t_data *lst)
{
	mlx_destroy_image(lst->mlx, lst->list->img);
	lst->list->img = mlx_new_image(lst->mlx, WIN_WIDTH, \
		 WIN_HEIGHT);
	lst->py += cos(lst->angle) * lst->step;
	lst->px -= sin(lst->angle) * lst->step;
	render(lst->list, lst, 0);
	mlx_put_image_to_window(lst->mlx, lst->windows,\
		lst->list->img, 0, 0);
}

void	move_forward(t_data *lst)
{
	mlx_destroy_image(lst->mlx, lst->list->img);
	lst->list->img = mlx_new_image(lst->mlx, WIN_WIDTH, \
		 WIN_HEIGHT);
	lst->py += sin(lst->angle) * lst->step;
	lst->px += cos(lst->angle) * lst->step;
	
	render(lst->list, lst, 0);
	mlx_put_image_to_window(lst->mlx, lst->windows,\
		lst->list->img, 0, 0);
}

void	move_back(t_data *lst)
{
	mlx_destroy_image(lst->mlx, lst->list->img);
	lst->list->img = mlx_new_image(lst->mlx, WIN_WIDTH, \
		 WIN_HEIGHT);
	lst->angle = fmod(lst->angle, 2 * M_PI);
	if (lst->angle < 0)
		lst->angle = lst->angle + 2 * M_PI;
	lst->px -= cos(lst->angle) * lst->step;
	lst->py -= sin(lst->angle) * lst->step;
	render(lst->list, lst, 0);
	mlx_put_image_to_window(lst->mlx, lst->windows,\
		lst->list->img, 0, 0);
}

void	left_arrow(t_data *lst)
{
	lst->player->moveStep = 1;
	lst->angle -= (M_PI / 180) * lst->step;
}

void	right_arrow(t_data *lst)
{
	lst->player->moveStep = 1;
	lst->angle += (M_PI / 180) * lst->step;
}

int	key_press(int key, t_data  *lst)
{
	if (key == 53  || key == 17)
		exit (0);
	else if (key == 0)
		move_right(lst);
	else if (key == 2)
		move_left(lst);
	else if (key == 13)
		move_forward(lst);
	else if (key == 1)
		move_back(lst);
	else if (key == 123 )
	{
		lst->player->moveStep = 0;
		left_arrow(lst);
	}
	else if (key == 124)
	{
		lst->player->moveStep = 0;
		right_arrow(lst);
	}
	return (0);
}

int	key_realse(int key, t_data  *lst)
{
	if (key == 123)
		lst->player->moveStep = 0;
	else if (key == 124)
		lst->player->moveStep = 0;
	return (0);
}
