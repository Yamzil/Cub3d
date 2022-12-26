/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 21:12:16 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/26 12:26:49 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void    free_all(char **temp)
{
    int i;

    i = 0;
    while (temp[i])
    {
        free(temp[i]);
        i++;
    }
    free(temp);
    temp = NULL;
}

void    free_tab(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
    str = NULL;
}

void    free_paths(t_data *data)
{
    free(data->north);
    free(data->south);
    free(data->west);
    free(data->east);
}