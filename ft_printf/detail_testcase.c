//
// Created by Woo Joo Chae on 2021/12/16.
//

#include "ft_printf.h"

int main(void)
{
    char testC = 'A';
    printf("\nprintf(\"[%%c]\", 'A');\n");
    printf("[%c]\n", testC);
    ft_printf("[%c]\n", testC);

    printf("%s\n","");
    ft_printf("%s\n","");
    printf("%s\n","abcd121923012903");
    ft_printf("%s\n","abcd121923012903");

    printf("===========NULL TEST===========\n");
    printf("%s\n",0);
    ft_printf("%s\n",0);

    int a = 2147483647;
    long b = 3147483699;
    printf("===========%%d TEST===========\n");
    printf("Normal Range 99999 = %d\n",a);
    ft_printf("Normal Range 99999 = %d\n",a);
    printf("Out Of Range = %d\n",b);
    ft_printf("Out Of Range  = %d\n",b);
}