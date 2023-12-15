#include "sort.h"

/**
* quick_sort - sort the array in ascending order using the
*    Lomuto partition scheme
* @array: the array to be sorted
* @size: the size of the array
* Return: void
*/
void quick_sort(int *array, size_t size)
{
	int pivot;
	size_t i = -1, j = 0, temp;

	if (size < 2)
	{
		return;
	}

	pivot = array[size - 1];
	while (j < size - 1)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
		j++;
	}
	temp = array[i + 1];
	array[i + 1] = array[size - 1];
	array[size - 1] = temp;
	print_array(array, size);
	quick_sort(array, i + 1);
	quick_sort(array + i + 2, size - i - 2);
}
