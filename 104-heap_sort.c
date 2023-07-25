#include "sort.h"

void heapify(int *array, size_t size, size_t last_index, size_t i)
{
	size_t max = i, left = i * 2 + 1, right = i * 2 + 2;

	if (left < last_index && array[left] > array[max])
		max = left;
	if (right < last_index && array[right] > array[max])
		max = right;
	if (i != max)
	{
		swap(&array[max], &array[i]);
		print_array(array, size);
		heapify(array, size, last_index, max);
	}
}
/**
 * heap_sort - sorting heap
 * @array: array that will be sortd
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (size < 2)
		return;
	for (i = size / 2 - 1; (int)i >= 0; i--)
	{
		heapify(array, size, size, i);
	}

	for (i = size - 1; (int)i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, size, i, 0);
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
