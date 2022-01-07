#include <string.h>
#include <stdio.h>

int main(void)
{
	char *str = "abcdefg";

	printf("%p == %p \n", &str[1], strchr(str, 'b'));
	printf("%p == %p \n", NULL, strchr(str, 'x'));
	char c;
	printf("%p == %p \n", NULL, strchr(str, c));

	printf("%p == %p \n", NULL, strchr(NULL, ''));
}
