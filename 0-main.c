#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
* main - Entry point
*
* Return: Always 0
*/
int main(void)
{
	int array[] = {19};

	size_t n = sizeof(array) / sizeof(array[0]);
	size_t a = 0;

	bubble_sort(array, a);

	print_array(array, n);
	printf("\n");
	bubble_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
