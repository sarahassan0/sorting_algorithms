#include "sort.h"

/**
 * quick_sort - quick sort algorithm
 * @array: array that will be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
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
