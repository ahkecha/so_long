/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:15:04 by ahkecha           #+#    #+#             */
/*   Updated: 2021/12/26 18:22:43 by ahkecha          ###   ########.fr       */
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
