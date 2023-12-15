#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current->prev;
		while (temp != NULL && temp->n > current->n)
		{
			if (temp->prev != NULL)
				temp->prev->next = current;
			else
				*list = current;

			current->prev = temp->prev;
			temp->prev = current;
			temp->next = current->next;

			if (current->next != NULL)
				current->next->prev = temp;

			current->next = temp;
			temp = current->prev;

			print_list(*list);
		}
		current = current->next;
	}
}
