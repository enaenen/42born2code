/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:39:36 by wchae             #+#    #+#             */
/*   Updated: 2021/07/24 04:04:58 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t ft_strlcpy(char	*dst, const char *src, size_t dstsize)
{
	size_t index;
	size_t src_len;

	if (!dst || !src)
		return (0);
	src_len = ft_strlen(src);
	index = 0;
	if (!src)
		return (0);
	if (dstsize)
	{
		while (index < dstsize - 1 && src[index])
		{
			dst[index] = src[index];
			index++;
		}
		dst[index] = '\0';
	}
	return (src_len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buf;

	if (!s || ft_strlen(s) <= start || len)
		return (ft_strdup(""));
	buf = malloc(++len);
	if (!buf)
		return (NULL);
	ft_strlcpy(buf, s + start, len);
	return (buf);
}

int	is_newline(char **backup, char **line)
{
	char	*newline;
	char	*temp;

	newline = ft_strchr(*backup, '\n');
	if (newline == NULL)
	{
		*line = ft_strdup(*backup);
		if (*line == NULL)
			return (-1);
		free(*backup);
		return (0);
	}
	*line = ft_substr(*backup, ,)
	*newline = '\0';
	*line = ft_strdup(*backup);
	if (*line == NULL)
		return (-1);
	temp = ft_strdup(++newline);
	if (temp == NULL)
		return (-1);
	free(*backup);
	*backup = temp;
	return (1);
}

char	*backup_clean(char **backup, char **line, int read_size)
{
	if (read_size < 0)
		return (NULL);
	if (*backup != NULL && (is_newline(backup, line)))
		return (*line);
	else if (*backup != NULL)
	{
		*line = ft_strdup(*backup);
		if (*line == NULL)
			return (NULL);
		free(*backup);
		*backup = NULL;
		return (*line);
	}
	*line = ft_strdup("");
	if (*line == NULL)
		return (NULL);
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	char		*line;
	char		buf[BUFFER_SIZE + 1];
	char		*temp;
	int			read_size;

	if ((fd < 0) || (BUFFER_SIZE < 1) || fd > OPEN_MAX)
		return (NULL);
	read_size = read(fd, buf, BUFFER_SIZE);
	printf("===== read_size : %d \n", read_size);
	if (read_size == 0 || read_size < 0)
		return (NULL);
	while (read_size > 0)
	{
		buf[read_size] = '\0';
		temp = backup[fd];
		backup[fd] = ft_strjoin(backup[fd], buf);
		if (backup[fd] == NULL)
			return (NULL);
		free(temp);
		if (is_newline())
		{

		}
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	if (is_newline(&backup[fd], &line) < 0)
		return (NULL);
	return (line);
}
