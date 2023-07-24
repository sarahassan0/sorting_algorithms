#include "sort.h"
size_t max(int *array, size_t size);
/**
 * counting_sort - counting sort algo
 * @array: array that will be sorted
 * @size: sizethe array
 */
void counting_sort(int *array, size_t size)
{
	size_t i, freq_len = max(array, size);
	int *sorted;
	int *freq;

       	sorted = malloc(sizeof(int) * size);
       	freq = malloc((freq_len + 1) * sizeof(int));
	if (!sorted || !freq || !array || size < 2)
		return;
	for (i = 0; i < size; i++)
		freq[array[i]] += 1;
	for (i = 1; i <= freq_len; i++)
		freq[i] += freq[i - 1];
	print_array(freq, freq_len + 1);
	for (i = size - 1; (int)i >= 0; i--)
		sorted[--freq[array[i]]] = array[i];
	for (i = 0; i < size; i++)
		array[i] = sorted[i];
	free(sorted);
	free(freq);
}
/**
 * max - get the max elementthe array
 * @array: array to get the max
 * @size: size of the array
 * Retuen: return max of the array
 */
size_t max(int *array, size_t size)
{
	size_t i;
	int max;

	max = array[0];
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}
