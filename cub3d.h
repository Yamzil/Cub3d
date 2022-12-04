/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:58:48 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/04 23:58:39 by yamzil           ###   ########.fr       */
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
#define SQUARE_SIZE 10
#define PLAYER_SQUARE 5
#define WHITE 16777215
#define BLACK 8421504
#define BLUE 14335

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
typedef struct s_player{
	double	px;
	double	py;
	int 	rotate_cam;
	int		move_w_s;
	int		move_a_d;
}t_player;

typedef struct s_map{
	void	*img;
	char	*address;
	int		bits_per_pxl;
	int		size_line;
	int		endian;
} t_map;

typedef struct s_ray{
	double	fov_angle;
	double	ray_x;
	double	ray_y;
	int		numbers_rays;
	int		increament_rays;
	int		rayCasting;
}t_ray;

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
	t_map		*list;
	t_player	*player;
	t_ray		*rays;
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
// MINIMAP
void	writing_pxl_to_img(t_map *list, int x, int y, int color);
void    render(t_map *lst, t_data *data, int flag);

// PLAYER
void	draw_player(t_map *lst, int x, int y, int color);
void	check_player_position(t_data *lst);

// DDA
void    dda_algo(t_data *data, double x1, double y1);

// RAYCASTING
bool	check_wall(t_data *data, double x, double y);
void	horizental_inter(t_data *data);
void	vertical_inter(t_data *data);

// RAYCASTING UTILS
double	sanitize_angle(t_data *data);
bool	rayisdown(t_data *data);
bool	rayisup(t_data *data);
bool	rayisright(t_data *data);
bool	rayisleft(t_data *data);
#endif