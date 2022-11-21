/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:34:27 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/21 18:37:21 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	no_map(char **av, s_data *lst, int count, int j)
{
	count = countline(av);
	if (j < count - 1)
	{
		if (!ft_strncmp(lst->file[j], "C", 1))
			j++;
	}
	else 
	{
		write (2, "Error no map\n", 14);
		exit (1);
	}
	return (j);
}

void    check_one(int j, int count)
{
    if (j == count - 1)
    {
        write (2, "Error no map\n", 14);
		exit (1);
    }
}

void    check_two(s_data *lst, int j)
{
    if (lst->file[j - 1] == NULL)
	{
		write (2, "Error no map\n", 14);
		exit (1);
	}
}