/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mouvement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:12:30 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/27 21:50:22 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	player_position(t_data *data)
// {

// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (data->map[i])
// 	{
// 		j = 0;
// 		while (data->map[i][j])
// 		{
// 			if (data->map[i][j] == 'N' || data->map[i][j] == 'S' 
// 				|| data->map[i][j] == 'W' || data->map[i][j] == 'E')
// 			{
// 				printf("%d--%d", i, j);
// 				exit(0);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
	
// }

void    init_player_coordination(t_player *player)
{
    player->raduis = 3;
    player->move = 0;
    player->turn = 0;
    player->rotions = M_PI / 2;
    player->speed = 3.0;
    player->rotion_speed = 2 * (M_PI / 180);
}

void	render_player(t_player *player, t_map *map, t_data *data)
{
	(void) data;
	// player_position(data);
	init_player_coordination(player);
	writing_pxl_to_img(map, player->x, player->y, 14335);
}
