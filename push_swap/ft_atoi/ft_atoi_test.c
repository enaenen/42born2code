#include <stdio.h>

bool	ft_atoi(char	**str, int	*num)
{
	int	sign;
	int	tmp;

	while (ft_isspace(**str))
		(*str)++;
	sign = 1;
	if (**str == '+' || **str == '-')
		if (*((*str)++) == '-')
			sign = -1;
	if (!ft_isdigit(**str))
		return (false);
	while (ft_isdigit(**str))
	{
		tmp = (*((*str)++) - '0');
		if (sign < 0)
			tmp = ~(tmp) + 1;
		tmp = *num * 10 + tmp;
		*num = tmp;
	}
}
