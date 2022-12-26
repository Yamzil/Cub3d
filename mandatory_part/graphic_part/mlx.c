/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:41:28 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/26 12:07:37 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	mlx_functions(t_data *lst, t_map *list)
{
	lst->mlx = mlx_init();
	if (!lst->mlx)
		exit(EXIT_FAILURE);
	lst->windows = mlx_new_window(lst->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!lst->windows)
		exit(EXIT_FAILURE);
	list->img = mlx_new_image(lst->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!list->img)
		exit(EXIT_FAILURE);
	list->addr = mlx_get_data_addr(list->img, &list->bits, &list->size,&list->end);
	loading_textures(lst);
	mlx_hook(lst->windows, 2, 0, key_start, lst);
	mlx_hook(lst->windows, 3, 0, key_realse, lst);
	mlx_hook(lst->windows, 17, 0, close_win, lst);
	mlx_loop_hook(lst->mlx , key_press, lst);
}
