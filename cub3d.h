/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:58:48 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/17 12:51:48 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <unistd.h>
#include "./minilibx_opengl_20191021/mlx.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/fcntl.h>
#include "get_next_line/get_next_line.h"

#define WIN_HEIGHT 720
#define WIN_WIDTH 1080
#define TILE_SIZE 10
#define PLAYER_SQUARE 5
#define WHITE 16777215
#define BLACK 8421504
#define BLUE 33023
#define RAD (M_PI / (double)180) 

enum{
	RED_CROSS = 17,
	ESCHAP = 53,
	LEFT_ARROW = 123,
	RIGHT_ARROW = 124,
	FORWARD = 13,
	BACKWARD = 1,
	LEFT = 0,
	RIGHT = 2,
};

typedef struct s_cast {
    double	xstep;
    double	ystep;
    double	xA;
    double	yA;
    double	deg;
    double	hwallX;
    double	hwallY;
    double	vxstep;
    double	vystep;
    double	vxA;
    double	vyA;
    double	vwallX;
    double	vwallY;
    double	vdis;
    double	hdis;
    double	dis;
    double	wx;
    double	wy;
    double	dpp;
    double	wallHeight;
	double	TopPixel;
	double	BotPixel;
	bool	vertical_inter;
	bool	horizontal_inter;
} t_cast; 

typedef struct s_player{
	double	px;
	double	py;
	int 	rotate_cam;
	int		move_w_s;
	int		move_a_d;
}t_player;

typedef struct s_map{
	void	*img;
	char	*addr;
	int		bits;
	int		size;
	int		end;
} t_map;

typedef struct s_txtdata
{
	t_map	data;
	int		height;
	int		width;
	int		*addr;
	double  xofset;
    double  yofset;
} t_txtdata;

typedef struct s_texture
{
	t_txtdata	*north;
	t_txtdata	*south;
	t_txtdata	*west;
	t_txtdata	*east;
} t_texture;
typedef struct s_data{
	char		**file;
	char		**map;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	int			floor;
	int			ceilling;
	int			begin;
	int			end;
	void		*mlx;
	void		*windows;
	int			step;
	double		angle;
	int			img_width;
	int			img_height;
	t_map		*list;
	t_player	*player;
	t_txtdata	*txt;
}t_data;

// LIBFT
int     ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
void	*ft_memset(void *b, int c, size_t len);
char	**ft_split(char const *s, char c);
void	ft_putendl_fd(char *s, int fd);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *s1);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
char	*ft_itoa(int n);

// AllOCATE FILE
char	**get_file(t_data *lst,char **av);
void	countline(t_data *lst, char **av);
char	**get_map(t_data *lst);

// MAIN
void	messages_error(int i);
void	error_msg(int i);

// GET NEXT LINE
char    *get_next_line(int fd);

// PARSING FILE
char	**getting_color_ceilling(t_data *lst);
char	**getting_color_floor(t_data *lst);
int		parsing_ceilling(t_data *lst);
int		parsing_floor(t_data *lst);
int		parsing_path(t_data *lst);

// PARSING ERROR
void    parsing_error(int i);
void    map_error(int i);

// PARSING UTILS
int		checking_color_ceilling(t_data *lst);
int		checking_color_floor(t_data *lst);
void	check_ver(t_data *lst, int i);
int		mx(int *j, int i);
int		check_dup(int i);

// STORING DATA
int		storing_colors_ceilling(t_data *lst);
int		storing_path(t_data *lst, int *j);
int		storing_colors_floor(t_data *lst);

// CHECK FILE
int		check_storing_file_data(t_data *lst);

// CHECK MAP
int		valid_player_position(t_data *lst);
int		valid_map_elements(t_data *lst);
int		check_last_line(t_data *lst);
int		valid_player(t_data *lst);
int		check_valid(t_data *lst);
void    check_map(t_data *lst);

// CHECK MAP UTILS
void	checking_player_position(t_data *lst, int i);
void    check_valid_util(t_data *lst, int i, int j);
void	check_player_util(t_data *lst, int i);
bool	check_char(char c);

// HOOK UTILS
int		key_realse(int key, t_data *lst);
int		key_start(int key, t_data  *lst);
int		key_press(t_data *lst);
int		close_win(void *param);

// MINIMAP
void	writing_pxl_to_img(t_map *list, int x, int y, int color);
void    render(t_map *lst, t_data *data, int flag, t_txtdata *txt);

// PLAYER
void	draw_player(t_map *lst, int x, int y, int color);
char	map_direction(t_data *data);
void	check_player_position(t_data *lst);
void	get_playerposition(t_data *data);
double 	player_direction(t_data *data);

// DDA
void    dda_algo(t_data *data, double x1, double y1);

// RAYCASTING
// void    draw_wall(t_cast *info, double  x, t_map *lst, t_data *data);
void    draw_wall(t_cast *info, double  x, t_map *lst, t_data *data, t_txtdata *txt);
// void	draw_line(int x1, int y1, int y2, t_map *lst,t_data *data);
// void 	draw_line(int x1, int y1, int y2, t_map *lst,t_data *data, t_cast *info);
void draw_line(int x1, int y1, int y2, t_map *lst,t_data *data, t_cast *info, t_txtdata *txt);
void	raycast(t_cast *info, t_data *data);
// void	draw_fov(t_data *data, t_map *lst);
void	draw_fov(t_data *data, t_map *lst, t_txtdata *txt);


// RAYCASTING UTILS
bool	check_wall(t_data *data, double x, double y);
double  check_deg(double deg);
int		arr_len(char **map);

// HORIZONTAL INTERSECTION
void	find_hor_point(t_cast *info, t_data *data);
void	find_hor_inter(t_cast *info, t_data *data);
void	find_hor_step(t_cast *info);

// VERTICAL INTERSECTION
void	find_ver_inter(t_cast   *info, t_data *data);
void	find_ver_point(t_cast *info, t_data *data);
void	find_ver_step(t_cast *info);

// DISTANCE
double	distance(double x1, double y1, double x2, double y2);
void	find_dis(t_cast *info);

// DRAW FLOOR AND CEILLING
void	draw_celling(int x1, int y1, t_map *lst, t_data *data);
void	draw_floor(int x1, int y1, t_map *lst, t_data *data);

void	writing_pxl_to_img2(t_map *list, int x, int y, t_txtdata *txt);
void	texture(t_cast *info, double y1, t_txtdata *txt);

#endif