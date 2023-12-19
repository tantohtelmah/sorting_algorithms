#include "sort.h"

/**
* cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
* ascending order using the cocktail shaker algorithm. (1==True, 0==False)
* @list: A pointer to the head of a listint_t doubly-linked list.
*/

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);

void cocktail_sort_list(listint_t **list)
{
	listint_t *start = NULL, *end = NULL, *shaker = NULL;
	int swapped = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	printf("i am here incode\n");

	while (swapped == 0 || end->prev != start)
	{
		printf("i am here while\n");
		swapped = 0;
		for (shaker = start; shaker != end; shaker = shaker->next)
		{
			printf("i am here for\n");
			if (shaker->n > shaker->next->n)
			{
				printf("i am here if\n");
				swap_node_ahead(list, &end, &shaker);
				swapped = 1;
				print_list(*list);
			}
		}
		if (swapped == 0)
			break;
		swapped = 0;
		end = end->prev;
		for (shaker = end; shaker != start; shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_behind(list, &start, &shaker);
				swapped = 1;
				print_list(*list);
			}
		}
		start = start->next;
	}
}

/**
* swap_node_ahead - Swap a node with the one after it.
* @list: A pointer to the head of a listint_t doubly-linked list.
* @tail: A pointer to the tail of a listint_t doubly-linked list.
* @shaker: A pointer to the node to swap.
*/
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;

	if ((*shaker)->prev)
		(*shaker)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*shaker)->prev;
	(*shaker)->prev = tmp;
	(*shaker)->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = *shaker;
	else
		*tail = *shaker;
	tmp->next = *shaker;
	printf("i am here");
}

/**
* swap_node_behind - Swap a node with the one before it.
* @list: A pointer to the head of a listint_t doubly-linked list.
* @tail: A pointer to the tail of a listint_t doubly-linked list.
* @shaker: A pointer to the node to swap.
*/
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->prev;

	if ((*shaker)->next)
		(*shaker)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*shaker)->next;
	(*shaker)->next = tmp;
	(*shaker)->prev = tmp->prev;
	if (tmp->prev)
		tmp->prev->next = *shaker;
	else
		*list = *shaker;
	tmp->prev = *shaker;
}
