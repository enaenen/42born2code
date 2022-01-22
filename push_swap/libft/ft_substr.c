/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 03:24:36 by wchae             #+#    #+#             */
/*   Updated: 2021/12/30 17:02:43 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buf;
	size_t	s_len;

	if (!s || !len)
		return (ft_strdup(""));
	s_len = ft_strlen(s);
	if (s_len <= start)
		return (ft_strdup(""));
	if (s_len < len)
		len = s_len;
	buf = (char *)malloc(++len);
	if (!buf)
		return (NULL);
	ft_strlcpy(buf, s + start, len);
	return (buf);
}
