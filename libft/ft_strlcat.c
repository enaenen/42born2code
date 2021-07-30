/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 05:37:00 by wchae             #+#    #+#             */
/*   Updated: 2021/05/18 03:12:29 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (!dstsize)
		return (src_len);
	else if (dstsize < dst_len)
		return (src_len + dstsize);
	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (src[j] && i < dstsize - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dst_len + src_len);
}
