/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:00:39 by ahkecha           #+#    #+#             */
/*   Updated: 2022/02/15 15:52:05 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	go_right(t_map *map, int w)
{
	int	i;
	int	j;

	i = map->playerx;
	j = map->playery;
	if (map->map[j][i + w] == 'E' && ft_charcount(map) == 0)
	{
		map->map[j][i + w] = 'E';
		map->map[j][i] = '0';
		vsync_with_exit(map);
		winexit();

	}
	if (map->map[j][i + w] == '0' || map->map[j][i + w] == 'C')
	{
		map->map[j][i + w] = 'P';
		map->map[j][i] = '0';
		vsync(map);
	}
}

void	go_left(t_map *map, int w)
{
	int	i;
	int	j;

	i = map->playerx;
	j = map->playery;
	if (map->map[j][i + w] == 'E' && ft_charcount(map) == 0)
	{
		map->map[i][i + w] = 'E';
		map->map[j][i] = '0';
		vsync_with_exit(map);
		winexit();
	}
	if (map->map[j][i + w] == '0' || map->map[j][i + w] == 'C')
	{
		map->map[j][i + w] = 'P';
		map->map[j][i] = '0';
		vsync(map);
	}
}

void	go_up(t_map *map, int w)
{
	int	i;
	int	j;

	i = map->playerx;
	j = map->playery;
	if (map->map[j + w][i] == 'E' && ft_charcount(map) == 0)
	{
		map->map[j + w][i] = 'E';
		map->map[j][i] = '0';
		vsync_with_exit(map);
		winexit();

	}
	if (map->map[j + w][i] == '0' || map->map[j + w][i] == 'C')
	{
		map->map[j + w][i] = 'P';
		map->map[j][i] = '0';
		vsync(map);
	}
}

void	go_down(t_map *map, int w)
{
	int	i;
	int	j;

	i = map->playerx;
	j = map->playery;
	if (map->map[j + w][i] == 'E' && ft_charcount(map) == 0)
	{
		map->map[j + w][i] = 'E';
		map->map[j][i] = '0';
		vsync_with_exit(map);
		winexit();

	}
	if (map->map[j + w][i] == '0' || map->map[j + w][i] == 'C')
	{
		map->map[j + w][i] = 'P';
		map->map[j][i] = '0';
		vsync(map);
	}
}



