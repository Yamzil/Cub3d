/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:56:13 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/21 21:04:07 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void    parsing_error(int i)
{
    if (i == 0)
    {
        ft_putendl_fd("Error: Incorrect numbers of textures", 2);
        exit (0);
    }
    else if (i == 1)
    {
        ft_putendl_fd("Error: Floor or ceilling is missing", 2);
        exit(0);
    }
    else if (i == 2)
    {
        ft_putendl_fd("Error: cannot open the path", 2);
        exit (0);
    }
    else if (i == 3)
    {
        ft_putendl_fd("Error: incorrect floor's arguments", 2);
        exit (0);
    }
    else if (i == 4)
    {
        ft_putendl_fd("Error: incorrect ceilling's arguments", 2);
        exit (0);
    }
}

void    map_error(int i)
{
    if (i == 0)
    {
        ft_putendl_fd("Error: Invalid data with empty space", 2);
        exit (0);
    }
    else if (i == 1)
    {
        ft_putendl_fd("Error: Imposter elements", 2);
        exit (0);
    }
    else if (i == 2)
    {
        ft_putendl_fd("Error: Invalid player", 2);
        exit (0);
    }
}