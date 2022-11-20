/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:40:10 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/20 09:59:33 by yamzil           ###   ########.fr       */
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
	fd = open(av[1], O_RDONLY, 0777);
	if (!lst->file)
		return (NULL);
	i = 0;
	while (1) 
	{
		char	*tmp;
		tmp = get_next_line(fd);
		if (tmp)
		{	
			if (ft_strcmp(tmp, "\n"))
				lst->file[i++] = tmp;
		}
			if (tmp == 0)
				break ;	
	}
	lst->file[i] = NULL;
	return (lst->file);
}

char	**get_map(s_data *lst, int j)
{	
	int	i;
	int	l;

	l = j;
	while(lst->file[l++]);
	lst->map = malloc(sizeof(char *) * (l - j));
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