/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 19:24:29 by wchae             #+#    #+#             */
/*   Updated: 2021/12/30 16:59:27 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*buf;

	buf = (void *)malloc(n * size);
	if (!buf)
		return (NULL);
	ft_bzero(buf, n * size);
	return (buf);
}
