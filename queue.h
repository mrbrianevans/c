#ifndef __QUEUE_H
#define __QUEUE_H
#include <stdio.h>
#include <stdlib.h>

struct queueStruct
{
	int			toleranceRemaining;
	int     timeSpentWaiting;
	struct queueStruct	*next;
	struct queueStruct	*previous;
};
/* Queue implemented by a doubly linked list */
typedef struct queueStruct QUEUE;

/* FUNCTION PROTOTYPES -----------------------------------*/
extern QUEUE *makeNewQueueItem (int); /* returns an isolated queue item */
extern QUEUE *push (int, QUEUE *); /*adds an item to the end of the queue, and returns that item*/
extern QUEUE *shift (QUEUE *); /*removes the first element and returns the new head of the queue*/
extern void emptyQueueFromHead(QUEUE *); /*safely empties a queue and frees the memory*/
extern void printQueueFromHead(QUEUE *);
#endif
