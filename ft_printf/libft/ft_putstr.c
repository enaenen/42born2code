//
// Created by Woo Joo Chae on 2021/12/17.
//
#include "libft.h"
int ft_putstr(char *str)
{
    int len;

    len = 0;
    len = write(1, str, ft_strlen(str));
    return (len);
}