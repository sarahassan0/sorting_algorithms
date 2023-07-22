#include "sort.h"

/*void insertion_sort(listint_t **list)
{
	listint_t *i, *j;

	for (i = *list->next; i->next ; i = i->next)
	{
		j = i;
		while (j->prev && j->n < j->prev->n)
		{
			swap(&array[j], &array[j - 1]);
			print_array(array, size);
			j = j->prev;
		}
	}
}
**/
 /* swap - Swaps the values of two integers using pointers.
 * @x: Pointer to the first integer.
 * @y: Pointer to the second integer.*/
 /*/
void swap(int *x, int *y)
{
	int tmp = *x;

	*x = *y;
	*y = tmp;
}*/

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
            j = j->prev;
        }
        i = i->next;
    }
}

/**
 * swap_list - Swaps the values of two integers using pointers.
 * @x: Pointer to the first integer.
 * @y: Pointer to the second integer.
 */
/*__attribute__((unused))*/
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
	/*listint_t temp = y->next;

	y->next = x->next;
	x->next = y;
	y->prev = x;
	x->prev = NULL;
	y->next->prev = y;
	*list = x;*/
    /*listint_t *tmp;

    tmp = (*x)->prev;
    (*x)->prev = (*y);
    (*y)->prev = tmp;

    tmp = (*x)->next;
    (*x)->next = (*y)->next;
    (*y)->next = (*x);

    if ((*x)->next != NULL)
        (*x)->next->prev = (*x);
    if ((*y)->prev != NULL)
        (*y)->prev->next = (*y);*/

