/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:02:12 by wchae             #+#    #+#             */
/*   Updated: 2022/01/10 11:19:05 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_width(int x)
{
	int	width;

	width = 0;
	while (width != (x + 1))
	{
		if (width == 0 || width == x)
			ft_putchar('o');
		else
			ft_putchar('-');
		width++;
	}
}

void	print_middle_width(int x)
{
	int	width;

	width = 0;
	while (width != (x + 1))
	{
		if (width == 0 || width == x)
			ft_putchar('|');
		else
			ft_putchar(' ');
		width++;
	}
}

void	rush00(int x, int y)
{
	int	height;

	height = 0;
	while (height != (y + 1))
	{
		if (height == 0 || height == y)
			print_width(x);
		else
			print_middle_width(x);
		ft_putchar('\n');
		height++;
	}
	ft_putchar('\n');
}

int	main(void)
{
	rush00(5, 5);
}
