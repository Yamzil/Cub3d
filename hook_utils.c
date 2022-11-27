/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:48:40 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/27 23:30:18 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void move_right(t_data *lst)
{
	mlx_destroy_image(lst->mlx, lst->list->img);
	lst->list->img = mlx_new_image(lst->mlx, WIN_WIDTH, \
		 WIN_HEIGHT);
	lst->px -= 3;
	lst->angle += 0.1;
	if (lst->angle > M_PI)
		lst->angle -= M_PI;
	lst->pdx = cos(lst->angle) * 5;
	lst->pdy = sin(lst->angle);
	render(lst->list, lst, 0);
	mlx_put_image_to_window(lst->mlx, lst->windows,\
		lst->list->img, 0, 0);
	
}

void	move_left(t_data *lst)
{
	lst->angle = M_PI;
	mlx_destroy_image(lst->mlx, lst->list->img);
	lst->list->img = mlx_new_image(lst->mlx, WIN_WIDTH, \
		 WIN_HEIGHT);
	lst->px += 3;
	lst->angle -= 0.1;
	if (lst->angle < 0)
		lst->angle += M_PI;
	lst->pdx = cos(lst->angle) * 5;
	lst->pdy = sin(lst->angle);
	render(lst->list, lst, 0);
	mlx_put_image_to_window(lst->mlx, lst->windows,\
		lst->list->img, 0, 0);
}

void	move_forward(t_data *lst)
{
	mlx_destroy_image(lst->mlx, lst->list->img);
	lst->list->img = mlx_new_image(lst->mlx, WIN_WIDTH, \
		 WIN_HEIGHT);
	lst->py -= 3;
	lst->pdx += lst->pdx;
	lst->pdy += lst->pdy;
	render(lst->list, lst, 0);
	mlx_put_image_to_window(lst->mlx, lst->windows,\
		lst->list->img, 0, 0);
}

void	move_back(t_data *lst)
{
	mlx_destroy_image(lst->mlx, lst->list->img);
	lst->list->img = mlx_new_image(lst->mlx, WIN_WIDTH, \
		 WIN_HEIGHT);
	lst->py += 3;
	lst->pdx -= lst->pdx;
	lst->pdy -= lst->pdy;
	render(lst->list, lst, 0);
	mlx_put_image_to_window(lst->mlx, lst->windows,\
		lst->list->img, 0, 0);
}


int	key_press(int key, t_data  *lst)
{
	if (key == 53  || key == 17)
		exit (1);
	else if (key == 0)
		move_right(lst);
	else if (key == 2)
		move_left(lst);
	else if (key == 13)
		move_forward(lst);
	else if (key == 1)
		move_back(lst);
	return (0);
}
int	close_windows_red_cross()
{
	exit (1);
	return (0);
}