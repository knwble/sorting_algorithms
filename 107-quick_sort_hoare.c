#include "sort.h"

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 *                    using the Quick sort algorithm with Hoare partition.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_hoare(array, 0, size - 1, size);
}

/**
 * quicksort_hoare - Implements the Quick sort algorithm with Hoare partition.
 * @array: The array to be sorted.
 * @low: The starting index of the partition to be sorted.
 * @high: The ending index of the partition to be sorted.
 * @size: The size of the array.
 */
void quicksort_hoare(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = hoare_partition(array, low, high, size);

		quicksort_hoare(array, low, pivot_index, size);
		quicksort_hoare(array, pivot_index + 1, high, size);
	}
}

/**
 * hoare_partition - Partitions the array using the Hoare partition scheme.
 * @array: The array to be sorted.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array.
 *
 * Return: The pivot index.
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[low];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		swap_ints(array + i, array + j);
		print_array(array, size);
	}
}

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}
