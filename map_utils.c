/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:53:51 by yamzil            #+#    #+#             */
/*   Updated: 2022/11/21 22:37:07 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_valid(char **av, s_data *lst, int *j)
{
    int k;
	int	count;

	count = countline(av);
	*j = no_map(av, lst, count, *j);
	printf("%d", *j);
    while (*j < count - 1  && lst->file[*j])
    {
		k = 0;
		// while (lst->file[*j] && !ft_strncmp(lst->file[*j], "\n", 2))
		// 	j++;
		check_one(*j, count);
		while (lst->file[*j] && lst->file[*j][k])
		{
			if (lst->file[*j][k] == '0')
			{
				if (k < (int)ft_strlen(lst->file[*j + 1]) 
					|| k < (int)ft_strlen(lst->file[*j - 1]))
				{
					if (check_char(lst->file[*j][k - 1]))
						error_msg(0);
					else if (check_char(lst->file[*j][k + 1]))
						error_msg(0);
					else if (check_char(lst->file[*j - 1][k]))
						error_msg(0);
					else if (check_char(lst->file[*j + 1][k]))
						error_msg(0);
				}
			}
			k++;
		}
        j++;
    }
	check_two(lst, *j);
}

// void	valid_map_elements(char **av, s_data *lst, int j)
// {
// 	int	k;
// 	int	count;

// 	count = countline(av);
// 	j = no_map(av, lst, count, j);
// 	while (j < count - 1 && lst->file[j])
// 	{
// 		k = 0;
// 		while (lst->file[j] && !ft_strncmp(lst->file[j], "\n", 2))
// 			j++;
// 		check_one(j, count);
// 		while (lst->file[j] && lst->file[j][k]) 
// 		{
// 			if (lst->file[j][k] != '0' && lst->file[j][k] != '1' 
// 				&& lst->file[j][k] != 'N' && lst->file[j][k] != 'S' 
// 				&& lst->file[j][k] != 'W' && lst->file[j][k] != 'E' 
// 				&& lst->file[j][k] != ' ' && lst->file[j][k] != '\n')
// 				error_msg(1);
// 			k++;
// 		}
// 		j++;
// 	}
// 	check_two(lst, j);
// }

// void	valid_player(char **av, s_data *lst, int j)
// {
// 	int	player;
// 	int	count;
// 	int	k;

// 	player = 0;
// 	count = countline(av);
// 	no_map(av, lst, count, j);
// 	while (j < count - 1 && lst->file[j])
// 	{
// 		k = 0;
// 		while (lst->file[j] && !ft_strncmp(lst->file[j], "\n", 2))
// 			j++;
// 		check_one(j, count);
// 		while (lst->file[j] && lst->file[j][k])
// 		{
// 			if (lst->file[j][k] == 'N' || lst->file[j][k] == 'S' 
// 				|| lst->file[j][k] == 'W' || lst->file[j][k] == 'E')
// 				player++;
// 			k++;
// 		}
// 		j++;
// 	}
// 	check_two(lst, j);
// 	if (player != 1)
// 		error_msg(2);
// }

// void	valid_player_sourrnder(char **av, s_data *lst, int j)
// {
// 	int	count;
// 	int	k;

// 	count = countline(av);
// 	no_map(av, lst, count, j);
// 	while (j < count - 1 && lst->file[j])
// 	{
// 		k = 0;
// 		while(lst->file[j] && !ft_strncmp(lst->file[j], "\n", 2))
// 			j++;
// 		check_one(j, count);
// 		while (lst->file[j] && lst->file[j][k])
// 		{
// 			if (lst->file[j][k] == 'N' || lst->file[j][k] == 'S' || lst->file[j][k] == 'W' || lst->file[j][k] == 'E')
// 			{
// 				if ((lst->file[j][k + 1] != '0' || lst->file[j][k - 1] != '0') && (lst->file[j][k + 1] != '1' || lst->file[j][k - 1] != '1') && (lst->file[j + 1][k] != '0' || lst->file[j - 1][k] != '0') && (lst->file[j - 1][k] != '1' || lst->file[j + 1][k] != '1'))
// 					error_msg(2);
// 			}
// 			k++;
// 		}
// 		j++;
// 	}
// 	check_two(lst, j);
// }