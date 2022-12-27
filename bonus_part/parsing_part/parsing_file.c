/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:47:23 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/26 15:55:02 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int parsing_path(t_data *lst)
{
    int count;
    int i;
    int	j;

    count = 0;
    i = 0;
    while(lst->file[i])
    {
        if (!ft_strncmp(lst->file[i], "NO ", 3) && dupli(lst, 0))
            count++;
        else if (!ft_strncmp(lst->file[i], "SO ", 3) && dupli(lst, 1))
            count++;
        else if (!ft_strncmp(lst->file[i], "WE ", 3) && dupli(lst, 2))
            count++;
        else if(!ft_strncmp(lst->file[i], "EA ", 3) && dupli(lst, 3))
            count++;
        i++;
    }
    if (count != 4)
        parsing_error(lst, 0);
	else
		storing_path(lst, &j);
    return (0);
}

int	parsing_floor(t_data *lst)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (lst->file[i])
	{
		if (!ft_strncmp(lst->file[i], "F ", 2))
		{
			mx(&lst->begin, i);
			count++;
		}
		i++;
	}
	if (count != 1)
		parsing_error(lst, 1);
	return (0);
}

int	parsing_ceilling(t_data *lst)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (lst->file[i])
	{
		if (!ft_strncmp(lst->file[i], "C ", 2))
		{
			mx(&lst->begin, i);
			count++;
		}
		i++;
	}
	if (count != 1)
		parsing_error(lst, 1);
	return (0);
}

char	**getting_color_floor(t_data *lst)
{
	char	**color;
	char	*str;
	int		i;

	i = 0;
	color = NULL;
	if (!checking_color_floor(lst))
	{
		while (lst->file[i])
		{
			if (ft_strchr(lst->file[i], 'F'))
			{
				str = ft_strdup(lst->file[i]);
				lst->file[i] =  ft_strtrim(str, "F \n");
				free(str);
				color = ft_split(lst->file[i], ','); // here allocate
			}
			i++;
		}
	}
	i = -1;
	while (color[++i]);
	if (i != 3)
		parsing_error(lst, 3);
	return (color);
}

char	**getting_color_ceilling(t_data *lst)  
{
	char	**color;
	int		i;

	i = 0;
	color = NULL;
	if (!checking_color_ceilling(lst))
	{
		while (lst->file[i])
		{
			if (ft_strchr(lst->file[i], 'C'))
			{
				lst->file[i] =  ft_strtrim(lst->file[i], "C \n");
				color = ft_split(lst->file[i], ',');
			}
			i++;
		}
	}
	i = -1;
	while (color[++i]);
	if (i != 3)
		parsing_error(lst, 4);
	return (color);
}