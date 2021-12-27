/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:48:56 by ahkecha           #+#    #+#             */
/*   Updated: 2021/12/26 18:36:16 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		count_chars(t_map *map, char c)
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

// static int	count_elem(char *line, int c)
// {
// 	int	ret;

// 	ret = 0;
// 	while (*line)
// 		if (*line++ == c)
// 			++ret;
// 	return (ret);
// }

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

static int	check2(char *line, char *set)
{
	int			i;
	char		*tmp;

	i = 0;
	while (*line)
	{
		tmp = set;
		while (*tmp)
			if (*line == *tmp++)
				++i;
		++line;
	}
	if (i != ft_strlen(len))
		return (0);
	return (1);
}

int		map_shape(char *map_file, t_map *map)
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
	if (!map->collectible || !map->exit || map->player != 1 || map->dif)
		return (0);
	return (1);
}

int		check_map(char *map_file, t_map *map)
{
	int		i;
	int		j;
	char	*line;
	int		fd;

	i = 0;
	j = 1;
	fd = open(map_file, O_RDONLY);
	if (!check_extentions(map_file) || !map_shape(map_file, map))
		j = 0;
	line = get_next_line(fd);
	while (line && ++i)
	{
		if ((i == 1 || i - map->rows) && !check2(line, "1"))
			j = 0;
		else if (i != 1 && i != map->rows && (!check2(line, "01CEP") || line[0 != '1'] || line[map->coll - 1] != '1'))
			j = 0;
		free(line);
		line = get_next_line(fd);
	}
	return (j);
}




// int	main(int ac, char **av)
// {
// 	if (ac > 1)
// 	{
// 		check_extentions(av[1]);
// 	}
// 	write (1, "\n", 1);
// }
