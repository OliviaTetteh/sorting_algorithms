#include "sort.h"

/**
 * two_nodes - it swaps two nodes in a listint_t doubly-linked list.
 * @k: A pointer to the head of the doubly-linked list.
 * @a1: first node to swap.
 * @b2: second node to swap.
 */
void two_nodes(listint_t **k, listint_t **a1, listint_t *a2)
{
	(*a1)->next = a2->next;
	if (a2->next != NULL)
		a2->next->prev = *a1;
	a2->prev = (*a1)->prev;
	a2->next = *a1;
	if ((*a1)->prev != NULL)
		(*a1)->prev->next = a2;
	else
		*k = a2;
	(*a1)->prev = a2;
	*a1 = a2->prev;
}

/**
 * insertion_sort_list - it sorts integers using the
 *                      insertion sort algorithm.
 * @list: points to the head of a doubly-linked list of integers.
 *
 * Description: It prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			two_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
