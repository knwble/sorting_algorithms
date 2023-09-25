#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a doubly linked list.
 * @list: A pointer to the head of the doubly linked list.
 * @a: The first node to swap.
 * @b: The second node to swap.
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a == b)
		return;

	if (a->prev != NULL)
		a->prev->next = b;
	else
		*list = b;

	if (b->prev != NULL)
		b->prev->next = a;
	else
		*list = a;

	if (a->next != NULL)
		a->next->prev = b;

	if (b->next != NULL)
		b->next->prev = a;

	listint_t *temp = a->next;

	a->next = b->next;
	b->next = temp;

	temp = a->prev;
	a->prev = b->prev;
	b->prev = temp;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		insert = current->prev;

		while (insert != NULL && insert->n > current->n)
		{
			insert = insert->prev;
		}

		if (insert == NULL)
		{
			listint_t *next_node = current->next;

			swap_nodes(list, current, current->prev);
			current = next_node;
		}
		else if (insert->next != current)
		{
			listint_t *next_node = current->next;

			swap_nodes(list, current, insert->next);
			current = next_node;
		}

		print_list((const listint_t *)*list);
	}
}
