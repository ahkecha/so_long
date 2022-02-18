/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:37:54 by ahkecha           #+#    #+#             */
/*   Updated: 2022/02/17 12:30:10 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"

# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2
# define ESCAPE_KEY 53
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define DOWN_KEY 125
# define UP_KEY 126
# define FILE_ERR "Error:\nNo such file or directory"
# define EXT_ERR "Error:\nMap must be .ber"
# define FAIL_ERR "Error:\nMap file is empty"
# define BUFFER_SIZE 100

typedef struct s_img
{
	void	*ptr;
	int		lenght;
	int		height;
	int		width;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_map
{
	int		playerx;
	int		playery;
	void	*map_path;
	char	**map;
	int		steps;
	int		coll;
	t_mlx	mlx;
	t_img	img;
}	t_map;

typedef struct gnl
{
	char		*line;
	char		*ch;
	int			tab[2];
}			t_list;

void	f_map_error(void);
void	ext_error(void);
void	fail_err(void);
void	arerr(void);
int		quit(int a);
void	errmap(void);
int		check_map(char *map_file, t_map *map);
int		readmap(t_map *map, char *map_file);
void	bg(t_map *map, int i, int j);
void	parse_xpm(t_map *map);
void	render_player(t_map *map, int i, int j);
void	render_bg(t_map *map);
int		parse_map(t_map *map, char	*exit);
int		check_extentions(char *file_path);
void	check_content(char *file_path);
void	is_exist(char *file_path);
int		ft_charcount(t_map *map);
void	go_right(t_map *map, int w);
void	go_left(t_map *map, int w);
void	go_up(t_map *map, int w);
void	go_down(t_map *map, int w);
char	*ft_freesec(char **str);
void	ft_free(char **str);
void	count_steps(t_map *map);
char	*get_next_line(int fd);
void	ft_swap(char *a, char *b);
void	ft_render_images(t_map *map);
void	player_position(t_map *map);
void	render_img(t_map *map, int i, int j, char *path);
void	vsync(t_map *map);
void	vsync_with_exit(t_map *map);
void	winexit(void);
int		check_components(t_map *map);

#endif
