#include <stdio.h>
#include "sort.h"


/**
 * swapNode - swap a double linked listed nodes
 * @head: head of the list
 * @v1: first node
 * @v2: second node
 *
 * Return: nothing
 * On error: nothing
 */
void swapNode(listint_t **head, listint_t *v1, listint_t *v2)
{
	if (v1->prev)
		v1->prev->next = v2;
	if (v2->next)
		v2->next->prev = v1;

	v1->next = v2->next;
	v2->prev = v1->prev;

	v1->prev = v2;
	v2->next = v1;

	if (!(v2->prev))
		*head = v2;
}


/**
 * checkEveryNode - recursive function to organize a single
 * node
 * @head: head of the list
 * @node: node to organize in a listint_t list
 *
 * Return: nothing
 * On error: nothing
 */
void checkEveryNode(listint_t **head, listint_t *node)
{
	listint_t *curr = node;

	while (curr->prev)
		if (curr->n < curr->prev->n)
		{
			swapNode(head, curr->prev, curr);
			print_list(*head);
		}
		else
			break;

	if (node->next)
		checkEveryNode(head, node->next);
}


/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @list: head of list
 *
 * Return: nothing
 * On error: nothing
 */
void insertion_sort_list(listint_t **list)
{
	if (list && *list && (*list)->next)
		checkEveryNode(list, (*list)->next);
}
