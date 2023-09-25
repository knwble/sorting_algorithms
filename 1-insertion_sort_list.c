#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *						order using the Insertion Sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each time you swap two elements.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		prev = current->prev;
		while (prev != NULL && prev->n > current->n)
		{
			temp = prev->prev;
			if (temp != NULL)
				temp->next = current;
			else
				*list = current;

			prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = prev;

			current->prev = temp;
			current->next = prev;
			prev->prev = current;

			print_list((const listint_t *)*list);

			prev = temp;
		}

		current = current->next;
	}
}
