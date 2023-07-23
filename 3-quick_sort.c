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
 * partition - partitions the quick sorted array according to the pivot
 *
 * @arr: the input array
 * @start: the start index from the array elements
 * @end: the end index from the array elements
 * @orig_size: the original size of the full array
 * Return: the pivot point index
 */
int partition(int *arr, int start, int end, size_t orig_size)
{
	int pivot_v = arr[end], i = 0, j = 0;

	i = start - 1;
	for (j = start; j < end; j++)
		if (arr[j] <= pivot_v)
			if (arr[++i] != arr[j])
				swap(arr + i, arr + j),
				print_array(arr, orig_size);
	if (arr[++i] != arr[end])
		swap(arr + i, arr + end),
		print_array(arr, orig_size);
	return (i);
}

/**
 * quick_sort_with_more_parameters - the actual recursive implementation
 *
 * @array: the input array
 * @start: the start index from the array elements
 * @end: the end index from the array elements
 * @orig_size: the original size of the full array
 * @
 */
void quick_sort_with_more_parameters(
	int *array, int start, int end, size_t orig_size
)
{
	size_t pivot;

	if (start >= end || start < 0)
		return;

	pivot = partition(array, start, end, orig_size);

	quick_sort_with_more_parameters(array, start, pivot - 1, orig_size);
	quick_sort_with_more_parameters(array, pivot + 1, end, orig_size);
}

/**
 * quick_sort - an implementation of the quick sort algorithm
 *
 * @array: the input array of numbers
 * @size: the size of the input
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_with_more_parameters(array, 0, size - 1, size);
	/**
	 *size_t pivot;
	 *
	 *if (size <= 2)
	 *{
	 *	if (size == 2 && array[0] > array[1])
	 *		swap(array, array + 1);
	 *	return;
	 *}
	/ ** /
	*pivot = partition(array, 0, size - 1);
	/ ** /
	*for (i = 0; i < pivot; i++)
	*	if (array[pivot] < array[i])
	*		swap(array + pivot - 1, array + i),
	*		swap(array + pivot, array + pivot - 1);
	/ ** /
	*print_array(array, size);
	*quick_sort(array, pivot);
	*quick_sort(array + pivot + 1, size - pivot - 1);
	*/
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
	quick_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
#endif
