#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail shaker sort algorithm.
 * @list: A pointer to the head of the doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;

	listint_t *start = NULL;
	listint_t *end = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		for (start = *list; start->next != end; start = start->next)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, &start, start->next);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
		}
		if (!swapped)
			break;

		swapped = 0;
		end = start;
		for (start = end->prev; start != NULL; start = start->prev)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, &start, start->next);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
		}
	} while (swapped);
}
