/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <mjlem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:44:24 by yamzil            #+#    #+#             */
/*   Updated: 2022/12/27 23:10:48 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
		free(map);
		count++;
		map = get_next_line(fd);
	}
	lst->end = count;
}

char	**get_file(t_data *lst, char **av)
{
	char	*tmp;
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
		tmp = get_next_line(fd);
		lst->file[i] = tmp;
		if (lst->file[i] == 0)
			break ;
		i++;
	}
	lst->file[i] = NULL;
	return (lst->file);
}

char	**get_map(t_data *lst)
{
	int	i;
	int	j;

	i = lst->begin;
	j = 0;
	lst->map = malloc((((lst->end) - lst->begin) + 1) * sizeof(char *));
	if (!lst->map)
		return (NULL);
	while (lst->file[i])
	{
		if (lst->file[i] && !ft_strncmp(lst->file[i], "\n", 2))
			i++;
		lst->map[j] = ft_strdup(lst->file[i]);
		j++;
		i++;
	}
	lst->map[j] = NULL;
	free_all(lst->file);
	return (lst->map);
}
