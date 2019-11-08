/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdervil <thdervil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:14:27 by thdervil          #+#    #+#             */
/*   Updated: 2019/11/05 12:06:50 by thdervil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int		get_next_line(const int fd, char **line)
{
	static char t[BUFF_SIZE + 1];
	char		*pos;
	char		*swap;
	int			cursor;

	if (fd < 0 || BUFF_SIZE < 1 || read(fd, t, 0) < 0
			|| !(*line = ft_strnew(0)) || !line)
		return (-1);
	while (1)
	{
		if ((pos = ft_strchr(t, '\n')))
		{
			if (!(swap = ft_strndup(t, ft_strlen(t) - ft_strlen(pos) - 1)))
				swap = ft_strnew(0);
			*line = ft_strjoin_free(*line, swap, 3);
			ft_strcpy(t, ++pos);
			return (1);
		}
		if (!((*line = ft_strjoin_free(*line, t, 1))))
			return (-1);
		cursor = read(fd, t, BUFF_SIZE);
		t[cursor] = '\0';
		if (cursor == 0)
			return (**line ? 1 : 0);
	}
}
