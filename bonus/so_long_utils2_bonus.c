/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:41:55 by ahkecha           #+#    #+#             */
/*   Updated: 2022/02/16 15:46:53 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free(char **str)
{
	free(*str);
	*str = NULL;
}

char	*ft_freesec(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

void	winexit(void)
{
	ft_putendl_fd("👏👏👏Winner👏👏👏", 1);
	exit(EXIT_SUCCESS);
}
