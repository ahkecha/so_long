/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_longs_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:34:57 by ahkecha           #+#    #+#             */
/*   Updated: 2022/02/16 18:08:23 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_charcount(t_map *map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map->map[i] != NULL && i <= map->img.height - 1)
	{
		j = 0;
		while (map->map[i][j] != '\0' && j <= map->img.width - 1)
		{
			if (map->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	count_steps(t_map *map)
{
	map->steps += 1;
	ft_putnbr_fd(map->steps, 1);
	ft_putstr_fd("\n", 1);
}

void	vsync(t_map *map)
{
	mlx_clear_window(map->mlx.mlx, map->mlx.win);
	render_bg(map);
	parse_map(map, "./textures/woodblock.xpm");
	player_position(map);
	count_steps(map);
}

void	vsync_with_exit(t_map *map)
{
	mlx_clear_window(map->mlx.mlx, map->mlx.win);
	render_bg(map);
	parse_map(map, "./textures/portal.xpm");
	player_position(map);
	count_steps(map);
}

int	quit(int a)
{
	(void)a;
	exit(EXIT_SUCCESS);
	return (0);
}
