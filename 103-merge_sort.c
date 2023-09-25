#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * merge - Merge two subarrays into one sorted array
 * @array: The original array to merge into
 * @size: The size of the array
 * @left: Pointer to the left subarray
 * @right: Pointer to the right subarray
 */
void merge(int *array, size_t size, int *left, int *right)
{
	size_t i = 0, j = 0, k = 0;
	size_t left_size = size / 2;
	size_t right_size = size - left_size;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < left_size)
	{
		array[k] = left[i];
		i++;
		k++;
	}

	while (j < right_size)
	{
		array[k] = right[j];
		j++;
		k++;
	}

	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - Sort an array of integers in ascending order
 *               using the Merge sort algorithm.
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return;

	size_t middle = size / 2;
	int *left = array;
	int *right = array + middle;

	merge_sort(left, middle);
	merge_sort(right, size - middle);
	merge(array, size, left, right);
}
