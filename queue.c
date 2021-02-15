#include <queue.h>

static void printQueueItem(QUEUE_ITEM *);

/** @returns an isolated queue item */
static QUEUE_ITEM *makeNewQueueItem(int);

/* FUNCTION DEFINITIONS ---------------------------------*/
static void printQueueItem(QUEUE_ITEM *queueItem)
{
   printf("%d", queueItem->customer.timeSpentWaiting);
   if( queueItem->next == NULL )
   {
      printf("\n");
      return;
   }
   printf("->");
   printQueueItem(queueItem->next);
}

extern void printQueue(QUEUE *queue)
{
   if( queue->length == 0 )
   {
      printf("Empty queue\n");
      return;
   }
   printQueueItem(queue->head);
}


static QUEUE_ITEM *makeNewQueueItem(int toleranceToWaiting)
{
   QUEUE_ITEM *newQueueItem = NULL;

   /* allocate memory */
   newQueueItem = (QUEUE_ITEM *) malloc(sizeof(QUEUE_ITEM));
   if( newQueueItem == NULL )
   {
      printf("Memory allocation failed on makeNewQueueItem");
      exit(-1);
   }
   newQueueItem->customer = makeNewCustomer(toleranceToWaiting);
   newQueueItem->next = NULL;
   newQueueItem->previous = NULL;
   return newQueueItem;
}


extern void push(int toleranceToWaiting, QUEUE *queue)
{
   QUEUE_ITEM *newItem = makeNewQueueItem(toleranceToWaiting);
   if( queue->length == 0 )
   {
      queue->head = newItem;
      queue->tail = newItem;
      newItem->previous = newItem;
      newItem->next = newItem;
   }
   else
   {
      queue->tail->next = newItem;
      newItem->previous = queue->tail;
   }
   queue->length++;
}


extern void shift(QUEUE *queue)
{
   if( queue->length == 0 ) return;
   QUEUE_ITEM *newHead = queue->head->next;
   free(queue->head);
   queue->head = newHead;
   queue->length--;
}

extern void emptyQueue(QUEUE *queue)
{
   while( queue->head->next != NULL )
   {
      shift(queue);
   }
}

extern QUEUE *makeNewQueue()
{
   QUEUE *newQueue = NULL;

   /* allocate memory */
   newQueue = (QUEUE *) malloc(sizeof(QUEUE));
   if( newQueue == NULL )
   {
      printf("Memory allocation failed on makeNewQueue");
      exit(-1);
   }
   newQueue->head = NULL;
   newQueue->tail = NULL;
   newQueue->length = 0;
   return newQueue;
}
