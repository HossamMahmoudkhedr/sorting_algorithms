#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 * Return: void
 */
void swap_ints(int *a, int *b)
{
int tmp;

tmp = *a;
*a = *b;
*b = tmp;
}

/**
* hoare_partition - Order a subset of an array of integers
*                   according to the hoare partition scheme.
* @array: The array of integers.
* @size: The size of the array.
* @l: The starting index of the subset to order.
* @r: The ending index of the subset to order.
*
* Return: The final partition index.
*/
int hoare_partition(int *array, size_t size, int l, int r)
{
int pivot, above, below;

pivot = array[r];
for (above = l - 1, below = r + 1; above < below;)
{
do {
above++;
} while (array[above] < pivot);
do {
below--;
} while (array[below] > pivot);

if (above < below)
{
swap_ints(array + above, array + below);
print_array(array, size);
}
}

return (above);
}

/**
* hoare_sort - Implement the quicksort algorithm through recursion.
* @array: An array of integers to sort.
* @size: The size of the array.
* @l: The starting index of the array partition to order.
* @r: The ending index of the array partition to order.
* Return: void
*/
void hoare_sort(int *array, size_t size, int l, int r)
{
int part;

if (r - l > 0)
{
part = hoare_partition(array, size, l, r);
hoare_sort(array, size, l, part - 1);
hoare_sort(array, size, part, r);
}
}

/**
* quick_sort_hoare - Sort an array of integers in ascending
*                    order using the quicksort algorithm.
* @array: An array of integers.
* @size: The size of the array.
* Return: void
*/
void quick_sort_hoare(int *array, size_t size)
{
if (array == NULL || size < 2)
{
return;
}

hoare_sort(array, size, 0, size - 1);
}
