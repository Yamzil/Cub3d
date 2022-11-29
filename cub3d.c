/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:42:48 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/29 17:32:39 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_functions(t_data *lst, t_map *list)
{
	lst->mlx =  mlx_init ();
	lst->windows = mlx_new_window(lst->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	list->img = mlx_new_image(lst->mlx, WIN_WIDTH, WIN_HEIGHT);
	list->address = mlx_get_data_addr(list->img, &list->bits_per_pxl, &list->size_line, &list->endian);
	mlx_hook(lst->windows, 2, 0, key_realse, lst);
	mlx_hook(lst->windows, 2, 0, key_press, lst);

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
		// t_player	player;

		lst.begin = 0;
		lst.angle = 3 * M_PI / 2;
		lst.step = 2;
		check_extension(ac, av);
		get_file(&lst, av);
		check_storing_file_data(&lst);
		check_map(&lst);
		get_map(&lst);
		mlx_functions(&lst, &list);
		lst.list = &list;
		render(&list, &lst, 1);
		mlx_put_image_to_window(lst.mlx, lst.windows, list.img, 0, 0);
		mlx_loop(lst.mlx);

	}
}
