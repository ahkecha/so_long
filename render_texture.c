/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:54:34 by ahkecha           #+#    #+#             */
/*   Updated: 2022/01/16 14:12:00 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall(int i, int j, t_map *map)
{
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->walls,
		j * 100, i * 100);
}

void	player(int i, int j, t_map *map)
{
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->player,
		j * 100, i * 100);
}

void	coll(int i, int j, t_map *map)
{
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->emerald,
		j * 100, i * 100);
}

void	exit(int i, int j, t_map *map)
{
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->exit,
		j * 100, i * 100);
}

void	path(int i, int j, t_map *map)
{
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win,
		map->map_path, j * 100, i * 100);
}

void	parse_xpm(t_map *map)
{
	map->tex_bg = "./assets/bg.xpm";
	map->bg = mlx_xpm_file_to_image(map->mlx.mlx, map->tex_bg, &map->i, &map->j);
	map->tex_emerald = "./assets/emerald.xpm";
	map->emerald = mlx_xpm_file_to_image(map->mlx.mlx, map->tex_emerald, &map->i, &map->j);
	map->tex_wall = "./assets/walls.xpm";
	map->walls = mlx_xpm_file_to_image(map->mlx.mlx, map->tex_wall, &map->i, &map->j);
	map->tex_exit = "./assets/exit.xpm";
	map->exit = mlx_xpm_file_to_image(map->mlx.mlx, map->tex_exit, &map->i, &map->j);
}
