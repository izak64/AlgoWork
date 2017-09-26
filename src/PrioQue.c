#include "PrioQue.h"
#include <stdio.h>

//Node queue[20];

linklist * new_link(size_t elemSize)
{
	linklist * linked = (linklist *)malloc(sizeof(linklist));
	memset(linked, 0, sizeof(linklist));
	linked->HEAD = NULL;
	linked->TAIL = NULL;
	linked->elemSize = elemSize;
	return linked;
}

Node * new_node(void * data, int priority)
{
	Node * node = (Node *)malloc(sizeof(Node));
	memset(node, 0, sizeof(Node));
	node->data = data;
	node->priority = priority;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

void enq(void * data, int priority, linklist * linked)
{
	Node * curr = linked->HEAD;
	Node * node = new_node(data, priority);
	if (linked->HEAD == NULL)
	{
		linked->HEAD = node;
		linked->TAIL = node;
		return;
	}

	while (curr->priority > node->priority && curr->next != NULL)
	{
		curr = curr->next;
	}
	if (curr->next == NULL)
	{
		curr->next = node;
		node->prev = curr;
		linked->TAIL = node;
	}
	else if (curr == linked->HEAD)
	{
		curr->prev = node;
		linked->HEAD = node;
		linked->HEAD->next = curr;
	}
	else
	{
		node->prev = curr->prev;
		node->next = curr;
		curr->prev = node;
		node->prev->next = node;
	}
}

void deq_max(linklist * linked)
{
	Node * curr = linked->HEAD;

	if (!linked->HEAD)
	{
		printf("no nodes present \n");
		return;
	}
	else
	{
		linked->HEAD = curr->next;
		linked->HEAD->prev = NULL;
		linked->HEAD->next = curr->next->next;
		curr->prev = NULL;
		curr->next = NULL;
		free(curr);
	}
}

void print_prio(linklist * linked)
{
	Node * curr;
	if (linked->HEAD == NULL)return NULL;
	curr = linked->HEAD;
	while(curr->next != NULL)
	{
		printf("%i, ", curr->priority);
		curr = curr->next;
	}
	printf("%i \n", curr->priority);
}