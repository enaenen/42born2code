#include <stdio.h>

int main(void)
{
	int a = printf("%9223372036854775808d\n", 42);
	printf("a : %d", a);
}
