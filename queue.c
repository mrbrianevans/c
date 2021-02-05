#include <stdio.h>
#include <stdlib.h>

struct queueStruct
{
	int			toleranceRemaining;
	struct queueStruct	*next;
	struct queueStruct	*previous;
};

typedef struct queueStruct QUEUE;

/* FUNCTION PROTOTYPES -----------------------------------*/
QUEUE *makeNewQueueItem (int); /* returns an isolated queue item */
QUEUE *push (int, QUEUE *); /*adds an item to the end of the queue, and returns that item*/
QUEUE *shift (QUEUE *); /*removes the first element and returns the new head of the queue*/
void printQueueFromHead(QUEUE *);

/* MAIN --------------------------------------------------*/
int main ()
{
	/* --- Example queue --- */
	QUEUE *head = makeNewQueueItem(3);
	QUEUE *tail = makeNewQueueItem(0);
	head->next = tail;
	tail->previous = head;
	tail = push(1, tail);
	tail = push(4, tail);
	tail = push(1, tail);
	tail = push(5, tail);
	tail = push(9, tail);
	head = shift(head);
	tail = push(2, tail);
	tail = push(6, tail);
	head = shift(head);
	tail = push(5, tail);
	tail = push(3, tail);
	printQueueFromHead(head);
	return 0;
}

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
