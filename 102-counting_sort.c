#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                 the Counting Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int max = 0, i;
	int *count_array = NULL;
	int *output_array = NULL;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum element in the array */
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count_array = malloc(sizeof(int) * (max + 1));
	output_array = malloc(sizeof(int) * size);

	if (count_array == NULL || output_array == NULL)
		return;

	/* Initialize count_array with zeros */
	for (i = 0; i <= max; i++)
		count_array[i] = 0;

	/* Count the occurrences of each element in array */
	for (i = 0; i < (int)size; i++)
		count_array[array[i]]++;

	/* Update count_array to store the cumulative sum */
	for (i = 1; i <= max; i++)
		count_array[i] += count_array[i - 1];

	/* Build the output array using the count_array */
	for (i = (int)size - 1; i >= 0; i--)
	{
		output_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}

	/* Copy the sorted elements back to the original array */
	for (i = 0; i < (int)size; i++)
		array[i] = output_array[i];

	printf("%d", count_array[0]);
	for (i = 1; i <= max; i++)
		printf(", %d", count_array[i]);
	printf("\n");

	/* Free allocated memory */
	free(count_array);
	free(output_array);
}
