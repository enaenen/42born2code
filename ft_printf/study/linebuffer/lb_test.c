#include <stdio.h>
#include <unistd.h>

int main (void)
{
	printf("a");
	write(1, "b", 1);
	printf("c");
}
