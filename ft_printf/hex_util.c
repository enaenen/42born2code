#include "ft_printf.h"

void    ft_hexlen(unsigned long long n, int *len)
{
    while (n > 0)
    {
        n = n / 16;
        (*len)++;
    }
}

void    ft_hexbase(char *str, int *i, unsigned long long num)
{
    if (num < 16)
    {
        str[*i] = "0123456789abcdef"[num];
        (*i)++;
        return;
    }
    else
    {
        ft_hexbase(str, i, num / 16);
        str[*i] = "0123456789abcdef"[num % 16];
        (*i)++;
        return;
    }
}

char    *to_string(unsigned int n)
{
    char *arr;
    int len;

    len = 0;
    ft_hexlen(n, &len);
    arr = (char *) malloc(sizeof(char) * (len + 1));
    if (!arr)
        return (0);
    return arr;
}

char    *ft_putnbr_hexbase(unsigned long long num)
{
    int i;
    char *hex;

    i = 0;

    hex = to_string(num);
    if (!hex)
        return (0);
    ft_hexbase(hex, &i, num);
    hex[i] = 0;
    return (hex);
}