#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
	int i;

	i = 0;
	while (list)
	{
		if (i > 0)
			printf(", ");
		printf("%d", list->n);
		++i;
		list = list->next;
	}
	printf("\n");
}
/**
 * swapl - swap 2 nodes of the doubley linked list
 * @n1: pointer to the first node
 * @n2: pointer to the second node
 */
void swapl(listint_t *n1, listint_t *n2)
{

}
