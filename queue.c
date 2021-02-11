#include <queue.h>

/* FUNCTION DEFINITIONS ---------------------------------*/
extern void printQueueFromHead(QUEUE *queue)
{
	printf("%d", head->toleranceRemaining);
	if(queue->head->next == NULL)
	{
		printf("\n");
		return;
	}
	printf("->");
	printQueueFromHead(queue->head->next);
}
/* Returns a newly created QUEUE item
 *
 * Next and previous are set to NULL
 * :params:
 *  - int toleranceToWaiting the number of timesteps before the person leaves the queue
 *
 */
static QUEUE *makeNewQueueItem (int toleranceToWaiting)
{
	QUEUE *newQueueItem = NULL;

	/* allocate memory */
	newQueueItem = (QUEUE *)malloc(sizeof(QUEUE));
	if(newQueueItem == NULL)
	{
		printf("Memory allocation failed on makeNewQueueItem");
		exit(-1);
	}
	/* todo: implement the make new customer function */
  newQueueItem->customer = makeNewCustomer(toleranceToWaiting);
	newQueueItem->next = 			NULL;
	newQueueItem->previous = 		NULL;
	return newQueueItem;
}
/* Creates a new queue item, and appends it to the queue, making it the new tail
 *
 * :params:
 *  - int toleranceToWaiting the number of timesteps before the person leaves the queue
 *  - QUEUE *tail the current tail of the queue (last element)
 *
 * :returns: the new tail of the queue
 */
extern QUEUE *push(int toleranceToWaiting, QUEUE *queue)
{
	QUEUE_ITEM *newItem = makeNewQueueItem(toleranceToWaiting);
	queue->tail->next = newItem;
	newItem->previous = tail;
	return newItem;
}
/* Removes the first item in the queue, and returns the new head of the queue
 *
 * Frees the memory that the old head used
 */
extern QUEUE *shift(QUEUE *queue)
{
	QUEUE *newHead = queue->head->next;
	free(head);
	return newHead;
}

extern void emptyQueue(QUEUE *queue)
{

  if(queue->head->next == NULL && queue->tail->previous == NULL)
  {
    free(head);
    return;
  }
  /* todo: fix empty queue function to work with queue objects*/
  QUEUE *nextHead = head->next;
  free(head);
  emptyQueue(nextHead);

}
