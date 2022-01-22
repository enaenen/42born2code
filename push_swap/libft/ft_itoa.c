/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:38:51 by wchae             #+#    #+#             */
/*   Updated: 2021/12/30 17:22:54 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_count(int n)
{
	int	count;

	count = 1;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long long	num;
	size_t		size;
	char		*res;

	num = n;
	size = digit_count(n);
	if (num < 0)
		size++;
	res = (char *)malloc(size + 1);
	if (!res)
		return (NULL);
	res[size] = 0;
	if (num < 0)
	{
		num = -num;
		res[0] = '-';
	}
	res[--size] = (num % 10) + '0';
	while (num)
	{
		num /= 10;
		res[--size] = (num % 10) + '0';
	}
	return (res);
}
