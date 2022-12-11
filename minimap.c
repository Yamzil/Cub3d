/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:02:20 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/05 22:42:45 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct s_cast {
    double xstep;
    double ystep;
    double xA;
    double yA;
    double deg;
    double     wallX;
    double     wallY;
} t_cast; 


void    find_hor_inter(t_cast   *info, t_data *data){
    info->yA = (int)(data->player->py / TILE_SIZE) * TILE_SIZE;
    info->xA = data->player->px + ((data->player->py - (double)info->yA) / tan(info->deg));
    printf("yA = %f && xA = %f\n", info->yA, info->xA);
}

void    find_hor_step(t_cast   *info){
    info->ystep = -1 * TILE_SIZE;
    info->xstep = TILE_SIZE / tan(info->deg);
    // if (info->deg > (M_PI / 2) && info->deg < ((3 * M_PI )/ 2)){
    //     printf("deg = %f\n", info->deg);
        info->xstep *= -1;
    // }
    printf("xstep = %f && ystep %f\n", info->xstep, info->ystep);
}

void    find_hor_point(t_cast   *info, t_data *data){
    double tmpX;
    double tmpY;

    tmpX = info->xA;
    tmpY = info->yA;
    while (!check_wall(data, tmpX, tmpY))
    {
        tmpX += info->xstep;
        tmpY += info->ystep;
    }
    info->wallX = tmpX;
    info->wallY = tmpY;
    printf("wallX = %f, WallY = %f\n", tmpX, tmpY);
}

void    raycast(t_cast   *info, t_data *data){
    find_hor_inter(info, data);
    find_hor_step(info);
    find_hor_point(info, data);
}


void	writing_pxl_to_img(t_map *list, int x, int y, int color)
{
	char	*adr;
    adr = list->address + (y *  list->size_line + x * (list->bits_per_pxl / 8));
    *(unsigned int *) adr = color; 
}

void    draw_square(t_map *lst, int x, int y, int color)
{
    int i;
	int	j;

    i = 0;
    while (i < TILE_SIZE)
    {
        j = 0;
        while (j < TILE_SIZE)
        {
			writing_pxl_to_img(lst, x + i, y + j, color);
			j++;	
        }
		i++;
    }
}

void    draw_fov(t_data *data){
    t_cast  info;
    double deg = data->angle - (30 * RAD);
    double incr = (((double)60  * RAD) / (double)WIN_WIDTH);
    int i = 0;
    /*  */
    while (i < WIN_WIDTH)
    { 
        info.deg = deg;
        printf("player x = %f && player y = %f\n", data->player->px, data->player->py);
        raycast(&info, data);
        printf("deg = %f && WallX = %f && wallY = %f\n", deg, info.wallX, info.wallY);
        // dda_algo(data, data->player->px + cos(deg) * WIN_WIDTH,data->player->py + sin(deg) * WIN_WIDTH);
        dda_algo(data, info.wallX, info.wallY);
        deg += incr;
        i++;
    }
}

void    render(t_map *lst, t_data *data, int flag)
{
    int i;
	int	j;
	int x;
	int y;
		
    i = 0;
    y = 0;
    while (data->map[i])
    {
        j = 0;
		x = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == '0' || data->map[i][j] == 'N')
                draw_square(lst, x, y, WHITE);
			if (data->map[i][j] == '1')
				draw_square(lst, x , y, BLACK);
            if (flag && data->map[i][j] == 'N')
            {
                data->player->px = x;
                data->player->py = y;
            }
			x += 10;
			j++;	
        }
		y  += 10; 
		i++;
    }
    draw_player(lst, data->player->px, data->player->py, BLUE);
    draw_fov(data);
    // dda_algo(data, data->player->px + cos(data->angle) * WIN_WIDTH,data->player->py + sin(data->angle) * WIN_WIDTH);
}
