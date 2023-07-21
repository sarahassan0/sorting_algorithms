#include "sort.h"

/**
 * selection_sort - selection sort algorithm
 * @array: array that will be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
    size_t i, j;

    for (i = 0; i < size - 1; i++)
    {
        size_t min = i;

        for (j = i + 1; j < size; j++)
        {
            if (array[min] > array[j])
            {
                min = j;
            }
        }
        swap(&array[min], &array[i]);
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
