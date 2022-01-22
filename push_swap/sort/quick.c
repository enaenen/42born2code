#include <stdio.h>

void	print_array(int **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
		printf("%d ", *arr[i++]);

	printf("\n");
}
void	qsort(int *arr, int start, int end)
{
	int	pivot;
	int	i;
	int	j;
	int	temp;

	print_array(&arr, 10);
	pivot = start;
	i = pivot + 1;
	j = end;
	temp = 0;
	if (start >= end)
		return;
	while (i <= j)
	{
		while (i <= end && arr[i] <= arr[pivot])
			++i;
		while(j > start && arr[j] >= arr[pivot])
			--j;
		if (i >= j)
			break;
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	temp = arr[j];
	arr[j] = arr[pivot];
	arr[pivot] = temp;

	qsort(arr, start, j - 1);
	qsort(arr, j + 1, end);
}

int	main()
{
	int	i;
	int	arr[10] = {5, 6, 10, 4, 3, 8, 7, 1, 2, 9};

	i = -1;
	qsort(arr, 0, 9);
	while (++i < 10)
		printf("%d ", arr[i]);
}
