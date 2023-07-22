#include "sort.h"

/**
 * insertion_sort_list - insertion sort algorithm
 * @listint_t: list that will be sorted
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *i = (*list)->next;
    listint_t *j;
    while (i != NULL)
    {
        j = i;
        while (j->prev != NULL && j->n < j->prev->n)
        {
            swap_list(list, j, j->prev);
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
	x->prev = y->prev;
	y->next = x->next;
	if (x->next)
		x->next->prev = y;
	y->prev = x;
	x->next = y;
	if (!x->prev)
		*list = x;
	else
		x->prev->next = x;
}
