#include "sort.h"
/**
 * partition - make the left less than pivot and the right greater
 * @array: array to be sorted
 * @low: start of the array
 * @high: end of the array
 * @size: size of the array
 * Return: pivot index of the array
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	i = low - 1;
	pivot = array[high];
	j = high + 1;
	while (true)
	{
		do
		{
			i++;
		} while (array[i] < pivot);
		do
		{
			j--;
		} while (array[j] > pivot);
		if (i > j)
			return (j);
		if (array[i] != array[j])
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
}
/**
 * quick_sort_helper - recursion on the array and sort
 * @array: array to be sorted
 * @low: start of the array
 * @high: end of the array
 * @size: size of the array
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int part;

	if (low < high)
	{
		part = partition(array, low, high, size);
		quick_sort_helper(array, low, part, size);
		quick_sort_helper(array, part + 1, high, size);
	}
}
/**
 * quick_sort_hoare - quick sort hoare algorithm
 * @array: array that will be sorted
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	quick_sort_helper(array, 0, size - 1, size);
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
