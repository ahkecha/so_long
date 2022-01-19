/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:46:58 by ahkecha           #+#    #+#             */
/*   Updated: 2022/01/19 15:03:53 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		key_press(int keycode, t_map *map)
{
	if (keycode == ESCAPE_KEY)
	{
		mlx_destroy_window(map->mlx.mlx, map->mlx.win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_map map;

	readmap(&map, av[1]);
	map.mlx.mlx = mlx_init();
	map.mlx.win = mlx_new_window(map.mlx.mlx, map.img.width * 70, map.img.height * 70, "test");
	// printf("%d\n%d\n", map.img.height, map.img.width);
	parse_xpm(&map);
	// mlx_put_image_to_window(map.mlx.mlx, map.mlx.win,
	// 	map.bg, 100, 100);
	render_bg(&map);
	parse_map(&map);
	render_player(&map, 100, 100);
	mlx_hook(map.mlx.win, 2, 1L<<0, key_press, &map);
	mlx_loop(map.mlx.mlx);
}
