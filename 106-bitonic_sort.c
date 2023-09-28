#include "sort.h"

void swap(int *array, int i, int j);

void swap(int *array, int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

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
