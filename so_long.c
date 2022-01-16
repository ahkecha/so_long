/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:11:18 by ahkecha           #+#    #+#             */
/*   Updated: 2022/01/05 17:32:16 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
# define ESCAPE_KEY 53
# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2


typedef struct	s_vars {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		i;
	int		j;
	void	*img2
}				t_vars;


void go_right(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->mlx_win);
	vars->i += 32;
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, vars->i, vars->j);
}

void	go_left(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->mlx_win);
	vars->i -= 32;
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, vars->i, vars->j);
}

void	go_up(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->mlx_win);
	vars->j -= 32;
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, vars->i, vars->j);
}

void	go_down(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->mlx_win);
	vars->j += 32;
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, vars->i, vars->j);
}

int		key_press(int keycode, t_vars *vars)
{

	if (keycode == ESCAPE_KEY)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == D_KEY)
		go_right(vars);
	if (keycode == A_KEY)
		go_left(vars);
	if (keycode == W_KEY)
		go_up(vars);
	if (keycode == S_KEY)
		go_down(vars);
}


// int		move_image(int keycode, t_vars *vars, t_img *img)
int		main(void)
{
	t_vars vars;
	char	*path = "./amethyst.xpm";
	char	*path2 = "./nether_block.xpm";
	int		img_width;
	int		img_height;


	vars.i = 0;
	vars.j = 0;
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 640, 240, "test");
	vars.img = mlx_xpm_file_to_image(vars.mlx, path, &img_height, &img_width);
	vars.img2 = mlx_xpm_file_to_image(vars.mlx, path2, &img_height, &img_width);
	// vars.img = mlx_xpm_file_to_image(vars.mlx, path2, &img_height, &img_width);
	// printf("%dx%d", img_height, img_width);
	vars.addr =  mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length,
								&vars.endian);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img, vars.i, vars.j);
	// mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img2, 4, 4)
	// mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img, 0, 0);
	mlx_hook(vars.mlx_win, 2, 1L<<0, key_press, &vars);
	mlx_loop(vars.mlx);
}
