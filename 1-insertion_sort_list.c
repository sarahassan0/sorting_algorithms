#include "sort.h"

/**
 * insertion_sort_list - insertion sort algorithm
 * @list: list that will be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j;

	if (!list)
		return;
	i = (*list)->next;

	while (i != NULL && list)
	{
		j = i;
		while (j->prev != NULL && j->n < j->prev->n)
		{
			swap_list(list, j->prev, j);
			print_list(*list);
		}
		i = i->next;
	}
}

/**
 * swap_list - Swaps the values of two integers using pointers.
 * @list: head of the list
 * @x: Pointer to the first integer.
 * @y: Pointer to the second integer.
 */
void swap_list(listint_t **list, listint_t *x, listint_t *y)
{
	y->prev = x->prev;
	x->next = y->next;
	if (y->next)
		y->next->prev = x;
	x->prev = y;
	y->next = x;
	if (!y->prev)
		*list = y;
	else
		y->prev->next = y;
}
