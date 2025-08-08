#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		prev = current->prev;
		while (prev && current->n < prev->n)
		{
			if (current->next)
				current->next->prev = prev;
			prev->next = current->next;

			current->prev = prev->prev;
			current->next = prev;

			if (prev->prev)
				prev->prev->next = current;
			prev->prev = current;

			if (current->prev == NULL)
				*list = current;

			print_list(*list);
			prev = current->prev;
		}
		current = current->next;
	}
}
