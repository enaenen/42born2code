/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:39:36 by wchae             #+#    #+#             */
/*   Updated: 2021/08/01 05:22:27 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
 *
 *	newline 전에서 잘림
 *	\n 도 리턴을 해야함
 *	nl 1. OK , 2.KO
 *	no_nl 테스트에서 KO
 *
 *
 * */ 
static int	ft_append(char **backup, char *buf)
{
	char	*prev;

	if (!*backup)
	{
		*backup = ft_strdup(buf);
		if (!*backup)
			return (0);
	}
	prev = ft_strdup(*backup);
	ft_free_ptr(backup);
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

static	int	is_newline(char *backup, int *read_size)
{
	int	i;

	i = -1;
	while (backup[++i])
	{
		if (backup[i] == '\n')
		{
			*read_size = i + 1;
			return (1);
		}
	}
	*read_size = -1;
	return (0);
}

static char	*split_line(char **backup, ssize_t read_size)
{
	char	*line;
	char	*temp;

	(*backup)[read_size] = '\0';
	line = ft_strdup(*backup);
	if (!line)
	{
		ft_free_ptr(backup);
		return (NULL);
	}
	if (!ft_strlen(*backup + read_size + 1))
	{
		ft_free_ptr(backup);
		return (line);
	}
	temp = *backup;
	*backup = ft_strdup(*backup + read_size + 1);
	ft_free_ptr(&temp);
	if (!*backup)
		return (NULL);
	return (line);
}

static char	*no_newline(char **backup, char **buf, int read_size)
{
	int		i;
	char	*line;

/*	if (!*backup)
	{
		ft_calloc(&line, 1, sizeof(char));
		ft_free_ptr(buf);
		return (line);
	}
	*/
	line = NULL;
	i = -1;
	ft_free_ptr(buf);
	if (read_size < 0)
	{
		ft_free_ptr(backup);
		return (NULL);
	}
	if (*backup)
	{
		if (is_newline(*backup, &i))
			return (split_line(backup, i));
		line = *backup;
		backup = NULL;
		return (line);
	}
	if (!ft_calloc(&line, 1, sizeof(char)))
	{
		ft_free_ptr(backup);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	char		*buf;
	int			read_size;

	if (fd < 0 || (BUFFER_SIZE < 1) || OPEN_MAX <= fd
		|| !ft_calloc(&buf, BUFFER_SIZE + 1, sizeof(char)))
		return (NULL);
	while (1)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		buf[read_size] = '\0';
		if (!ft_append(&backup[fd], buf))
		{
			ft_free_ptr(&buf);
			return (NULL);
		}
		if (is_newline(backup[fd], &read_size))
		{
			ft_free_ptr(&buf);
			return (split_line(&backup[fd], read_size));
		}
	}
	return (no_newline(&(backup[fd]), &buf, read_size));
}
