/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:48:56 by ahkecha           #+#    #+#             */
/*   Updated: 2022/02/15 14:14:09 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <errno.h>


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
	if (line == 1)
	{
		ft_putendl_fd("Error\nInvalid Map" ,2);
		exit(EXIT_FAILURE);
	}
	close(fd);
	return (line);
}

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



