//
// Created by Woo Joo Chae on 2021/12/16.
//

#include "ft_printf.h"

int main(void)
{
    ft_printf("%c",'t');
    ft_printf("%s","the string");
    ft_printf("%p","1");
    ft_printf("%d","123");
    ft_printf("%i","1");
    ft_printf("%u","1");
    ft_printf("%x","1");
    ft_printf("%X","1");
    ft_printf("%%","ABC");
}