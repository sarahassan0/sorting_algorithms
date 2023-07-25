#include "sort.h"

/**
 * merge - compair left and right array elements merge and sort.
 * @array: array to be sorted.
 * @leftArr: left array.
 * @rightArr: right array.
 * @size: size of the main array.
 * @middle: middle of the array.
 */

void merge(int *array, int *leftArr, int *rightArr, size_t size, size_t middle)
{
	size_t i = 0, l = 0, r = 0;

	while (l < middle && r < (size - middle))
	{
		if (leftArr[l] < rightArr[r])
		{
			array[i] = leftArr[l++];
		}
		else
		{
			array[i] = rightArr[r++];
		}
		i++;
	}
	while (l < middle || r < (size - middle))
	{
		if (l < middle)
			array[i] = leftArr[l++];
		if (r < (size - middle))
			array[i] = rightArr[r++];
		i++;
	}
}
/**
 * merge_sort - merge sort algorithm
 * @array: array that will be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t i, l = 0, r = 0, middle = size / 2;
	int *leftArr;
	int *rightArr;

	if (!array || size < 2)
		return;

	leftArr = malloc(middle * sizeof(int));
	rightArr = malloc((size - middle) * sizeof(int));
	for (i = 0; i < size; i++)
	{
		if (i < middle)
			leftArr[l++] = array[i];
		else
			rightArr[r++] = array[i];
	}
	merge_sort(leftArr, middle);
	merge_sort(rightArr, size - middle);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(leftArr, middle);

	printf("[right]: ");
	print_array(rightArr, size - middle);

	merge(array, leftArr, rightArr, size, middle);

	printf("[Done]: ");
	print_array(array, size);
	free(leftArr);
	free(rightArr);
}
