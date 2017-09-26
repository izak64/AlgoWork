#ifndef __PQ__
#define __PQ__

#include <stdlib.h>

typedef struct node
{
	void * data;
	int priority;
	size_t elemSize;
	struct node * next;
	struct node * prev;
}Node;

//extern Node queue[20];

typedef struct link_list
{
	Node * HEAD;
	Node * TAIL;
	size_t elemSize;
}linklist;

/*new linked list*/
linklist * new_link(size_t elemSize);

/*Create a Node*/
Node * new_node(void * data, int priority);

/*enqueue*/
void enq(void * data, int priority, linklist * linked);

/*dequeue_max*/
void deq_max(linklist * linked);

#endif