/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointerType.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:54:39 by wchae             #+#    #+#             */
/*   Updated: 2022/01/05 14:58:56 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
	int a;
	int *ptr;

	a = 999;
	ptr = &a;

	
	printf("%p\n", ptr);
	printf("%p\n", &a);
	printf("%u\n", &ptr);
}