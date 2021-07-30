/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 02:13:16 by wchae             #+#    #+#             */
/*   Updated: 2021/05/15 02:47:04 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t index;

	index = 0;
	while (index < n)
	{
		if (((unsigned char *)s1)[index]
				!= ((unsigned char *)s2)[index])
		{
			return ((((unsigned char*)s1)[index])
					- (((unsigned char *)s2)[index]));
		}
		index++;
	}
	return (0);
}
