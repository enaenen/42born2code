#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dup_str;
	char	*ret;

	ret = (char *) malloc(sizeof(char) * (n + 1));
	if (!ret)
		return (NULL);
	dup_str = ret;
	while (n--)
		*dup_str++ = *s1++;
	*dup_str = '\0';
	return (ret);
}

void	test_ft_strndup(char *str, size_t n)
{
	char *dup_str;

	dup_str = ft_strndup(str, n);
	printf("strndup %zu == %s \n", n, dup_str);
	free(dup_str);
}

void	test_strndup(char *str, size_t n)
{
	char *dup_str;

	dup_str = strndup(str, n);
//	printf("dup_str == %p , original_str = %p \n",dup_str, str);
	printf("strndup %zu == %s \n", n, dup_str);
	free(dup_str);
}

int main(void)
{
	char	*str = "abcd";
//	malloc 할당과정에서 -1 할당시 너무 큰 할당량이라 bus 에러 발생	
//	test_strndup(str, -1);
//	test_ft_strndup(str, -1);

	test_strndup(str, 0);
	test_ft_strndup(str, 0);
	test_strndup(str, 1);
	test_ft_strndup(str, 1);
	test_strndup(str, 2);
	test_ft_strndup(str, 2);
	test_strndup(str, 3);
	test_ft_strndup(str, 3);
	test_strndup(str, 4);
	test_ft_strndup(str, 4);
	test_strndup(str, 5);
	test_ft_strndup(str, 5);
	test_strndup(str, 6);
	test_ft_strndup(str, 6);

	printf("=================================\n");
	char	*trash;
	test_strndup(NULL, 0);
	test_ft_strndup(NULL, 0);

	test_strndup(trash, 0);
	test_ft_strndup(trash, 0);
	
	printf("==========trash -1,1,2=======================\n");

	//test_strndup(trash, -1);
	test_strndup(trash, 1);
	test_ft_strndup(trash, 1);
	test_strndup(trash, 2);
	test_ft_strndup(trash, 2);

	printf("=============NULL 1, 2====================\n");
	test_strndup(NULL, 1);
	test_strndup(NULL, 2);
}
