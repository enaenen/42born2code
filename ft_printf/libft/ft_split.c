/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 00:18:43 by wchae             #+#    #+#             */
/*   Updated: 2021/12/30 17:09:48 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_wordcnt(const char *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			++cnt;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (cnt);
}

static char	**ft_free(char **res, int i)
{
	while (--i >= 0 && res[i])
	{
		free(res[i]);
		res[i] = NULL;
	}
	free(res);
	res = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char		**res;
	char		*from;
	size_t		i;

	res = (char **)malloc(sizeof(char *) * (ft_wordcnt(s, c) + 1));
	if (!s || !res)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			from = (char *)s;
			while (*s && *s != c)
				s++;
			res[i] = (char *)malloc(s - from + 1);
			if (!res[i])
				return (ft_free(res, i));
			ft_strlcpy(res[i++], from, s - from + 1);
		}
		else
			s++;
	}
	res[i] = NULL;
	return (res);
}
