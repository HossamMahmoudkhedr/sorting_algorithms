#include "sort.h"

#define parent(node_idx) (((node_idx) - 1) / 2)
#define lchild(node_idx) (2 * (node_idx) + 1)
#define rchild(node_idx) (2 * (node_idx) + 2)

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
 * siftDown - affirms the heap property on a certain rooted range of the array
 *
 * @array: the input array of numbers
 * @start: the start index of the array
 * @end: the end index of the array
 * @size: the full size of the array
 */
void siftDown(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start, child, candidate;

	while (lchild(root) <= end)
	{
		child = lchild(root);	/*Left child of root*/
		candidate = root;		/*Keeps track of child to swap with*/

		if (array[candidate] < array[child])
			candidate = child;
		/*If there is a right child and that child is greater*/
		if (child + 1 <= end && array[candidate] < array[child + 1])
			candidate = child + 1;
		/*
		* The root holds the largest element.
		* Since we assume the heaps rooted at the
		* children are valid, this means that we are done.
		*/
		if (candidate == root)
			return;
		swap(&array[root], &array[candidate]);
		print_array(array, size);
		root = candidate;	/*repeat to continue sifting down the child now)*/
	}
}

/**
 * buildMaxHeap - transforms an array into an in-place min-heap data structure
 *
 * @array: the input array of numbers
 * @size: the size of the input
 */
void buildMaxHeap(int *array, size_t size)
{
	int start = parent(size - 1);

	while (start >= 0)
		siftDown(array, start, size - 1, size),
		start--;
}

/**
 * heap_sort - an implementation of the heap sort algorithm
 *
 * @array: the input array of numbers
 * @size: the size of the input
 */
void heap_sort(int *array, size_t size)
{
	size_t end = size - 1;

	buildMaxHeap(array, size);
	while (end)
	{
		swap(&array[0], &array[end]);
		print_array(array, size);
		--end;
		siftDown(array, 0, end, size);
	}
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
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	heap_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
#endif
