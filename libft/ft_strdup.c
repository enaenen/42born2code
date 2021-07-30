/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:20:10 by wchae             #+#    #+#             */
/*   Updated: 2021/05/13 12:58:32 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*res;

	len = ft_strlen(s1);
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ft_memcpy(res, s1, len);
	res[len] = '\0';
	return (res);
}
