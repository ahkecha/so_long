/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:48:56 by ahkecha           #+#    #+#             */
/*   Updated: 2022/02/02 12:40:53 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <errno.h>

static void		count_chars(t_map *map, char c)
{
	if (c == '0')
		map->empty += 1;
	if (c == '1')
		map->walls += 1;
	if (c == 'C')
		map->emerald += 1;
	if (c == 'P')
		map->start += 1;
	if (c == 'E')
		map->exit += 1;
}


int		check_extentions(char *file_path)
{
	size_t	lenght;

	lenght = ft_strlen(file_path);
	if (!lenght)
		f_map_error();
	if (file_path[lenght - 1] == 'r' && file_path[lenght - 2] == 'e' && \
		file_path[lenght - 3] == 'b' && file_path[lenght - 4] == '.')
		return (1);
	else
		ext_error();
	return (0);
}



static int	check2(char *map_file)
{
	int		fd;
	int		line;
	char	*str;

	fd = open(map_file, O_RDONLY);
	line = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		free(str);
		line++;
	}
	close(fd);
	return (line);
}

// // static int		map_shape(char *map_file, t_map *map)
// // {
// // 	int 	i;
// // 	char	*line;
// // 	int		fd;
// // 	int		j;

// // 	i = 1;
// // 	j = 0;
// // 	fd = open(map_file, O_RDONLY);
// // 	line = get_next_line(fd);
// // 	while(line && i++)
// // 	{
// // 		if(i == 1)
// // 			map->coll = ft_strlen(line);
// // 		else if ((int)ft_strlen(line) != map->walls)
// // 			map->dif = 1;
// // 		count_chars(map, 'W');
// // 		count_chars(map, 'C');
// // 		count_chars(map, 'P');
// // 		count_chars(map, 'E');
// // 		free(line);
// // 		line = get_next_line(fd);
// // 	}
// // 	map->rows = 1;
// // 	if (!map->emerald || !map->exit || map->player != 1 || map->dif)
// // 		return (0);
// // 	return (1);
// // }

int		readmap(t_map *map, char *map_file)
{
	int		fd;
	int		line;
	char	*str;

	line = check2(map_file);
	if (!line)
		return (0);
	fd = open(map_file, O_RDONLY);
	map->map = malloc(sizeof(char *) * line);
	line = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		map->map[line] = str;
		line++;
	}
	map->img.height = line;
	//// puts("p1");
	map->img.width = ft_strlen(map->map[0]) - 1;
	close(fd);
	return (line);
}

void	is_exist(char *file_path)
{
	int fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		f_map_error();
}

void	check_content(char *file_path)
{
	int fd;
	char *str;

	fd = open(file_path, O_RDONLY);
	str = get_next_line(fd);
	if (!str)
		fail_err();
}


int		parse_map(t_map *map)
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
				wall(map, i, j);
			else if (map->map[i][j] == 'P')
				render_player(map, i, j);
			else if (map->map[i][j] == 'C')
				coll(map, i, j);
			else if (map->map[i][j] == 'E')
				exits(map, i, j);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
