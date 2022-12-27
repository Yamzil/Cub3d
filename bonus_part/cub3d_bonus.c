/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <mjlem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:20:00 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/27 23:07:32 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <stdlib.h>

int	mouse_move(int x, int y, t_data *lst)
{
	if (x > (WIN_WIDTH / 2) + 100)
		lst->p->rotate_cam = 1;
	else if (x < (WIN_WIDTH / 2) - 100)
		lst->p->rotate_cam = -1;
	else
		lst->p->rotate_cam = 0;
	y = 0;
	return (0);
}

void	mlx_functions(t_data *lst, t_map *l)
{
	if (WIN_WIDTH > 2000 || WIN_HEIGHT > 2000
		|| WIN_HEIGHT < 0 || WIN_WIDTH < 0)
		exit(EXIT_FAILURE);
	lst->mlx = mlx_init ();
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
	mlx_hook(lst->windows, 6, 0, mouse_move, lst);
	mlx_hook(lst->windows, 3, 0, key_realse, lst);
	mlx_hook(lst->windows, 17, 0, close_win, lst);
	mlx_loop_hook (lst->mlx, key_press, lst);
}

void	init_values(t_data *lst)
{
	lst->begin = 0;
	lst->step = 2;
	lst->angle = player_direction(lst);
	lst->p->rotate_cam = 0;
	lst->p->move_a_d = 0;
	lst->p->move_w_s = 0;
	lst->door_dst = 0;
}

void	check_extension(int ac, char **av)
{
	size_t	len;

	len = ft_strlen(av[1]);
	if (ac == 2)
	{
		if (av[1][len - 1] != 'b' || av[1][len - 2] != 'u'
			|| av[1][len - 3] != 'c' || av[1][len - 4] != '.')
			write(2, "Error in extension \n", 21);
	}
}

int	main(int ac, char **av)
{
	t_data	*data;
	t_map	list;

	if (ac != 2)
	{
		ft_putendl_fd("Incorrect numbers of arguments", 2);
		exit (0);
	}
	else
	{
		data = malloc(sizeof(t_data));
		data->p = malloc(sizeof(t_player));
		check_extension(ac, av);
		get_file(data, av);
		check_storing_file_data(data);
		check_map(data);
		get_map(data);
		init_values(data);
		mlx_functions(data, &list);
		data->li = &list;
		render(&list, data, 1);
		mlx_put_image_to_window(data->mlx, data->windows, data->li->img, 0, 0);
		mlx_loop(data->mlx);
	}
}
