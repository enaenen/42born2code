/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:39:36 by wchae             #+#    #+#             */
/*   Updated: 2021/07/22 21:17:55 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_newline(char **backup, char **line)
{
	char	*newline;
	char	*temp;

	newline = ft_strchr(*backup, '\n');
	if (newline == NULL)
		return (0);
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

	if ((fd < 0) || (BUFFER_SIZE < 1))
		return (NULL);
	read_size = read(fd, buf, BUFFER_SIZE);
	if (read_size == 0)
		return (NULL);
	while (read_size > 0)
	{
		buf[read_size] = '\0';
		temp = backup[fd];
		backup[fd] = ft_strjoin(backup[fd], buf);
		if (backup[fd] == NULL)
			return (NULL);
		free(temp);
		if (is_newline(&backup[fd], &line) != 0)
			return (line);
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	return (backup_clean(&backup[fd], &line, read_size));
}
