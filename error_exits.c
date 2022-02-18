/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:45:56 by ahkecha           #+#    #+#             */
/*   Updated: 2022/02/18 11:47:33 by ahkecha          ###   ########.fr       */
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

void	arerr(void)
{
	ft_putendl_fd("Error:\nNot enough arguments", 2);
	exit(EXIT_FAILURE);
}

void	errmap(void)
{
	ft_putendl_fd("Error:\nMap is invalid", 2);
	exit(EXIT_FAILURE);
}
