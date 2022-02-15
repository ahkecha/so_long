/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:41:55 by ahkecha           #+#    #+#             */
/*   Updated: 2022/02/15 13:45:40 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
