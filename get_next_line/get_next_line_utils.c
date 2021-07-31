/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 19:31:49 by wchae             #+#    #+#             */
/*   Updated: 2021/08/01 05:03:35 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t		len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	if (dstsize)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	len;

	len = ft_strlen(s);
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s, len + 1);
	return (result);
}

int	ft_calloc(char **ptr, size_t cnt, size_t n)
{
	size_t	i;

	i = -1;
	*ptr = malloc(cnt * n);
	if (!*ptr)
		return (0);
	while (++i < n)
		(*ptr)[i] = '\0';
	return (1);
}

void	ft_free_ptr(char **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}
