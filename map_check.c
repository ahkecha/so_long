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




// int	main(int ac, char **av)
// {
// 	if (ac > 1)
// 	{
// 		check_extentions(av[1]);
// 	}
// 	write (1, "\n", 1);
// }
