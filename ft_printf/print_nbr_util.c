//
// Created by Woo Joo Chae on 2021/12/28.
//
#include "ft_printf.h"


void ft_putuns(unsigned int n, int *len)
{
    char tmp;

    if (n < 10)
    {
        tmp = n % 10 + '0';
        *len += write(1, &tmp, 1);
    }
    else
    {
        ft_putuns(n / 10, len);
        tmp = n % 10 + '0';
        *len += write(1, &tmp, 1);
    }
}

int ft_print_unsigned(unsigned int n, char format)
{
    char *hex;
    int len;
    int i;

    len = 0;
    i = 0;
    if (format == 'u')
        ft_putuns(n, &len);
    else
    {
        hex = ft_putnbr_hexbase((unsigned long long) n);
        if (!hex)
            return (0);
        if (format == 'X')
        {
            while (hex[i])
            {
                hex[i] = (char) ft_toupper(hex[i]);
                i++;
            }
        }
        len = ft_putstr(hex);
        free(hex);
    }
    return (len);
}

void ft_putnbr(int n, int *len)
{
    if (n == -2147483648)
    {
        *len = write(1, "-2147483648", 11);
        return;
    }
    else if (n < 0)
    {
        *len += write(1, "-", 1);
        n *= -1;
        ft_putnbr(n, len);
    }
    else if (n < 10)
    {
        char tmp;
        tmp = n % 10 + '0';
        *len += write(1, &tmp, 1);
    }
    else
    {
        char tmp;
        ft_putnbr(n / 10, len);
        tmp = n % 10 + '0';
        *len += write(1, &tmp, 1);
    }
}


int ft_print_number(int n)
{
    int len;

    len = 0;
    ft_putnbr(n, &len);
    return (len);
}
