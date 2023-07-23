#include "sort.h"
/**
 * shell_sort - shell sort algorithm
 * @array: the array that we will sort
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;

	if (size < 2)
		return;
	while (gap * 3 + 1 < size)
	{
		gap  = gap * 3 + 1;
	}
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j > 0 && array[j] < array[j - gap])
			{
				swap(&array[j], &array[j - gap]);
				j-=gap;
			}
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
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
