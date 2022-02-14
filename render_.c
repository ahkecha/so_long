/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:48:43 by ahkecha           #+#    #+#             */
/*   Updated: 2022/02/14 17:02:50 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	mupdate(t_map *map, int x, int y)
// {
// 	int	i;
// 	int	j;

// 	i = map->plr_x;
// 	j = map->plr_y;
// 	if (map->map[x][y] == 'E' || map->map[x][y] == 'G')
// 	{
// 		map->map[x][y] = 'E';
// 		map->map[i][j] = 'P';
// 	}
// 	else
// 	{
// 		map->map[x][y] = '0';
// 		if (map->map[i][j] == 'E')
// 			map->map[i][j] = 'G';
// 		else
// 			map->map[i][j] = 'P';
// 	}
// 	return (0);
// }

// void	rerender(t_map *map, int x, int y)
// {
// 	int	i;
// 	int	j;

// 	i = map->plr_x;
// 	j = map->plr_y;
// 	if (map->map[x][y] == 'E' || map->map[x][y] == 'G')
// 	{
// 		player(map, i, j);
// 		wall(map, x ,y);
// 		bg(map, x, y);
// 		exits(map, x, y);
// 	}
// 	else
// 	{
// 		bg(map, x, y);
// 		if (map->map[x][y] == 'E')
// 		{
// 			bg(map,x ,y);
// 			exits(map, x, y);
// 		}
// 		else
// 			player(map, i, j);
// 	}
// }
