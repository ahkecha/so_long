/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:37:54 by ahkecha           #+#    #+#             */
/*   Updated: 2021/12/26 18:39:05 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "minilibx/mlx.h"
#include <fcntl.h>
#include <unistd.h>
#include "libft/libft.h"
// #include "gnl/get_next_line.h"

# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2;
# define ESCAPE_KEY 53;
# define FILE_ERR "Error:\n Map not found"
# define EXT_ERR "Error:\n Map must be .ber"
# define FAIL_ERR "Error:\n Failed to read map"



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
	char	**map;
	int		empty;
	int		emerald;
	int		start;
	int		exit;
	int		walls;
	int		coll;
	int		dif;
	int		rows;
	int		player;

}	t_map;

typedef struct t_mlx
{
	void	*mlx;
	void	*win;
	int		x_len;
	int		y_len;
	int		x_player;
	int		y_player;
	t_map	map;
	t_img	*img;
}	t_mlx;

typedef struct s_plr
{
	int		moves;
	int		current;
	int		f_x;
	int		f_y;
	int		c_x;
	int		c_y;
}	t_plr;

//erros functions
void	f_map_error(void);
void	ext_error(void);
void	fail_err(void);

//map functions
void	count_chars(t_map *map, char c);


// miscellaneous
void	ft_free(char **str);

#endif
