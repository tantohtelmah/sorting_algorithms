#include "sort.h"
/**
* selection_sort - sorts an array by repeatedly selectiong
*                  smallest and/or largest
* @array: array to be sorted
* @size: size of the array
* Return: void
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx, temp;

	if (size == 0 || array == NULL)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}
		if (min_idx != i)
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;
		}
		print_array(array, size);
	}
	printf("\n");
}
