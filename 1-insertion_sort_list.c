#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *curr = (*list)->next, *prev, *next_node;

	while (curr)
	{
		next_node = curr->next;
		prev = curr->prev;

		while (prev && prev->n > curr->n)
		{
			prev->next = next_node;
			if (next_node)
				next_node->prev = prev;
			curr->prev = prev->prev;
			curr->next = prev;
			if (prev->prev)
				prev->prev->next = curr;
			else
				*list = curr;
			prev->prev = curr;
			prev->next = next_node;
			if (next_node)
				next_node->prev = prev;
			prev = curr->prev;
			print_list((const listint_t *)*list);
		}

		curr = next_node;
	}
}
