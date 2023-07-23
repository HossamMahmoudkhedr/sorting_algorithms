#include "sort.h"

/**
 * swap - swaps the values of two integers
 *
 * @a: the address of the first int
 * @b: the address of the second int
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * selection_sort - an implementation of the selection sort algorithm
 *
 * @array: the input array of numbers
 * @size: the size of the input
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min_pos;

	for (i = 0; i < size; i++)
	{
		min_pos = i;
		for (j = i + 1; j < size; j++)
			/*
			 * if (array[j] < array[min_pos])
			 * min_pos = j;
			 */
			min_pos += (array[j] < array[min_pos]) * (j - min_pos);
		if (array[i] != array[min_pos])
			swap(array + i, array + min_pos),
			print_array(array, size);
	}
}

/*#define TEST*/

#ifdef TEST
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	selection_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
#endif
