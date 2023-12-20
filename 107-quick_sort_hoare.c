#include "sort.h"

int hoare_partition(int arr[], int low, int high)

	int pivot = arr[high];

	int i = low - 1;

	int j = high + 1;

	while (1)
	{
		do

			i++;
		}
		while (arr[i] < pivot);

		do
		{
			j--;
		} 
		while (arr[j] > pivot);

		if (i >= j)
			return (j);

		swap(&arr[i], &arr[j]);
	}
}

void quick_sort_hoare(int arr[], int low, int high) {

	if (low < high) {
		int pi = hoare_partition(arr, low, high);

		quick_sort_hoare(arr, low, pi);
		quick_sort_hoare(arr, pi + 1, high);
	}
}
