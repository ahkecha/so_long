/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:37:54 by ahkecha           #+#    #+#             */
/*   Updated: 2022/01/16 14:13:19 by ahkecha          ###   ########.fr       */
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
	int		i;
	int		j;
	void	*map_path;
	char	**map;
	int		empty;
	void	*emerald;
	int		start;
	void	*exit;
	int		*exit2;
	void	*walls;
	int		coll;
	int		dif;
	int		rows;
	int		*player;
	int		*bg;
	char	*tex_bg;
	char	*tex_wall;
	char	*tex_emerald;
	char	*tex_exit;
	t_mlx	mlx;
	t_img	img;

}	t_map;

typedef struct t_mlx
{
	void	*mlx;
	void	*win;
	int		x_len;
	int		y_len;
}	t_mlx;



//erros functions
void	f_map_error(void);
void	ext_error(void);
void	fail_err(void);

//map functions
// void	count_chars(t_map *map, char c);
int		check_map(char *map_file, t_map *map);
int		readmap(t_map *map, char *map_file);


// miscellaneous
// void	ft_free(char **str);
char	*get_next_line(int fd);

#endif
