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
QUEUE *push (int, QUEUE); /*adds an item to the end of the queue, and returns that item*/
QUEUE *shift (QUEUE); /*removes and returns the first element*/
void printQueueFromHead(QUEUE);
/* MAIN --------------------------------------------------*/
int main ()
{
	QUEUE *head = NULL;
	QUEUE *tail = NULL;
	return 0;
}

/* FUNCTION DEFINITIONS ---------------------------------*/
void printQueueFromHead(QUEUE head)
{
	printf("o");
	if(*head->next == NULL)
	{
		printf("/n");
		return;
	}
	printf("->");
	printQueueFromHead(*head->next);
	
}
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
