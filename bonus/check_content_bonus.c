/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:41:02 by ahkecha           #+#    #+#             */
/*   Updated: 2022/02/18 13:19:03 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>

int	check_components(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->img.height)
	{
		while (j < map->img.width)
		{
			if (map->map[i][j] != 'P' && map->map[i][j] != 'C' &&
				map->map[i][j] != 'E' && map->map[i][j] != '1' &&
				map->map[i][j] != '0')
				arerr();
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int	count_components(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->img.height - 1)
	{
		j = 0;
		while (j < map->img.width - 1)
		{
			if (map->map[i][j] == 'P')
				map->p += 1;
			if (map->map[i][j] == 'C')
				map->c += 1;
			if (map->map[i][j] == 'E')
				map->e += 1;
			j++;
		}
		i++;
		j = 0;
	}
	if (map->e < 1 || map->p != 1 || map->c < 1)
		return (0);
	return (1);
}

int	check_shape(t_map *map)
{
	int	len2;
	int	len;

	len = ft_strlen(map->map[0]);
	len2 = map->img.height;
	if (len != len2)
		return (1);
	return (0);
}

int	check_closed(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->img.width - 1)
	{
		if (map->map[0][i] != '1' || map->map[map->img.height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map->img.height - 1)
	{
		if (map->map[i][0] != '1' || map->map[i][map->img.width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	init_check(t_map *map)
{
	check_components(map);
	if (!(count_components(map)))
		errmap();
	if (!(check_shape(map)))
		errmap();
	if (!(check_closed(map)))
		errmap();
}
