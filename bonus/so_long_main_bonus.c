/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:46:58 by ahkecha           #+#    #+#             */
/*   Updated: 2022/02/16 17:37:23 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_press(int keycode, t_map *map)
{
	if (keycode == ESCAPE_KEY)
	{
		mlx_destroy_window(map->mlx.mlx, map->mlx.win);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == D_KEY || keycode == RIGHT_KEY)
		go_right(map, 1);
	else if (keycode == A_KEY || keycode == LEFT_KEY)
		go_left(map, -1);
	else if (keycode == W_KEY || keycode == UP_KEY)
		go_up(map, -1);
	else if (keycode == S_KEY || keycode == DOWN_KEY)
		go_down(map, 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac < 2)
		arerr();
	is_exist(av[1]);
	if (!(check_extentions(av[1])))
		ext_error();
	check_content(av[1]);
	readmap(&map, av[1]);
	check_components(&map);
	map.mlx.mlx = mlx_init();
	map.mlx.win = mlx_new_window(map.mlx.mlx, map.img.width * 70, map.img.height
			* 70, "so_long");
	render_bg(&map);
	parse_map(&map, "./textures/portal.xpm");
	player_position(&map);
	mlx_hook(map.mlx.win, 2, 1L << 0, key_press, &map);
	mlx_hook(map.mlx.win, 17, 1L << 17, quit, &map);
	mlx_loop(map.mlx.mlx);
}
