#include "sort.h"

/**
 * max - get the max elementthe array.
 * @array: array to get the max.
 * @size: size of the array.
 * Return: return max of the array.
 */

size_t max(int *array, size_t size)
{
	size_t i;
	int max;

	max = 0;
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * counting_sort2 - counting sort algorithm.
 * @array: array that will be sorted.
 * @size: size of the array.
 * @digit: exponent to split and control over the eles digits.
 */

void counting_sort2(int *array, size_t size, int digit)
{
	size_t i;
	int *sorted;
	int freq[10] = {0};

	if (!array || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return;

	/* count frequency for every digit on the ele */
	for (i = 0; i < size; i++)
	{
		freq[array[i] / digit % 10] += 1;
	}
	/* count position for every ele regarding the frequency */
	for (i = 1; i < 10; i++)
		freq[i] += freq[i - 1];

	/* sort the ele due it's position in the frequency array */
	for (i = size - 1; (int)i >= 0; i--)
		sorted[--freq[array[i] / digit % 10]] = array[i];
	/* fill the main array with the sorted eles and free the temp array*/
	for (i = 0; i < size; i++)
		array[i] = sorted[i];
	print_array(array, size);
	free(sorted);
}

/**
 * radix_sort - radix sort algorithm.
 * @array: array that will be sortd.
 * @size: size of the array.
 */
void radix_sort(int *array, size_t size)
{
	size_t digit, maxNum;

	if (!array || size < 2)
		return;
	maxNum = max(array, size);
	for (digit = 1; (maxNum / digit) > 0; digit *= 10)
	{
		counting_sort2(array, size, digit);
	}
}
