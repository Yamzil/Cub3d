/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:58:45 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/17 19:02:05 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    s_data  *lst;

    lst = malloc(sizeof(s_data));
    if (!lst)
        return (0);
    if (ac == 2){
        //check_arg();
        //check_file();
        //get_data();
        //math
        check_map(av);
    }
}