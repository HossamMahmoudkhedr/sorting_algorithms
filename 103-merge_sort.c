#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * sortArr - sort the divided array
 *
 * @l: lower index
 * @m: middle index
 * @h: higher index
 * @dest: destination for the data
 * @src: input data
 * Return: void
 */
void sortArr(size_t l, size_t m, size_t h, int *dest, int *src)
{
size_t i = 0, j = 0, k = 0;

printf("Merging...\n");
printf("[left]: ");
print_array(src + l, m - l);
printf("[right]: ");
print_array(src + m, h - m);
i = l;
j = m;
k = l;

for (; k < h; k++)
{
if (i < m && (j >= h || src[i] <= src[j]))
{
dest[k] = src[i];
i++;
}
else
{
dest[k] = src[j];
j++;
}
}
printf("[Done]: ");
print_array(dest + l, h - l);
}

/**
* divArray - divide the array to sub arrays
*
* @l: lower index
* @h: higher index
* @array: the array to be divided
* @copy: the copy of the array
*/
void divArray(size_t l, size_t h, int *array, int *copy)
{
size_t m = 0;

if (h - l < 2)
{
return;
}
m = (l + h) / 2;
divArray(l, m, array, copy);
divArray(m, h, array, copy);
sortArr(l, m, h, array, copy);
for (m = l; m < h; m++)
{
copy[m] = array[m];
}
}

/**
* merge_sort - merge the arrays
*
* @array: the array
* @size: the size of the array
*/
void merge_sort(int *array, size_t size)
{
size_t i = 0;
int *copy = NULL;

if (array == NULL || size < 2)
{
return;
}

copy = malloc(sizeof(int) * size);

if (copy == NULL)
{
return;
}

for (; i < size; i++)
{
copy[i] = array[i];
}
divArray(0, size, array, copy);
free(copy);
}
