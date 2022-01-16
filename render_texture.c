/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:54:34 by ahkecha           #+#    #+#             */
/*   Updated: 2022/01/16 14:20:00 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall(t_map *map)
{
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->walls,
		map->j * 100, map->i * 100);
}

void	player(t_map *map)
{
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->player,
		map->j * 100, map->i * 100);
}

void	coll(t_map *map)
{
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->emerald,
		map->j * 100, map->i * 100);
}

void	exit(t_map *map)
{
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->exit,
		map->j * 100, map->i * 100);
}

void	path(t_map *map)
{
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win,
		map->map_path, map->j * 100, map->i * 100);
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
