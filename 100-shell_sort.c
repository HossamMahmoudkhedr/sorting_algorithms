#include "sort.h"

/**
 * knuth_seq - it generates a knuth sequence for consumption by shell sort
 *
 * @size: the size of input
 * Return: the created sequence of numbers
 */
size_t *knuth_seq(size_t size)
{
	/* seq = { (3^k - 1)/2 | k = 0,1,2,... ^ (3^k - 1)/2 < ceil(size / 3) } */
	size_t i, pow_3 = 3, *seq_arr, seq_size = 0;

	/* printf("%ld\n", size); */
	size = 2 * ceil(size / 3) + 1;
	/* printf("%ld\n", size); */
	while (size)
		seq_size++, size /= 3;
	seq_arr = calloc(seq_size + 1, sizeof(size_t));
	/* printf("%ld\n", seq_size); */
	for (i = 0; i < seq_size; i++)
	{
		seq_arr[seq_size - i - 1] = (pow_3 - 1) / 2;
		pow_3 *= 3;
	}
	/* for (i = 0; i < seq_size; i++) printf("%ld-", seq_arr[i]); */
	return (seq_arr);
}

/**
 * shell_sort - an implementation of the shell sort algorithm
 *
 * @array: the input array of numbers
 * @size: the size of the input
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap, *arr = knuth_seq(size), *gaps;
	int temp;

	gaps = arr;
	/*** Credits for pseudocode goes to the wikipedia page writer ***/

	for (gap = *gaps; gap != 0; gap = *(++gaps))
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; (j >= gap) && (array[j - gap] > temp); j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
	}
	free(arr);
}

#define TEST

#ifdef TEST
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7,
		/*
		*20, 59, 10, 29, 98, 24, 88, 100, 0, 30, 37, 23, 41,
		*57, 49, 84, 21, 50, 20, 51, 60, 12, 90, 10, 21, 19,
		*513, 120, 239, 511
		*/};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	shell_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
#endif
