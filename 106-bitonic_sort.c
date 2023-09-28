#include "sort.h"

void swap(int *array, int i, int j);

/**
 * swap - Swaps two elements in an array
 * @array: The array
 * @i: Index of the first element to swap
 * @j: Index of the second element to swap
 */
void swap(int *array, int i, int j)
{
	int temp = array[i];

	array[i] = array[j];
	array[j] = temp;
}

/**
 * bitonic_merge - Merges two subarrays in ascending or descending order
 * @array: The array
 * @low: Starting index of the first subarray
 * @count: Number of elements to merge
 * @up: 1 for ascending order, 0 for descending order
 */
void bitonic_merge(int *array, int low, int count, int up)
{
	int i;

	if (count > 1)
	{
		int k = count / 2;

		for (i = low; i < low + k; i++)
		{
			if ((array[i] > array[i + k]) == up)
				swap(array, i, i + k);
		}
		bitonic_merge(array, low, k, up);
		bitonic_merge(array, low + k, k, up);
	}
}

/**
 * bitonic_sort_recursive - Recursively sorts a bitonic sequence
 * @array: The array to sort
 * @low: Starting index of the subarray
 * @count: Number of elements in the subarray
 * @up: 1 for ascending order, 0 for descending order
 */
void bitonic_sort_recursive(int *array, int low, int count, int up)
{
	if (count > 1)
	{
		int k = count / 2;

		bitonic_sort_recursive(array, low, k, 1);
		bitonic_sort_recursive(array, low + k, k, 0);
		bitonic_merge(array, low, count, up);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using Bitonic sort
 * @array: The array to sort
 * @size: The size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	int up, k, i, step;

	if (array == NULL || size < 2)
		return;

	up = 1;

	printf("Merging [1/%lu] (UP):\n", size);
	print_array(array, size);

	for (step = 2; step <= (int)size; step <<= 1)
	{
		for (k = step / 2; k > 0; k >>= 1)
		{
			for (i = 0; i < (int)size; i += step)
			{
				if ((i / step) % 2 == 0)
				{
					bitonic_sort_recursive(array + i, k, k, up);
				}
				else
				{
					bitonic_sort_recursive(array + i, k, k, !up);
				}
			}

			printf("Result [%d/%lu] (%s):\n", step, size, up ? "UP" : "DOWN");
			print_array(array, size);
		}

		up = !up;
	}
}
