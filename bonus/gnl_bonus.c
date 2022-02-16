/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:59:57 by ahkecha           #+#    #+#             */
/*   Updated: 2022/02/16 15:46:14 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	get_line2(int fd, char **s, t_list *var)
{
	char	buffer[BUFFER_SIZE + 1];
	int		ret;

	if (!*s)
		*s = ft_strdup("");
	var->ch = ft_strchr(*s, '\n');
	ret = 1;
	while (!var->ch && ret > 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		buffer[ret] = '\0';
		var->ch = *s;
		*s = ft_strjoin(*s, buffer);
		free(var->ch);
		var->ch = ft_strchr(*s, '\n');
	}
	return (ret);
}

static char	*d(char **s_buff, t_list *var)
{
	var->line = ft_strdup(*s_buff);
	ft_free(s_buff);
	if (var->line[0] == '\0')
		ft_free(&var->line);
	return (var->line);
}

char	*get_next_line(int fd)
{
	static char	*s_buff;
	t_list		var;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 4096)
		return (NULL);
	var.tab[0] = get_line2(fd, &s_buff, &var);
	if (var.tab[0] == -1)
		return (ft_freesec(&s_buff));
	if (var.ch)
	{
		var.tab[1] = ft_strlen(s_buff) - ft_strlen(var.ch);
		var.line = ft_substr(s_buff, 0, var.tab[1] + 1);
		var.ch = s_buff;
		s_buff = ft_strdup(s_buff + var.tab[1] + 1);
		free(var.ch);
	}
	else
		return (d(&s_buff, &var));
	if ((var.tab[0] == 0 && s_buff != NULL) || var.tab[0])
		return (var.line);
	return (NULL);
}
