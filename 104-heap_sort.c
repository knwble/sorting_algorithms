#include "sort.h"

/**
 * sift_down - Perform the sift-down operation in a heap.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @start: The index to start the sift-down operation from.
 * @end: The index to end the sift-down operation.
 */
void sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root = start;
	size_t child;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		if (child + 1 <= end && array[child] < array[child + 1])
			child++;

		if (array[root] < array[child])
		{
			int temp = array[root];
			array[root] = array[child];
			array[child] = temp;
			print_array(array, size);
			root = child;
		}
		else
			return;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using
 *             Heap sort Algorithm.
 * @array: The array of intergers to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2; i > 0; i--)
	{
		size_t j = i - 1;
		sift_down(array, size, j, size - 1);
	}

	for (i = size - 1; i > 0; i--)
	{
		int temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		sift_down(array, size, 0, i - 1);
	}
}
