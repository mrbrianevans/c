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
	QUEUE_ITEM head;
	QUEUE_ITEM tail;
	int length;
};
typedef struct queueStruct QUEUE;
/* FUNCTION PROTOTYPES -----------------------------------*/
extern QUEUE *makeNewQueue(); /* makes a head and tail of a queue*/
static QUEUE_ITEM *makeNewQueueItem (int); /* returns an isolated queue item */
extern QUEUE_ITEM *push (int, QUEUE *); /*adds an item to the end of the queue, and returns that item*/
extern QUEUE_ITEM *shift (QUEUE *); /*removes the first element and returns the new head of the queue*/
extern void emptyQueue(QUEUE *); /*safely empties a queue and frees the memory*/
extern void printQueue(QUEUE *);
#endif
