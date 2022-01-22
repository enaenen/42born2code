/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 18:09:40 by wchae             #+#    #+#             */
/*   Updated: 2021/12/30 17:13:37 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	index;

	index = -1;
	if (n && dst != src)
	{
		while (++index < n)
			((unsigned char *)dst)[index] = ((unsigned char *)src)[index];
	}
	return (dst);
}
