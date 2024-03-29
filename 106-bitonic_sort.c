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
 * bitonic_sort_norec - a recursion free version from wikipedia of bitonic sort
 *
 * @array: the input array of numbers
 * @size: the size of the input
 */
void bitonic_sort_norec(int *array, size_t size)
{
	size_t i, j, k, l;


	for (k = 2; k <= size; k <<= 1)
		for (j = k >> 1; j > 0; j >>= 1)
			for (i = 0; i < size; i++)
			{
				l = i ^ j;
				if (l > i)
					if ((((i & k) == 0) && (array[i] > array[l]))
					|| (((i & k) != 0) && (array[i] < array[l])))
						swap(&array[i], &array[l]);
			}
}

/**
 * comparision_merge - performs a recursive sequence of comparisons and merges
 *
 * @array: the input array of numbers
 * @size: the size of the input
 * @offset: the offset of the sub-array
 * @sect_size: the size of the sub-array section
 * @printed: an option to print the intermediate results or not
 */
void comparision_merge(int *array, size_t size, size_t offset,
	size_t sect_size, bool printed)
{
	if (printed)
		printf("Merging [%ld/%ld] (%s):\n", sect_size, size,
			((offset / sect_size) % 2 == 0) ? "UP" : "DOWN"),
		print_array(array + offset, sect_size);
	if (sect_size == 2)
	{
		if (
			((offset / sect_size) % 2 == 0) ?
			(array[offset + 1 /*(sect_size >> 1)*/] < array[offset]) :
			(array[offset + 1 /*(sect_size >> 1)*/] > array[offset])
		)
		{
			swap(array + offset, array + offset + 1);
			if (printed)
				printf("Result [%ld/%ld] (%s):\n", sect_size, size,
					((offset / sect_size) % 2 == 0) ? "UP" : "DOWN"),
				print_array(array + offset, sect_size);
		}
	}
	else
	{
		/*size_t i;*/

		sect_size >>= 1;
		comparision_merge(array, size, offset, sect_size, printed);
		comparision_merge(array, size, offset + (sect_size), sect_size, printed);

		/*MISSING INTERMEDIATE RESULT MERGING*/

		if (printed)
			printf("Result [%ld/%ld] (%s):\n", (sect_size << 1), size,
				((offset / (sect_size << 1)) % 2 == 0) ? "UP" : "DOWN"),
			print_array(array + offset, (sect_size << 1));
	}
}
/**/

/**
 * bitonic_sort - an implementation of the bitonic sort algorithm
 *
 * @array: the input array of numbers
 * @size: the size of the input
 */
/**/
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	comparision_merge(array, size, 0, size, true);
}
/**/

/*#define TEST*/

#ifdef TEST
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {100, 93, 40, 57, 14, 58, 85, 54,
					31, 56, 46, 39, 15, 26, 78, 13};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	bitonic_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
#endif
