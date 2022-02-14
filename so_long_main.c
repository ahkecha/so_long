/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:46:58 by ahkecha           #+#    #+#             */
/*   Updated: 2022/02/14 18:57:17 by ahkecha          ###   ########.fr       */
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
	else if (keycode == D_KEY)
		go_right(map, 1);
	else if(keycode == A_KEY)
		go_left(map, -1);
	else if(keycode == W_KEY)
		go_up(map, -1);
	else if(keycode == S_KEY)
		go_down(map, 1);
}

int	main(int ac, char **av)
{
	t_map map;
	if (ac < 2)
	{
		ft_putendl_fd("Error\nNot enough arguments", 2);
		exit(EXIT_FAILURE);
	}
	is_exist(av[1]);
	if (!(check_extentions(av[1])))
	{
		ft_putendl_fd(EXT_ERR, 2);
		exit(EXIT_FAILURE);
	}

	check_content(av[1]);
	readmap(&map, av[1]);
	map.mlx.mlx = mlx_init();
	map.mlx.win = mlx_new_window(map.mlx.mlx, map.img.width * 70, map.img.height * 70, "test");
	// parse_xpm(&map);
	// player_position(&map);
	// printf("%d %d\n", map.img.width, map.img.height);
	render_bg(&map);
	parse_map(&map);
	// render_player(&map, 100, 100);
	player_position(&map);

	mlx_hook(map.mlx.win, 2, 1L<<0, key_press, &map);
	mlx_hook(map.mlx.win, 17, 1L<<17, quit, &map);
	mlx_loop(map.mlx.mlx);

}
