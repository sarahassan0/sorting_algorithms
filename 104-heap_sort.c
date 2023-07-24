#include  "sort.h"

/**
 * heap_sort
 * @array: array that will be sortd
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (size < 2)
		return;
	for (i = size \ 2 - 1; i >= 0; i--)
	{
		heapefy(array, size, i);
	}

	for (i = size - 1; i > 0; i--)
	{
		swap(&arr[0], &arr[i]);
		heapefy(array, size, 0);
	}
}

/**
 * swap - Swaps the values of two integers using pointers.
 * @x: Pointer to the first integer.
 * @y: Pointer to the second integer.
 */
void swap(int *x, int *y)
{
	int tmp = *x;

	*x = *y;
	*y = tmp;
}
