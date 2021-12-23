//
// Created by Woo Joo Chae on 2021/12/17.
//
#include "libft.h"

int ft_putchar(char c) {
    int len;

    len = 0;
    len = write(1, &c, 1);
    return (len);
}