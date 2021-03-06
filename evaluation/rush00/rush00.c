/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:02:12 by wchae             #+#    #+#             */
/*   Updated: 2022/01/11 21:08:10 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_width(int x)
{
	int	width;

	width = 0;
	if (x == 0)
		return ;
	while (width != x)
	{
		if (width == 0 || width == (x - 1))
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
	if (x == 0)
		return ;
	while (width != x)
	{
		if (width == 0 || width == (x - 1))
			ft_putchar('|');
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
		if (height == 0 || height == (y - 1))
			print_width(x);
		else
			print_middle_width(x);
		ft_putchar('\n');
		height++;
	}
}
