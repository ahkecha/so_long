/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:54:34 by ahkecha           #+#    #+#             */
/*   Updated: 2022/02/15 15:44:48 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

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
			render_img(map, i, j, "./textures/woodblock.xpm");
			j++;
		}
		i++;
		j = 0;
	}
}

void	render_img(t_map *map, int i, int j, char *path)
{
	int height;
	int width;

	height = 70;
	width = 70;

	map->img.ptr = mlx_xpm_file_to_image(map->mlx.mlx, path, &width, &height);
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->img.ptr, j * 70, i * 70);
	mlx_destroy_image(map->mlx.mlx, map->img.ptr);
}

int		parse_map(t_map *map, char	*exit)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->img.height)
	{
		while (j < map->img.width)
		{
			if (map->map[i][j] == '1')
				render_img(map, i, j, "./textures/obsidian.xpm");
			else if (map->map[i][j] == 'P')
				render_img(map, i, j, "./textures/steve.xpm");
			else if (map->map[i][j] == 'C')
				render_img(map, i, j, "./textures/eyeofender.xpm");
			else if (map->map[i][j] == 'E')
				render_img(map, i, j, exit);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

void	player_position(t_map *map)
{
	int i;
	int j;

	i = 0;
	while(map->map[i] != NULL && i <= map->img.height - 1)
	{
		j = 0;
		while(map->map[i][j] != '\0' && j <= map->img.width - 1)
		{
			if (map->map[i][j] == 'P')
			{
				map->playerx = j;
				map->playery = i;
			}
			j++;
		}
		i++;
	}
}
