#include "sort.h"

void swap(int *a, int *b);
void max_heapify(int arr[], size_t heap_size, size_t i);
void build_max_heap(int arr[], size_t size);

/**
 * heap_sort - sorts an array
 * @arr: array to be sorted
 * @size: size of the array
 * Return: void
*/

void heap_sort(int arr[], size_t size)
{
	int i;

	build_max_heap(arr, size);

	for (i = size - 1; i > 0; --i)

	{
		swap(&arr[0], &arr[i]);
		max_heapify(arr, i, 0);
		print_array(arr, size);
	}
}

/**
 * swap - swaps elements
 * @a: first element
 * @b: second element
 * Return: void
*/
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * max_heapify - heapify
 * @arr: array to be sorted
 * @heap_size: size of the array
 * @i: counter
 * Return: void
*/

void max_heapify(int arr[], size_t heap_size, size_t i)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < heap_size && arr[left] > arr[largest])
		largest = left;

	if (right < heap_size && arr[right] > arr[largest])
		largest = right;

	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		max_heapify(arr, heap_size, largest);
	}
}

/**
 * build_max_heap - builds max heap
 * @arr: array to be sorted
 * @size: size of the array
 * Return: void
*/

void build_max_heap(int arr[], size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; --i)

		max_heapify(arr, size, i);
}
