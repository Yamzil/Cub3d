/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:06:50 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/18 18:12:34 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_duplicate_path(s_data *lst)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (lst->file[i])
	{
		if (!ft_strncmp(lst->file[i], "NO", 2) && check_dup(0))
			count++;
		else if (!ft_strncmp(lst->file[i], "SO", 2) && check_dup(1))
			count++;
		else if (!ft_strncmp(lst->file[i], "WE", 2) && check_dup(2))
			count++;
		else if (!ft_strncmp(lst->file[i], "EA", 2) && check_dup(3))
			count++;
		i++;
	}
	if (count != 4)
	{
		write(2, "Missing a path\n", 16);
		return (1);
	}
	return (0);
}

int	checkspace(s_data *lst)
{
	int	i;

	i = 0;
	while (lst->file[i])
	{
		if (!ft_strncmp(lst->file[i], "NO", 2))
			found_space(lst->file[i][2]);
		else if (!ft_strncmp(lst->file[i], "SO", 2))
			found_space(lst->file[i][2]);
		else if (!ft_strncmp(lst->file[i], "WE", 2))
			found_space(lst->file[i][2]);
		else if (!ft_strncmp(lst->file[i], "EA", 2))
			found_space(lst->file[i][2]);
		i++;
	}
	return (0);
}
