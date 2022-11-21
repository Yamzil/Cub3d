/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:58:45 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/21 19:28:56 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>

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
    s_data  *lst;

    lst = malloc(sizeof(s_data));
    if (!lst)
        return (0);
    if (ac == 2)
	{
        check_extension(ac, av);
        get_file(lst, av);
		check_file(av, lst);
    }
}

// HEAP OVERFLOW WITH SANITIZE WHEN FOUND AN EMPTY LINE // otherwise everythihg woking fine
// RAY CASTING ISSUE