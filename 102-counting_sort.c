#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                the Counting Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	/* Find the maximum value in the input array */
	int max = array[0];
	for (size_t i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Create a counting array and initialize it to zero */
	int *count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;

	for (int i = 0; i <= max; i++)
		count[i] = 0;

	/* Count the occurrences of each element in the input array */
	for (size_t i = 0; i < size; i++)
		count[array[i]]++;

	/* Reconstruct the sorted array from the counting array */
	int index = 0;
	for (int i = 0; i <= max; i++)
	{
		while (count[i] > 0)
		{
			array[index] = i;
			index++;
			count[i]--;
		}
	}

	free(count);
}
