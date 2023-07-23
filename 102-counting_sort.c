#include "sort.h"

/**
 * counting_sort - sort the array using counting sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
int *countArr;
int *sortedArr;
size_t i, j;

countArr = (int*)malloc(sizeof(int) * (size + 1));
sortedArr = (int*)malloc(sizeof(int) * (size + 1));
for (i = 0; i < size; i++)
{
countArr[i] = 0;
sortedArr[i] = 0;
}

print_array(countArr, size);
for (i = 0; i < size - 1; i++)
{
for (j = i + 1; j < size; j++)
{
if (array[i] < array[j])
{
countArr[j] += 1;
}
else
{
countArr[i] += 1;
}
}
print_array(countArr, size);
}

for (i = 0; i < size; i++)
{
sortedArr[countArr[i]] = array[i];
}

for (i = 0; i < size; i++)
{
array[i] = sortedArr[i];
}

free(countArr);
free(sortedArr);
}
