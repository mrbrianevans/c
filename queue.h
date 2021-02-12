#ifndef __QUEUE_H
#define __QUEUE_H
#include <stdio.h>
#include <stdlib.h>

/* Queue implemented by a doubly linked list */
struct queueItemStruct
{
	CUSTOMER customer;
	struct queueItemStruct	*next;
	struct queueItemStruct	*previous;
};
typedef struct queueItemStruct QUEUE;

struct queueStruct
{
	QUEUE_ITEM *head;
	QUEUE_ITEM *tail;
	int length;
};
typedef struct queueStruct QUEUE;
/* FUNCTION PROTOTYPES -----------------------------------*/
extern QUEUE *makeNewQueue(); /* makes an empty queue */
extern QUEUE_ITEM *push (int, QUEUE *); /*adds an item to the end of the queue*/
extern QUEUE_ITEM *shift (QUEUE *); /*removes the first element*/
extern void emptyQueue(QUEUE *); /*safely empties a queue and frees the memory*/
extern void printQueue(QUEUE *); /* prints a queue */
#endif
