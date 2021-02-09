#include <queue.h>

/* FUNCTION DEFINITIONS ---------------------------------*/
void printQueueFromHead(QUEUE *head)
{
	printf("%d", head->toleranceRemaining);
	if(head->next == NULL)
	{
		printf("\n");
		return;
	}
	printf("->");
	printQueueFromHead(head->next);

}
/* Returns a newly created QUEUE item
 *
 * Next and previous are set to NULL
 * :params:
 *  - int toleranceToWaiting the number of timesteps before the person leaves the queue
 *
 */
QUEUE *makeNewQueueItem (int toleranceToWaiting)
{
	QUEUE *newQueueItem = NULL;

	/* allocate memory */
	newQueueItem = (QUEUE *)malloc(sizeof(QUEUE));
	if(newQueueItem == NULL)
	{
		printf("Memory allocation failed on makeNewQueueItem");
		exit(-1);
	}

	newQueueItem->toleranceRemaining = 	toleranceToWaiting;
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
QUEUE *push(int toleranceToWaiting, QUEUE *tail)
{
	QUEUE *newItem = makeNewQueueItem(toleranceToWaiting);
	tail->next = newItem;
	newItem->previous = tail;
	return newItem;
}
/* Removes the first item in the queue, and returns the new head of the queue
 *
 * Frees the memory that the old head used
 */
QUEUE *shift(QUEUE *head)
{
	QUEUE *newHead = head->next;
	free(head);
	return newHead;
}

void emptyQueue(QUEUE *head)
{

  if(head->next == NULL && head->previous == NULL)
  {
    free(head);
    return;
  }

  if(head->next == NULL)
  {
    QUEUE *nextHead = head->next;
    free(head);
    emptyQueue(nextHead);
  }
  else
  {
    QUEUE *previousHead = head->previous;
    free(head);
    emptyQueue(previousHead);
  }
}
