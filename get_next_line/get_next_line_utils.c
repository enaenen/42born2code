/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 19:31:49 by wchae             #+#    #+#             */
/*   Updated: 2021/07/21 20:11:32 by wchae            ###   ########.fr       */
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

char	*ft_strchr(const char *s, int c)
{
	while (*s != c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *) s);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;

	if (dst == NULL && src == NULL)
		return (dst);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s)
{
	char	*result;
	int		len;

	len = ft_strlen(s);
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, s, len);
	result[len] = 0;
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		s1_len;
	int		s2_len;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL || s2 == NULL)
	{
		if (s1 == NULL)
			return (ft_strdup(s2));
		return (ft_strdup(s1));
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, s1, s1_len);
	ft_memcpy(result + s1_len, s2, s2_len + 1);
	result[s1_len + s2_len + 1] = '\0';
	return (result);
}
