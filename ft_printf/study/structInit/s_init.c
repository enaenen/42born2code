#include <stdio.h>
#include <string.h>

typedef struct s_name
{
	int op1;
	int op2;
	int op3;
}	t_name;

int main(void)
{
	t_name tp;

	printf("op1 : %d\n", tp.op1);
	printf("op2 : %d\n", tp.op2);
	printf("op3 : %d\n", tp.op3);
	printf("======================\n");
	memset(&tp, 0, sizeof(t_name));
	printf("op1 : %d\n", tp.op1);
	printf("op2 : %d\n", tp.op2);
	printf("op3 : %d\n", tp.op3);
}
