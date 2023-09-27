#include "sort.h"

int get_max(int *array, size_t size);
void radix_sort(int *array, size_t size);

/**
 * get_max - Get the maximum value in an array.
 * @array: The array of integers.
 * @size: The size of the array.
 * Return: The maximum value in the array.
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - Sort an array of integers using counting sort.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 * @exp: The current digit position being considered (1, 10, 100, ...).
 */
void counting_sort(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};
	int i;

	if (!output)
		return;

	for (i = 0; i < (int)size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using
 *              the LSD Radix Sort algorithm.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (!array || size < 2)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort(array, size, exp);
		print_array(array, size);
	}
}
