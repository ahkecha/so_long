/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:41:02 by ahkecha           #+#    #+#             */
/*   Updated: 2022/02/16 15:46:07 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int check_components(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < map->img.height)
	{
		while (j < map->img.width)
		{
			if (map->map[i][j] != 'P' && map->map[i][j] != 'C' \
			 && map->map[i][j] != 'E'&& map->map[i][j] != '1' \
			 && map->map[i][j] != '0')
			 	arerr();
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

// int		count_components(t_map *map)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	while (i < map->img.height)
// 	{
// 		while (j < map->img.width)
// 		{
// 			if (map->map[i][j] == 'P')
// 				map->p += 1;
// 			if (map->map[i][j] == 'C')
// 				map->c += 1;
// 			if (map->map[i][j] == 'E')
// 				map->e += 1;
// 			j++;
// 		}
// 		i++;
// 		j = 0;
// 	}
// 	if (map->e < 1 || map->p != 1 || map->c < 1)
// 		return (0);
// 	return (1);
// }


