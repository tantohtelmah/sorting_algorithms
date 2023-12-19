#include "sort.h"


void merge(int arr[], int l[], int r[], size_t ls, size_t rs);
void print_array_merge(const int *array, size_t size);

/**
* merge_sort - sorts an array
* @arr: array to be sorted
* @size: size of the array
* Return: void
*/
void merge_sort(int arr[], size_t size)
{
	size_t i, mid;
	int *left, *right;

	if (size <= 1)
		return;

	mid = size / 2;
	left = malloc(mid * sizeof(int));

	right = malloc((size - mid) * sizeof(int));

	for (i = 0; i < mid; ++i)
		left[i] = arr[i];

	for (i = mid; i < size; ++i)
		right[i - mid] = arr[i];

	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge(arr, left, right, mid, size - mid);
	print_array_merge(arr, size);
	free(left);
	free(right);
}

/**
* merge - merges the didvided array
* @arr: final array
* @l: first subarray
* @r:second subarray
* @ls: first subarray's size
* @rs: second subarray's size
* Return: void
*/
void merge(int arr[], int l[], int r[], size_t ls, size_t rs)
{

	size_t i = 0, j = 0, k = 0;

	while (i < ls && j < rs)
	{
		if (l[i] <= r[j])
			arr[k++] = l[i++];
		else
			arr[k++] = r[j++];
	}

	while (i < ls)
		arr[k++] = l[i++];

	while (j < rs)
		arr[k++] = r[j++];
}

/**
* print_array_merge - Prints an array of integers
*
* @array: The array to be printed
* @size: Number of elements in @array
*/
void print_array_merge(const int *array, size_t size)
{
	size_t i;

	i = 0;
	printf("[Done]: ");
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}
