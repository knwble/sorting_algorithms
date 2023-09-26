#include "sort.h"

/**
 * merge - Merge two subarrays into one sorted array
 * @array: The original array to merge into
 * @size: The size of the array
 * @left: Pointer to the left subarray
 * @right: Pointer to the right subarray
 */
static void merge(int *array, size_t size, int *left, int *right)
{
	size_t i = 0, j = 0, k = 0;
	size_t left_size = size / 2;
	size_t right_size = size - left_size;
	int *temp = malloc(sizeof(int) * size);

	if (!temp)
		exit(EXIT_FAILURE);

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			temp[k] = left[i++];
		else
			temp[k] = right[j++];
		k++;
	}

	while (i < left_size)
		temp[k++] = left[i++];

	while (j < right_size)
		temp[k++] = right[j++];

	for (i = 0; i < size; i++)
		array[i] = temp[i];

	free(temp);
}

/**
 * merge_sort - Sort an array of integers in ascending order
 *               using the Merge sort algorithm.
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	size_t middle = size / 2;
	int *left = array;
	int *right = array + middle;

	printf("Merging...\n[left]: ");
	for (size_t i = 0; i < middle; i++)
	{
		printf("%d", left[i]);
		if (i < middle - 1)
			printf(", ");
	}
	printf("\n[right]: ");
	for (size_t i = 0; i < size - middle; i++)
	{
		printf("%d", right[i]);
		if (i < size - middle - 1)
			printf(", ");
	}
	printf("\n");

	merge_sort(left, middle);
	merge_sort(right, size - middle);
	merge(array, size, left, right);

	printf("[Done]: ");
	for (size_t i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i < size - 1)
			printf(", ");
	}
	printf("\n");
}
