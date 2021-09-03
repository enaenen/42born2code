/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:22:02 by wchae             #+#    #+#             */
/*   Updated: 2021/09/03 14:26:17 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*ret;
	char	*tmp;

	ret = malloc(n + 1);
	if (!ret)
		return (NULL);
	tmp = ret;
	while (n--)
		*tmp++ = *s++;
	*tmp = '\0';
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = malloc(s1_len + s2_len + 1);
	if (!ret)
		return (NULL);
	while (*s1)
		*ret++ = *s1++;
	while (*s2)
		*ret++ = *s2++;
	*ret = '\0';
	return (ret - s1_len - s2_len);
}

char	*ft_strchr(const char *str, int c)
{
	char	*ret;

	ret = (char *)str;
	while (*ret && *ret != (char)c)
		ret++;
	if (*ret == (char) c)
		return (ret);
	return (NULL);
}
