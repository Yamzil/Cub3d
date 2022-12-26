/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:25:08 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/25 22:08:18 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int check_storing_file_data(t_data *lst)
{
    parsing_path(lst);
	parsing_floor(lst);
	parsing_ceilling(lst);
    storing_colors_ceilling(lst);
    storing_colors_floor(lst);
    return (0);
}

void    check_map( t_data *lst)
{
	check_last_line(lst);
	check_valid(lst);
	valid_map_elements(lst);
	valid_player(lst);
	valid_player_position(lst);
}