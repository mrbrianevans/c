#include <queue.h>
static void printQueueItem(QUEUE_ITEM *);
static QUEUE_ITEM *makeNewQueueItem (int); /* returns an isolated queue item */
/* FUNCTION DEFINITIONS ---------------------------------*/
static void printQueueItem(QUEUE_ITEM *queueItem)
{
  printf("%d", queueItem->customer->toleranceRemaining);
	if(queueItem->next == NULL)
	{
		printf("\n");
		return;
	}
	printf("->");
	printQueue(queueItem->next);
}

extern void printQueue(QUEUE *queue)
{
  if( queue->length == 0)
  {
    printf("Empty queue\n")
    return;
  }
	printQueueItem(queue->head);
}
/* Returns a newly created QUEUE_ITEM
 *
 * Next and previous are set to NULL
 * :params:
 *  - int toleranceToWaiting the number of timesteps before the person leaves the queue
 *
 */
static QUEUE_ITEM *makeNewQueueItem (int toleranceToWaiting)
{
	QUEUE_ITEM *newQueueItem = NULL;

	/* allocate memory */
	newQueueItem = (QUEUE_ITEM *)malloc(sizeof(QUEUE_ITEM));
	if(newQueueItem == NULL)
	{
		printf("Memory allocation failed on makeNewQueueItem");
		exit(-1);
	}
  newQueueItem->customer = makeNewCustomer(toleranceToWaiting);
	newQueueItem->next = 			NULL;
	newQueueItem->previous = 		NULL;
	return newQueueItem;
}
/* Creates a new queue item, and appends it to the queue, making it the new tail
 *
 * :params:
 *  - int toleranceToWaiting the number of timesteps before the person leaves the queue
 *  - QUEUE *queue the queue to append an element to
 */
extern void push(int toleranceToWaiting, QUEUE *queue)
{
	QUEUE_ITEM *newItem = makeNewQueueItem(toleranceToWaiting);
  if( queue->length == 0)
  {
    queue->head = newItem;
    queue->tail = newItem;
    newItem->previous = newItem;
    newItem->next = newItem;
  }
  else
  {
    queue->tail->next =   newItem;
    newItem->previous =   tail;
  }
  queue->length++;
}
/* Removes the first item  in the queue (the head)
 *
 * Frees the memory that the old head used
 */
extern void shift(QUEUE *queue)
{
  if( queue->length == 0) return;
	QUEUE *newHead = queue->head->next;
	free(queue->head);
	queue->head = newHead;
  queue->length--;
}

/* Loops through queue, shifting each item, until its empty */
extern void emptyQueue(QUEUE *queue)
{
  while( queue->head->next != NULL )
  {
    shift(queue);
  }
}

/* makes a new empty QUEUE */
extern QUEUE *makeNewQueue()
{
  QUEUE *newQueue = NULL;

	/* allocate memory */
	newQueue = (QUEUE *)malloc(sizeof(QUEUE));
	if(newQueue == NULL)
	{
		printf("Memory allocation failed on makeNewQueue");
		exit(-1);
	}
  newQueue->head = NULL;
  newQueue->tail = NULL;
  newQueue->length = 0;
	return newQueue;
}
