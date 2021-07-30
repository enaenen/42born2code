/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 02:04:03 by wchae             #+#    #+#             */
/*   Updated: 2021/05/27 14:13:30 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t index;

	index = 0;
	if (dstsize)
	{
		while (index < dstsize - 1 && src[index])
		{
			dst[index] = src[index];
			index++;
		}
		dst[index] = '\0';
	}
	while (src[index])
		index++;
	return (index);
}
