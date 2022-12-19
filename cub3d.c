/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:42:48 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/17 11:27:41 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_functions(t_data *lst, t_map *list)
{
	lst->mlx =  mlx_init ();
	lst->windows = mlx_new_window(lst->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	list->img = mlx_new_image(lst->mlx, WIN_WIDTH, \
		 WIN_HEIGHT);
	list->addr = mlx_get_data_addr(list->img, &list->bits, &list->size,&list->end);
	mlx_hook(lst->windows, 2, 0, key_start, lst);
	mlx_hook(lst->windows, 3, 0, key_realse, lst);
	mlx_hook(lst->windows, 17, 0, close_win, lst);
	mlx_loop_hook (lst->mlx , key_press, lst);
}

void	init_values(t_data *lst)
{
	lst->begin = 0;
	lst->step = 1;
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
		t_data  	lst;
		t_map		list;
		t_txtdata	txt;

		lst.player = malloc(sizeof(t_player));
		if (!lst.player)
			return (0);
		check_extension(ac, av);
		get_file(&lst, av);
		check_storing_file_data(&lst);
		check_map(&lst);
		get_map(&lst);
		init_values(&lst);
		mlx_functions(&lst, &list);
		lst.list = &list;
		txt.data.img = mlx_xpm_file_to_image(lst.mlx, lst.north, &txt.width, &txt.height);
		txt.addr = (int *)mlx_get_data_addr(txt.data.img, &txt.data.bits, &txt.data.size, &txt.data.end);
		lst.txt = &txt;
		render(&list, &lst, 1, &txt);
		mlx_put_image_to_window(lst.mlx, lst.windows,\
		lst.list->img, 0, 0);
		mlx_loop(lst.mlx);
	}
}
