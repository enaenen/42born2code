//
// Created by Woo Joo Chae on 2021/12/14.
//

#ifndef FT_PRINTF_FT_PRINTF_H
# define FT_PRINTF_FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>
# include <string.h>
# include "libft/libft.h"

int ft_print_number(int n);
int ft_print_unsigned(unsigned int n, char format);
char *ft_putnbr_hexbase(unsigned long long num);
int ft_printf(const char *format, ...);
#endif //FT_PRINTF_FT_PRINTF_H
