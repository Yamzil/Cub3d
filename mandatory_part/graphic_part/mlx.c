/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <mjlem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:41:28 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/27 23:10:48 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	mlx_functions(t_data *lst, t_map *l)
{
	if (WIN_WIDTH > 2000 || WIN_HEIGHT > 2000
		|| WIN_HEIGHT < 0 || WIN_WIDTH < 0)
		exit(EXIT_FAILURE);
	lst->mlx = mlx_init();
	if (!lst->mlx)
		exit(EXIT_FAILURE);
	lst->windows = mlx_new_window(lst->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!lst->windows)
		exit(EXIT_FAILURE);
	l->img = mlx_new_image(lst->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!l->img)
		exit(EXIT_FAILURE);
	l->addr = mlx_get_data_addr(l->img, &l->bits, &l->size, &l->end);
	loading_textures(lst);
	mlx_hook(lst->windows, 2, 0, key_start, lst);
	mlx_hook(lst->windows, 3, 0, key_realse, lst);
	mlx_hook(lst->windows, 17, 0, close_win, lst);
	mlx_loop_hook(lst->mlx, key_press, lst);
}
