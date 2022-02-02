/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:54:34 by ahkecha           #+#    #+#             */
/*   Updated: 2022/02/02 12:14:40 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
void	wall(t_map *map, int i, int j)
{
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->walls,
		j * 70, i * 70);
}

void	player(t_map *map, int i, int j)
{
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->player,
		j * 70, i * 70);
}

void	coll(t_map *map, int i, int j)
{
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->emerald,
		j * 70, i * 70);
}

void	exits(t_map *map, int i, int j)
{
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->exit,
		j * 70, i * 70);
}

void	bg(t_map *map, int i, int j)
{
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win,
		map->bg, j * 70, i * 70);
}

void	parse_xpm(t_map *map)
{
	map->tex_bg = "./textures/woodblock.xpm";
	map->bg = mlx_xpm_file_to_image(map->mlx.mlx, map->tex_bg, &map->i, &map->j);
	map->tex_emerald = "./textures/eyeofender.xpm";
	map->emerald = mlx_xpm_file_to_image(map->mlx.mlx, map->tex_emerald, &map->i, &map->j);
	map->tex_wall = "./textures/obsidian.xpm";
	map->walls = mlx_xpm_file_to_image(map->mlx.mlx, map->tex_wall, &map->i, &map->j);
	map->tex_exit = "./textures/portal.xpm";
	map->exit = mlx_xpm_file_to_image(map->mlx.mlx, map->tex_exit, &map->i, &map->j);
}

void	render_bg(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->img.height)
	{
		while (j < map->img.width - 1)
		{
			bg(map, i, j);
			j++;
			printf("j: %d\n", j);
		}
		i++;
		j = 0;
	}
}

void	render_player(t_map *map, int i, int j)
{
	char	*plr;

	plr = "./textures/steve.xpm";
	map->plr_x = i;
	map->plr_y = j;
	map->player = mlx_xpm_file_to_image(map->mlx.mlx, plr, &map->i, &map->j);
	player(map, i, j);
	mlx_destroy_image(map->mlx.mlx, map->player);
}
