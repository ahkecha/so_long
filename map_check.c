/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:48:56 by ahkecha           #+#    #+#             */
/*   Updated: 2022/01/16 13:53:20 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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


static int		check_extentions(char *file_path)
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

static int	check2(char *map)
{
	int		fd;
	int		line;
	char	*str;

	fd = open(map, O_RDONLY);
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

static int		map_shape(char *map_file, t_map *map)
{
	int 	i;
	char	*line;
	int		fd;
	int		j;

	i = 1;
	j = 0;
	fd = open(map_file, O_RDONLY);
	line = get_next_line(fd);
	while(line && i++)
	{
		if(i == 1)
			map->coll = ft_strlen(line);
		else if ((int)ft_strlen(line) != map->walls)
			map->dif = 1;
		count_chars(map, 'W');
		count_chars(map, 'C');
		count_chars(map, 'P');
		count_chars(map, 'E');
		free(line);
		line = get_next_line(fd);
	}
	map->rows = 1;
	if (!map->emerald || !map->exit || map->player != 1 || map->dif)
		return (0);
	return (1);
}

int		readmap(t_map *map, char *map_file)
{
	int		fd;
	int		line;
	char	*ptr;

	line = check2(map_file);
	fd = open(map_file, O_RDONLY);
	map->map = malloc(sizeof(char) * line);
	line = 0;
	while (1337)
	{
		ptr = get_next_line(fd);
		if (!ptr)
			break ;
		map->map[line] = ptr;
		line++;
	}
	map->img.height = line;
	map->img.width = ft_strlen(map->map[0]);
	close(fd);
	return (line);
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		check_extentions(av[1]);
	}
	write (1, "\n", 1);
}
