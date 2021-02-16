#ifndef __QUEUE_H
#define __QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <customer.h>

/* Queue implemented by a doubly linked list */
struct queueItemStruct
{
   CUSTOMER *customer;
   struct queueItemStruct *next;
   struct queueItemStruct *previous;
};
typedef struct queueItemStruct QUEUE_ITEM;

struct queueStruct
{
   struct queueItemStruct *head;
   struct queueItemStruct *tail;
   int length;
};
typedef struct queueStruct QUEUE;

/* FUNCTION PROTOTYPES -----------------------------------*/
/** Returns a newly created QUEUE_ITEM
 *
 * Next and previous are set to NULL
 * @param int toleranceToWaiting the number of time steps before the person leaves the queue
 * @returns newly created QUEUE_ITEM
 */
extern QUEUE *makeNewQueue(); /* makes an empty queue */
/** Creates a new queue item, and appends it to the queue, making it the new tail
 *
 *  @param int      toleranceToWaiting the number of time steps before the person leaves the queue
 *  @param QUEUE    *queue the queue to append an element to
 */
extern void push(int, QUEUE *); /*adds an item to the end of the queue*/
/** Removes the first item  in the queue (the head)
 *
 * Frees the memory that the old head used
 */
extern void shift(QUEUE *);

/**safely empties a queue and frees the memory*/
extern void emptyQueue(QUEUE *);

/** prints a queue */
extern void printQueue(QUEUE *);

#endif
