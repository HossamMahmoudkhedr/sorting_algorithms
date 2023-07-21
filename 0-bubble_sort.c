#include "sort.h"
/**
 * bubble_sort - sort an array using bubble sort
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */

void bubble_sort(int *array, size_t size)
{
size_t i, l;
int temp;
for (l = 0; l < size; l++){
for (i = 0; i < size - 1; i++)
{
if (array[i] > array[i + 1])
{
temp = array[i];
array[i] = array[i + 1];
array[i + 1] = temp;
print_array(array, size);
}
}
}
}
