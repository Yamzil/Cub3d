/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:44:24 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/24 15:08:55 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	countline(t_data *lst, char **av)
{
	int		count;
	char	*map;
	int		fd;

	fd = open(av[1], O_RDONLY, 0777);
	map = get_next_line(fd);
	count = 0;
	while (map)
	{
		count++;
		map = get_next_line(fd);
	}
	lst->end = count;
}

char	**get_file(t_data *lst,char **av)
{
	int		fd;
	int		i;

	countline(lst, av);
	lst->file = malloc((lst->end + 1) * sizeof(char *));
	if (!lst->file)
		return (NULL);
	fd = open(av[1], O_RDONLY, 0777);
	i = 0;
	while (true) 
	{
		char	*tmp = get_next_line(fd);
		lst->file[i] = tmp;
		if (lst->file[i] == 0)
			break ;
		i++;
	}
	lst->file[i] = NULL;
	return (lst->file);
}