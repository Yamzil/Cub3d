/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:42:48 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/26 18:18:06 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_values(t_data *lst)
{
	lst->begin = 0;
	lst->step = 2;
	lst->angle = player_direction(lst);
	lst->player->rotate_cam = 0;
	lst->player->move_a_d = 0;
	lst->player->move_w_s = 0;
	ft_memset(lst->arr, 0, sizeof(lst->arr));
	lst->arr->addr = NULL;
}

void	check_extension(t_data *data, int ac, char **av)
{
	size_t	i;

	i = ft_strlen(av[1]);
	if (ac == 2)
	{
		if (av[1][i - 1] != 'b' || av[1][i - 2] != 'u' || av[1][i - 3] != 'c'
			|| av[1][i - 4] != '.')
		{
			free(data->player);
			free(data);
			write(2, "Error in extension \n", 21);
			exit (0);
		}
	}
}

// void fun()
// {
// 	system("leaks cub3D");
// }

int	main(int ac, char **av)
{
	t_data	*data;
	t_map	l;
	// atexit(fun);
	if (ac != 2)
	{
		ft_putendl_fd("Incorrect numbers of arguments", 2);
		exit (0);
	}
	else
	{
		data = malloc(sizeof(t_data));
		if (!data)
			return (0);
		data->player = malloc(sizeof(t_player));
		if (!data->player)
			return (0);
		check_extension(data, ac, av);
		get_file(data, av);
		check_storing_file_data(data);
		check_map(data);
		get_map(data);
		init_values(data);
		mlx_functions(data, &l);
		data->li = &l;
		render(&l, data, 1);
		mlx_put_image_to_window(data->mlx, data->windows, data->li->img, 0, 0);
		mlx_loop(data->mlx);
	}
}
