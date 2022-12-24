/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:42:48 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/22 13:08:28 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdlib.h>

void	mlx_functions(t_data *lst, t_map *list)
{
	lst->mlx =  mlx_init ();
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
	mlx_loop_hook (lst->mlx , key_press, lst);
}

void	init_values(t_data *lst)
{
	lst->begin = 0;
	lst->step = 2;
	lst->angle = player_direction(lst);
	lst->player->rotate_cam = 0;
	lst->player->move_a_d  = 0;
	lst->player->move_w_s = 0;
}

void    check_extension(int ac, char **av)
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

int main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putendl_fd("Incorrect numbers of arguments", 2);
		exit (0);
	}
	else 
	{
		t_data  	*data;
		t_map		list;

		data = malloc(sizeof(t_data));
		if (!data)
			return 0;
		data->player = malloc(sizeof(t_player));
		if (!data->player)
			return (0);
		check_extension(ac, av);
		get_file(data, av);
		check_storing_file_data(data);
		check_map(data);
		get_map(data);
		init_values(data);
		mlx_functions(data, &list);
		data->list = &list;
		render(&list, data, 1);
		mlx_put_image_to_window(data->mlx, data->windows,\
		data->list->img, 0, 0);
		mlx_loop(data->mlx);
	}
}
