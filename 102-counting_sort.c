#include "sort.h"

/**
* counting_sort - sorts an array of integers in ascending order using the
* Counting sort algorithm
* @array: array to sort
* @size: size of the array
*/
void counting_sort(int *array, size_t size)
{
	int *count_array = NULL, *output_array = NULL;

	size_t i, max_value = 0;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
		max_value = (int)array[i] > max_value ? (int)array[i] : max_value;

	count_array = calloc(max_value + 1, sizeof(int));
	output_array = malloc(size * sizeof(int));

	if (count_array == NULL || output_array == NULL)
		return;

	for (i = 0; i < size; i++)
		count_array[array[i]]++;

	for (i = 1; i <= max_value; i++)
		count_array[i] += count_array[i - 1];

	for (i = 0; i < size; i++)
	{
		output_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output_array[i];

	print_array(array, size);

	free(count_array);
	free(output_array);
}
