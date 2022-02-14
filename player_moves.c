/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:00:39 by ahkecha           #+#    #+#             */
/*   Updated: 2022/02/14 18:56:47 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	go_up(t_map *map)
// {
// 	int	i;
// 	int	j;

// 	i = map->plr_x;
// 	j = map->plr_y;
// 	if (map->map[i - 1][j] == '0')
// 	{
// 		ft_swap(&map->map[i - 1][j], &map->map[i][j]);
// 		map->player--;
// 		rerender(map, i, j);
// 	}
// 	else if (map->map[i - 1][j] == 'C')
// 	{
// 		map->coll--;
// 		map->map[i][j] = '0';
// 		map->map[i - 1][j] = 'P';
// 		map->plr_x--;
// 		rerender(map, i, j);
// 	}
// }

void	go_right(t_map *map, int w)
{
	int	i;
	int	j;

	i = map->playerx;
	j = map->playery;
	if (map->map[j][i + w] == '0' || map->map[j][i + w] == 'C')
	{
		map->map[j][i + w] = 'P';
		map->map[j][i] = '0';
		mlx_clear_window(map->mlx.mlx, map->mlx.win);
		render_bg(map);
		parse_map(map);
		player_position(map);
	}
}

void	go_left(t_map *map, int w)
{
	int	i;
	int	j;

	i = map->playerx;
	j = map->playery;
	if (map->map[j][i + w] == '0' || map->map[j][i + w] == 'C')
	{
		map->map[j][i + w] = 'P';
		map->map[j][i] = '0';
		mlx_clear_window(map->mlx.mlx, map->mlx.win);
		render_bg(map);
		parse_map(map);
		player_position(map);
	}
}

void	go_up(t_map *map, int w)
{
	int	i;
	int	j;

	i = map->playerx;
	j = map->playery;
	if (map->map[j + w][i] == '0' || map->map[j + w][i] == 'C')
	{
		map->map[j + w][i] = 'P';
		map->map[j][i] = '0';
		mlx_clear_window(map->mlx.mlx, map->mlx.win);
		render_bg(map);
		parse_map(map);
		player_position(map);
	}
}

void	go_down(t_map *map, int w)
{
	int	i;
	int	j;

	i = map->playerx;
	j = map->playery;
	if (map->map[j + w][i] == '0' || map->map[j + w][i] == 'C')
	{
		map->map[j + w][i] = 'P';
		map->map[j][i] = '0';
		mlx_clear_window(map->mlx.mlx, map->mlx.win);
		render_bg(map);
		parse_map(map);
		player_position(map);
	}
}



