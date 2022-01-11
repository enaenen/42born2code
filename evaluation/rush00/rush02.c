/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:57:10 by wchae             #+#    #+#             */
/*   Updated: 2022/01/11 21:09:30 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_first_line(int x)
{
	int	width;

	width = 0;
	while (width != x)
	{
		if (width == 0 || width == (x - 1))
			ft_putchar('A');
		else
			ft_putchar('B');
		width++;
	}
}

void	print_last_line(int x)
{
	int	width;

	width = 0;
	while (width != x)
	{
		if (width == 0 || width == (x - 1))
			ft_putchar('C');
		else
			ft_putchar('B');
		width++;
	}
}

void	print_middle_line(int x)
{
	int	width;

	width = 0;
	while (width != x)
	{
		if (width == 0 || width == (x - 1))
			ft_putchar('B');
		else
			ft_putchar(' ');
		width++;
	}
}

void	rush(int x, int y)
{
	int	height;

	height = 0;
	while (height != y)
	{
		if (height == 0)
			print_first_line(x);
		else if (height == (y - 1))
			print_last_line(x);
		else
			print_middle_line(x);
		ft_putchar('\n');
		height++;
	}
}
