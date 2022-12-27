/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:48:40 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/27 19:14:19 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	key_press(t_data *lst)
{
	mlx_destroy_image(lst->mlx, lst->li->img);
	lst->li->img = mlx_new_image(lst->mlx, WIN_WIDTH, WIN_HEIGHT);
	check_player_position(lst);
	render(lst, 0);
	mlx_put_image_to_window(lst->mlx, lst->windows, lst->li->img, 0, 0);
	return (0);
}

int	key_start(int key, t_data *lst)
{
	if (key == ESCHAP)
	{
		free_paths(lst);
		free_all(lst->map);
		free(lst->player);
		free(lst);
		exit (0);
	}
	else if (key == LEFT_ARROW)
		lst->player->rotate_cam = -1;
	else if (key == RIGHT_ARROW)
		lst->player->rotate_cam = 1;
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

int	key_realse(int key, t_data *lst)
{
	if (key == LEFT_ARROW)
		lst->player->rotate_cam = 0;
	else if (key == RIGHT_ARROW)
		lst->player->rotate_cam = 0;
	else if (key == LEFT)
		lst->player->move_a_d = 0;
	else if (key == RIGHT)
		lst->player->move_a_d = 0;
	else if (key == FORWARD)
		lst->player->move_w_s = 0;
	else if (key == BACKWARD)
		lst->player->move_w_s = 0;
	return (0);
}

int	close_win(t_data *data)
{
	if (data)
		exit(0);
	return (0);
}
