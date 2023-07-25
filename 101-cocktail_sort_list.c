#include "sort.h"

/**
 * swap - swaps the place of two nodes inside of a doubly linked list
 *
 * @N1: the first node
 * @N2: the second node
 */
void swap(listint_t *N1, listint_t *N2)
{
	if (!N1 || !N2)
		return;
	if (N1->next == N2)
	{
		if (N2->next)
			(N2->next)->prev = N1;
		if (N1->prev)
			(N1->prev)->next = N2;
		N1->next = N2->next, N2->next = N1;
		N2->prev = N1->prev, N1->prev = N2;
	}
	else if (N2->next == N1)
	{
		swap(N2, N1);
	}
	else
	{
		/* no time for general swapping now lol */
	}
}

/**
 * cocktail_sort_list - an implementation of the cocktail shaker sort algorithm
 *
 * @list: the input list
 */
#ifndef OLDCODE
void cocktail_sort_list(listint_t **list)
{
	listint_t *current/*, *min, *f_end = NULL, *b_end = NULL*/;
	bool swapped;

	if (!list || !(*list) || !((*list)->next))
		return;

	current = *list;
	do {
		swapped = false;
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap(current, current->next), swapped = true;
				current = current->prev;
				if ((*list)->prev != NULL)
					while ((*list)->prev != NULL)
						*list = (*list)->prev;
				print_list(*list);
			}
			current = current->next;
		}
		if (!swapped)
			break;
		swapped = false;
		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				swap(current->prev, current), swapped = true;
				current = current->next;
				if ((*list)->prev != NULL)
					while ((*list)->prev != NULL)
						*list = (*list)->prev;
				print_list(*list);
			}
			current = current->prev;
		}
	} while (swapped);
}
#else
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *min, *f_end = NULL, *b_end = NULL;
	bool swapped;

	if (!list || !(*list) || !((*list)->next))
		return;
	minmax = current = *list;
	do {
		while (current->next != f_end)
			minmax = (current->n > minmax->n) ? current : minmax,
			current = current->next;
		if (minmax != current)
		{
			if (minmax->next != NULL)
				minmax->next->prev = minmax->prev;
			if (minmax->prev != NULL)
				minmax->prev->next = minmax->next;
			minmax->next = current->next, minmax->prev = current;
			f_end = current->next = minmax;
		}
		else
			current = current->prev;
		while (current->prev != b_end)
			minmax = (current->n < minmax->n) ? current : minmax,
			current = current->prev;
		if (minmax != current)
		{
			if (minmax->next != NULL)
				minmax->next->prev = minmax->prev;
			if (minmax->prev != NULL)
				minmax->prev->next = minmax->next;
			minmax->prev = current->prev, minmax->next = current;
			b_end = current->prev = minmax;
		} else
			current = current->next;
	} while (f_end->next != b_end);
}
#endif

/*#define TEST*/

#ifdef TEST
/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
	listint_t *list;
	listint_t *node;
	int *tmp;

	list = NULL;
	while (size--)
	{
		node = malloc(sizeof(*node));
		if (!node)
			return (NULL);
		tmp = (int *)&node->n;
		*tmp = array[size];
		node->next = list;
		node->prev = NULL;
		list = node;
		if (list->next)
			list->next->prev = list;
	}
	return (list);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	listint_t *list;
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);

	list = create_listint(array, n);
	if (!list)
		return (1);
	print_list(list);
	printf("\n");
	cocktail_sort_list(&list);
	printf("\n");
	print_list(list);
	return (0);
}
#endif
