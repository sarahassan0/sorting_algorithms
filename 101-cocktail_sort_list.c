#include "sort.h"
/**
 * cocktail_sort_list - cocktail_sort_list
 * @list: list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *j, *k, *i = *list;

	if (!list)
		return;
	for (; i; i = i->next)
	{
		j = *list;
		for (; j->next;)
		{
			if (j->n > j->next->n)
			{
				swap_list(list, j, j->next);
				print_list(*list);
				continue;
			}
			j = j->next;
		}
		for (k = j; k->prev ;)
		{
			if (k->n < k->prev->n)
			{
				swap_list(list, k->prev, k);
				print_list(*list);
				continue;
			}
			k = k->prev;
		}
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
