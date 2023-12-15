#include "sort.h"

/**
* bubble_sort - sorts the arrays using the bubble sorting algorithm
*
* @array: the arrya to be sorted
* @size: the size of the array to be sorted
* Return: void
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;

	if (size < 2 || array == NULL)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
			print_array(array, size);
		}
	}
}
