/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:57:24 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/18 18:11:58 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int found_space(char c)
{
    if (c != ' ')
    {
        write(2, "No space has been found\n", 25);
        return 1;
    }
    return 0;
}

int check_dup(int i){
    static int flag[4] = {};
    
    if (flag[i])
    {
        printf("duplicate path \n");
        exit(1);
    }
    flag[i] = 1;
    return 1;
}