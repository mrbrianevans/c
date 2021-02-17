#include <queue.h>

/** @returns an isolated queue item */
static QUEUE_ITEM *makeNewQueueItem(int);

static QUEUE_ITEM *makeNewQueueItem(int toleranceToWaiting)
{
   QUEUE_ITEM *newQueueItem = NULL;

   /* allocate memory */
   newQueueItem = (QUEUE_ITEM *) malloc(sizeof(QUEUE_ITEM));
   if( newQueueItem == NULL )
   {
      printf("Memory allocation failed on makeNewQueueItem");
      exit(-2);
   }
   newQueueItem->customer = makeNewCustomer(toleranceToWaiting);
   newQueueItem->next = NULL;
   newQueueItem->previous = NULL;
   return newQueueItem;
}


extern void push(int toleranceToWaiting, QUEUE *queue)
{
   /*printf("Queue before push of %d: ", toleranceToWaiting);
   printQueue(queue);*/
   QUEUE_ITEM *newItem = makeNewQueueItem(toleranceToWaiting);
   if( queue->length == 0 )
   {
      queue->head = newItem;
      queue->tail = newItem;
      /*newItem->previous = newItem;
      newItem->next = newItem;*/
   }
   else
   {
      newItem->previous = queue->tail;
      queue->tail->next = newItem;
      queue->tail = newItem;
   }
   queue->length++;
   /*printf("Queue after push of %d: ", toleranceToWaiting);
   printQueue(queue);*/
}


extern void shift(QUEUE *queue)
{
   /*printf("Queue before shift: ");
   printQueue(queue);*/
   if( queue->length == 0 ) return;
   if( queue->length == 1 )
   {
      free(queue->tail);
      queue->head = NULL;
      queue->length = 0;
      queue->tail = NULL;
      return;
   }
   if( queue->length == 2 )
   {
      free(queue->head);
      queue->head = queue->tail;
      queue->length = 1;
      return;
   }
   else
   {
      QUEUE_ITEM *newHead = queue->head->next;
      queue->head = NULL;
      free(queue->head);
      queue->head = newHead;
      queue->head->previous = NULL;
      queue->length--;
   }
}

extern void emptyQueue(QUEUE *queue)
{
   while( queue->length )
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
