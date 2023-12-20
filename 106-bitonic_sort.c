#include "sort.h"

void bitonic_merge(int arr[], size_t n, int up)
{

	if (n > 1)
	{
		size_t m = n / 2;

		for (size_t i = 0; i < m; ++i)
		{
			if ((arr[i] > arr[i + m]) == up)
				swap(&arr[i], &arr[i + m]);
		}
		bitonic_merge(arr, m, up);
		bitonic_merge(arr + m, m, up);
	}
}

void bitonic_sort(int *array, size_t size)
{

	if (size > 1)
	{
		size_t m = size / 2;

		bitonic_sort(array, m);
		bitonic_sort(array + m, m);
		bitonic_merge(arr, n, up);
	}
}
