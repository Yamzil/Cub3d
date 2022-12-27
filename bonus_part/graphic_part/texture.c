#include "../../cub3d.h"

void	writing_pxl_to_img2(t_map *list, int x, int y, t_data *data)
{
	char	*adr;
	int		color;

    list->addr = mlx_get_data_addr(list->img, &list->bits, &list->size,&list->end);
    adr = list->addr + (y * list->size + x * (list->bits / 8));
	color = data->arr[data->ti].addr[(int)(data->arr[data->ti].yofset * data->arr[data->ti].width + data->arr[data->ti].xofset)];
    *(unsigned int *) adr = color;
}

void	texture(t_data *data, t_cast *info, double y1)
{
	int		distance_top;
    double  xofset;
    double  yofset;
	double	y;

	y = y1;
	xofset = 0.0;
	data->ti = choose_texture(info);
    if (info->horizontal_inter)
		xofset = ((info->wx - ((int)(info->wx / TILE_SIZE) * TILE_SIZE)) * data->arr[data->ti].width) / TILE_SIZE;
	else if (info->vertical_inter)
		xofset = ((info->wy - ((int)(info->wy / TILE_SIZE) * TILE_SIZE)) * data->arr[data->ti].width) / TILE_SIZE;
	distance_top = y + (info->wallHeight / 2) - ((double)WIN_HEIGHT / 2);
	yofset = distance_top * data->arr[data->ti].height / info->wallHeight;
	data->arr[data->ti].xofset = abs((int)xofset);
	data->arr[data->ti].yofset = abs((int)yofset);
}

void	loading_textures(t_data *r)
{
	r->arr[NORTH].img = mlx_xpm_file_to_image(r->mlx, r->north, &r->arr[NORTH].width,&r->arr[NORTH].height);
	r->arr[SOUTH].img = mlx_xpm_file_to_image(r->mlx, r->south, &r->arr[SOUTH].width,&r->arr[SOUTH].height);
	r->arr[WEST].img = mlx_xpm_file_to_image(r->mlx, r->west, &r->arr[WEST].width,&r->arr[WEST].height);
	r->arr[EAST].img = mlx_xpm_file_to_image(r->mlx, r->east, &r->arr[EAST].width,&r->arr[EAST].height);
	r->da[0].img = mlx_xpm_file_to_image(r->mlx, "texture/F0.xpm", &r->da[0].width,&r->da[0].height);
	r->da[1].img = mlx_xpm_file_to_image(r->mlx, "texture/F1.xpm", &r->da[1].width,&r->da[1].height);
	r->da[2].img = mlx_xpm_file_to_image(r->mlx, "texture/F2.xpm", &r->da[2].width,&r->da[2].height);
	r->da[3].img = mlx_xpm_file_to_image(r->mlx, "texture/F3.xpm", &r->da[3].width,&r->da[3].height);
	r->da[4].img = mlx_xpm_file_to_image(r->mlx, "texture/F4.xpm", &r->da[4].width,&r->da[4].height);
	r->da[5].img = mlx_xpm_file_to_image(r->mlx, "texture/F5.xpm", &r->da[5].width,&r->da[5].height);
	r->da[6].img = mlx_xpm_file_to_image(r->mlx, "texture/F6.xpm", &r->da[6].width,&r->da[6].height);
	r->arr[NORTH].addr = (int *)mlx_get_data_addr(r->arr[NORTH].img, &r->arr[NORTH].bits,&r->arr[NORTH].size,&r->arr[NORTH].end);
	r->arr[SOUTH].addr = (int *)mlx_get_data_addr(r->arr[SOUTH].img, &r->arr[SOUTH].bits,&r->arr[SOUTH].size,&r->arr[SOUTH].end);
	r->arr[WEST].addr = (int *)mlx_get_data_addr(r->arr[WEST].img , &r->arr[WEST].bits,&r->arr[WEST].size,&r->arr[WEST].end);
	r->arr[EAST].addr = (int *)mlx_get_data_addr(r->arr[EAST].img, &r->arr[EAST].bits,&r->arr[EAST].size,&r->arr[EAST].end);
	r->da[0].addr = (int *)mlx_get_data_addr(r->da[0].img, &r->da[0].bits,&r->da[0].size,&r->da[0].end);
	r->da[1].addr = (int *)mlx_get_data_addr(r->da[1].img, &r->da[1].bits,&r->da[1].size,&r->da[1].end);
	r->da[2].addr = (int *)mlx_get_data_addr(r->da[2].img, &r->da[2].bits,&r->da[2].size,&r->da[2].end);
	r->da[3].addr = (int *)mlx_get_data_addr(r->da[3].img, &r->da[3].bits,&r->da[3].size,&r->da[3].end);
	r->da[4].addr = (int *)mlx_get_data_addr(r->da[4].img, &r->da[4].bits,&r->da[4].size,&r->da[4].end);
	r->da[5].addr = (int *)mlx_get_data_addr(r->da[5].img, &r->da[5].bits,&r->da[5].size,&r->da[5].end);
	r->da[6].addr = (int *)mlx_get_data_addr(r->da[6].img, &r->da[6].bits,&r->da[6].size,&r->da[6].end);
}

int	choose_texture(t_cast *info)
{
	info->deg = fmod(info->deg , (2 * M_PI));
	if (info->deg < 0)
		info->deg = (2 * M_PI) + info->deg;
	if (info->vertical_inter)
	{
		if (info->deg > M_PI / 2 && info->deg < 3 * M_PI / 2)
			return (WEST);
		else
			return (EAST);
	}
	if (info->horizontal_inter)
	{
		if (info->deg > 0 && info->deg < M_PI)
			return (SOUTH);
		else
			return (NORTH);
	}
	return -1;
}