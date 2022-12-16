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
    double hwallX;
    double hwallY;
    double vxstep;
    double vystep;
    double vxA;
    double vyA;
    double vwallX;
    double vwallY;
    double vdis;
    double hdis;
    double dis;
    double wx;
    double wy;
    double dpp;
    double wallHeight;
} t_cast; 

double distance(double x1, double y1, double x2, double y2){
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void    find_ver_inter(t_cast   *info, t_data *data){
    info->vxA = (int)(data->player->px / TILE_SIZE) * TILE_SIZE;
    if (info->deg < (M_PI / 2) || info->deg > ((3 * M_PI )/ 2)) // ray is right
        info->vxA += TILE_SIZE;
    info->vyA = data->player->py + ((info->vxA - data->player->px)  * tan(info->deg));
    // printf("yA = %f && xA = %f\n", info->vyA, info->vxA);
}

void    find_ver_step(t_cast   *info){

    info->vxstep = TILE_SIZE;
    if (info->deg > (M_PI / 2) && info->deg < ((3 * M_PI )/ 2)) // ray is left
        info->vxstep *= -1;
    info->vystep = TILE_SIZE * tan(info->deg);
    if ((info->deg > M_PI && info->deg < (2 * M_PI) && info->vystep > 0) || (info->deg < M_PI && info->deg > 0 && info->vystep < 0)) // ray is up and step is postive or ray is down and step negative
        info->vystep *= -1;
    // printf("xstep = %f && ystep %f\n", info->vxstep, info->vystep);
}

void    find_ver_point(t_cast   *info, t_data *data){
    double tmpX;
    double tmpY;
    bool flag = false;

    tmpX = info->vxA;
    tmpY = info->vyA;
    if (info->deg > (M_PI / 2) && info->deg < ((3 * M_PI )/ 2))
    {
        flag = true;
        tmpX--;
    }
    while (tmpX < WIN_WIDTH && tmpY < WIN_HEIGHT && tmpX >= 0 && tmpY >= 0 && !check_wall(data, tmpX, tmpY))
    {
        tmpX += info->vxstep;
        tmpY += info->vystep;
    }
    if(flag)
        tmpX++;
    info->vwallX = tmpX;
    info->vwallY = tmpY;
    // printf("wallX = %f, WallY = %f\n", tmpX, tmpY);
    info->vdis = distance(data->player->px, data->player->py, info->vwallX, info->vwallY);
    // printf("vdis = %f\n", info->vdis);
}

void    find_hor_inter(t_cast   *info, t_data *data){
    info->yA = (int)(data->player->py / TILE_SIZE) * TILE_SIZE;
    if (info->deg < M_PI && info->deg > 0) // ray is down
        info->yA += TILE_SIZE;
    info->xA = data->player->px + ((info->yA - data->player->py) / tan(info->deg)); 
    // printf("yA = %f && xA = %f\n", info->yA, info->xA);
}

void    find_hor_step(t_cast   *info){

    info->ystep = TILE_SIZE;
    if (info->deg > M_PI && info->deg < (2 * M_PI)) //ray is up
        info->ystep *= -1;

    info->xstep = TILE_SIZE / tan(info->deg);
    if (((info->deg > (M_PI / 2) && info->deg < ((3 * M_PI )/ 2)) && info->xstep > 0) // ray is left
     || ((info->deg < (M_PI / 2) || info->deg > ((3 * M_PI )/ 2)) && info->xstep < 0)){// ray is right
        info->xstep *= -1;
    }
    // printf("xstep = %f && ystep %f\n", info->xstep, info->ystep);
}

void    find_hor_point(t_cast   *info, t_data *data){
    double tmpX;
    double tmpY;
    bool flag = false;

    tmpX = info->xA;
    tmpY = info->yA;
    if (info->deg > M_PI && info->deg < (2 * M_PI))
    {
        flag = true;
        tmpY--;
    }
    while (tmpX < WIN_WIDTH && tmpY < WIN_HEIGHT && tmpX >= 0 && tmpY >= 0 && !check_wall(data, tmpX, tmpY))
    {
        tmpX += info->xstep;
        tmpY += info->ystep;
    }
    info->hwallX = tmpX;
    if (flag)
        tmpY++;
    info->hwallY = tmpY;
    // printf("wallX = %f, WallY = %f\n", tmpX, tmpY);
    info->hdis = distance(data->player->px, data->player->py, info->hwallX, info->hwallY);
    // printf("hdis = %f\n", info->hdis);
}

void    find_dis(t_cast *info){
    if (info->vdis > info->hdis)
    {
        info->wx = info->hwallX;
        info->wy = info->hwallY;
        info->dis = info->hdis;
    }
    else
    {
        info->wx = info->vwallX;
        info->wy = info->vwallY;
        info->dis = info->vdis;
    }
}

void    raycast(t_cast   *info, t_data *data){
    find_hor_inter(info, data);
    find_hor_step(info);
    find_hor_point(info, data);
    find_ver_inter(info, data);
    find_ver_step(info);
    find_ver_point(info, data);
    find_dis(info);
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

double  check_deg(double deg){
    if (deg < 0)
        deg *= -1;
    if (deg >  (2 * M_PI))
        deg -= (2 * M_PI);
    return deg;
}

void    draw_celling(int x1, int y1,t_map *lst,t_data *data){
    int i;

    i = 0;
    while (i < y1)
    {
        writing_pxl_to_img(lst, x1, i, data->ceilling);
        i++;
    }
}

void    draw_floor(int x1, int y1,t_map *lst,t_data *data){

    while (y1+1 < WIN_HEIGHT)
    {
        writing_pxl_to_img(lst, x1, y1, data->floor);
        y1++;
    }
}

void draw_line(int x1, int y1, int y2, t_map *lst,t_data *data){
    // printf("x1 = %d && y1 = %d && y2 = %d\n", x1, y1, y2);
    if (y1 < 0)
        y1 = 0;
    else
        draw_celling(x1, y1, lst, data);
    if (y2 >= WIN_HEIGHT)
        y2 = WIN_HEIGHT - 1;
    else
        draw_floor(x1, y2, lst, data);
    while(y1 <= y2){
        writing_pxl_to_img(lst, x1, y1, BLUE);
        y1++;
    }
}

void    draw_wall(t_cast *info, double  x, t_map *lst, t_data *data){
    double y;
    double deg = data->angle;

    deg = fmod(deg , (2 * M_PI));
    if (deg < 0)
        deg = (2 * M_PI) + deg;
    info->wallHeight = (TILE_SIZE / (info->dis * cos(deg - info->deg))) * info->dpp;
    // printf("wall height = %f && dis = %f\n", info->wallHeight, info->dis);
    y = (WIN_HEIGHT - info->wallHeight) / 2;
    draw_line(x, y, WIN_HEIGHT - y, lst, data);
}

void    draw_fov(t_data *data, t_map *lst){
    t_cast  info;
    double deg = data->angle - (30 * RAD);
    double incr = (((double)60  * RAD) / (double)WIN_WIDTH);
    info.dpp = (WIN_WIDTH / 2) * tan(30 * RAD);
    // printf("dpp = %f\n", info.dpp);
    int i = 0;
    /*  */
    // (void)lst;
    while (i < WIN_WIDTH)
    { 
        deg = fmod(deg , (2 * M_PI));
        if (deg < 0)
            deg = (2 * M_PI) + deg;
        info.deg = deg;
        // printf("player x = %f && player y = %f && deg = %f\n", data->player->px, data->player->py, deg);
        raycast(&info, data);
        // printf("deg = %f && WallX = %f && wallY = %f\n", deg, info.wallX, info.wallY);
        // dda_algo(data, data->player->px + cos(deg) * WIN_WIDTH,data->player->py + sin(deg) * WIN_WIDTH);
        // dda_algo(data, info.wx, info.wy);
        // dda_algo(data, info.hwallX, info.hwallY);
        // dda_algo(data, info.vwallX, info.vwallY);
        draw_wall(&info, i, lst,data);
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
			x += TILE_SIZE;
			j++;	
        }
		y  += TILE_SIZE; 
		i++;
    }
    // draw_player(lst, data->player->px, data->player->py, BLUE);
    draw_fov(data, lst);
    // dda_algo(data, data->player->px + cos(data->angle) * WIN_WIDTH,data->player->py + sin(data->angle) * WIN_WIDTH);
}
