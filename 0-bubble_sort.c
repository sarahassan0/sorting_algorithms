#include "sort.h"

/**
 * bubble_sort - bubble sort algorithm
 * @array: array that will be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, sorted;

	if (size < 2 || !size || !array)
		return;
	for (i = 0; i < size; i++)
	{
		sorted = 1;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				sorted = 0;
			}
		}
		if (sorted)
			return;
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
