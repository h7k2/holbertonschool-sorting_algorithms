#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	current = (*list)->next;

	while (current)
	{
		tmp = current->prev;

		while (tmp && tmp->n > current->n)
		{
			int swap = tmp->n;
			((int *)&tmp->n)[0] = current->n;
			((int *)&current->n)[0] = swap;

			print_list(*list);

			tmp = tmp->prev;
		}
		current = current->next;
	}
}
