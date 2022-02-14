/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:45:56 by ahkecha           #+#    #+#             */
/*   Updated: 2022/02/12 12:45:57 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	f_map_error(void)
{
	ft_putendl_fd(FILE_ERR, 2);
	exit(EXIT_FAILURE);
}

void	ext_error(void)
{
	ft_putendl_fd(EXT_ERR, 2);
	exit(EXIT_FAILURE);
}

void	fail_err(void)
{
	ft_putendl_fd(FAIL_ERR, 2);
	exit(EXIT_FAILURE);
}
