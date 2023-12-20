#include "sort.h"

void countSort(int arr[], size_t n, int exp);
int getMax(int arr[], size_t n);

/**
 * radix_sort - sorts an array
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
*/

void radix_sort(int *array, size_t size)
{
	int exp;

	int m;

	m = getMax(array, size);

	for (exp = 1; m / exp > 0; exp *= 10)
	{
		countSort(array, size, exp);
		print_array(array, size);
	}
}
/**
 * getMax - gets max in array an array
 * @arr: array to be sorted
 * @n: size of the array
 * Return: void
*/

int getMax(int arr[], size_t n)
{
	size_t i;
	int mx;

	mx = arr[0];

	for (i = 1; i < n; ++i)
	{
		if (arr[i] > mx)
			mx = arr[i];
	}
	return (mx);
}

/**
 * countSort - counts sorts
 * @arr: array to be sorted
 * @n: size of the array
 * @exp: exp
 * Return: void
*/
void countSort(int arr[], size_t n, int exp)
{
	int *output;
	size_t i;
	int count[10] = {0};

	output = malloc(n * sizeof(int));
	if (output == NULL)
		exit(EXIT_FAILURE);

	for (i = 0; i < n; ++i)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; ++i)
		count[i] += count[i - 1];

	for (i = n - 1; (int)i >= 0; --i)
	{

		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < n; ++i)
		arr[i] = output[i];

	free(output);
}
