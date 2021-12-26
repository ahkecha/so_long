/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:37:54 by ahkecha           #+#    #+#             */
/*   Updated: 2021/12/26 18:00:15 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "minilibx/mlx.h"
#include <fcntl.h>
#include <unistd.h>

# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2;
# define ESCAPE_KEY 53;


typedef struct s_img
{
	void	*up;
	void	*down;
	void	*left;
	void	*right;
	void	*bg;
	void	*addr;
	void	*ptr;
	int		lenght;
	int		endian;
	int		height;
	int		width;
}	t_img;

typedef struct s_map
{
	int		x;
	int		y;
	int		collectible;
	char	**map
}	t_map;

typedef struct t_mlx
{
	void	*mlx;
	void	*win;
	int		x_len;
	int		y_len;
	int		x_player;
	int		y_player;
	t_map	*map;
	t_img	*img;
}	t_mlx;


#endif
