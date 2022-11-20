/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:57:24 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/20 17:13:19 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_char(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'W' && c != 'E' && c != 'S')
		return true;
	return false;
}

int found_space(char c)
{
    if (c != ' ')
    {
        write(2, "No space has been found\n", 25);
        exit (1);
    }
    return 0;
}

int check_dup(int i){
    static int flag[4] = {};

    if (flag[i])
    {
        write (2, "duplicate path\n", 15);
        exit(1);
    }
    flag[i] = 1;
    return 1;
}

void	check_ver(s_data *lst, int i)
{
    int	count;
    int j;

    j = 0;
	count = 0;
    while (lst->file[i][j])
	{
		if (lst->file[i][j] == ',')
			count++;
		j++;
	}
	if (count != 2)
    {
        write(2, "Error in floor or ceilling arguments\n", 38);
		exit (1);
    } 
}

void    valid_rgb(char **str, int i)
{
    int j;

    j = 0;
    while (str[i][j])
    {
        if (str[i][j] >= '0' && str[i][j] <= '9')
        {
            if (ft_atoi(str[i]) < 0 || ft_atoi(str[i]) > 255)
            {
                write(2, "Rgb color out of bounds\n", 25);
                exit (1);
            }
        }
        else 
        {
            write (2, "Detecting a no digit number\n", 29);
            exit(1);
        }
        j++;
    }
}