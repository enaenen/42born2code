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

	printf("%s\n", "");
	ft_printf("%s\n", "");
	printf("%s\n", "abcd121923012903");
	ft_printf("%s\n", "abcd121923012903");

	char *str;
	printf("===========NULL TEST===========\n");
	printf("%s\n", str);
	ft_printf("%s\n", str);

	int a = 2147483647;
	long b = 3147483699;
	printf("===========%%d TEST===========\n");
	printf("Normal Range 99999 = %d\n", a);
	ft_printf("Normal Range 99999 = %d\n", a);

	unsigned int un = 4294967295;
	printf("===========Unsigned TEST===========\n");
	printf("%u \n", un);
	ft_printf("%u \n", un);

	printf("===========Hex TEST===========\n");
	printf("\nprintf(\"[%%x]\", 123);\n");
	printf("[%x]\n", 123);
	ft_printf("[%x]\n", 123);
}