/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:39:36 by wchae             #+#    #+#             */
/*   Updated: 2021/08/01 04:29:58 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	ft_append(char **backup, char *buf)
{
	char	*prev;

	if (!*backup)
	{
		*backup = ft_strdup(buf);
		if (!*s)
			return (0);
	}
	prev = ft_strdup(*backup);
	free_ptr(backup);
	if (!prev)
		return (0);
	if (!ft_calloc(backup, ft_strlen(prev) + ft_strlen(buf) + 1, 1))
	{
		ft_free_ptr(&prev);
		return (0);
	}
	ft_strlcpy(*backup, prev, ft_strlen(prev) + 1);
	ft_strlcpy(*backup + ft_strlen(prev), buf, ft_strlen(buf) + 1);
	ft_free_ptr(&prev);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	char		*line;
	char		*buf;
	int			read_size;

	if (fd < 0 || (BUFFER_SIZE < 1) || OPEN_MAX <= fd ||
			!ft_calloc(&buf, BUFFER_SIZE + 1, sizeof(char)))
		return (NULL);
	while (1)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		buf[read_size] = '\0';
		if (!ft_append(&backup[fd], buf))
		{
			ft_free_ptr(&buf)
				return (NULL);
		}
	}
	return (line);
}
