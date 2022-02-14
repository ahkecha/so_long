/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_longs_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:34:57 by ahkecha           #+#    #+#             */
/*   Updated: 2022/02/14 17:03:42 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int quit(int a)
{
	exit(EXIT_SUCCESS);
	return (0);
}

