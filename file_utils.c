/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:40:10 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/21 15:51:44 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	countline(char **av)
{
	int		count;
	char	*map;
	int		fd;

	fd = open(av[1], O_RDONLY, 0777);
	map = get_next_line(fd);
	count = 0;
	while (map)
	{
		map = get_next_line(fd);
		count++;
	}
	return count;
}

char	**get_file(s_data *lst,char **av)
{
	int		line;
	int		fd;
	int		i;

	line = countline(av);
	lst->file = malloc((line + 1) * sizeof(char *));
	if (!lst->file)
		return (NULL);
	fd = open(av[1], O_RDONLY, 0777);
	i = 0;
	while (true) 
	{
		char	*tmp = get_next_line(fd);
		lst->file[i] = tmp;
		if (lst->file[i] == '\0')
			break ;
		i++;
	}
	lst->file[i] = NULL;
	return (lst->file);
}

char	**get_map(s_data *lst, int j)
{
	int	i;
	int	k;

	k = 0;
	while (lst->file[k]){
		k++;
	}
	if (k > j)
		lst->map = malloc(sizeof(char *) * (k - j));
	if (!lst->map)
		return (NULL);
	i = 0;
	while (lst->file[j]) 
	{
		lst->map[i] = lst->file[j];
		j++;
		i++;
	}
	lst->map[i] = NULL;
	return (lst->map);
}