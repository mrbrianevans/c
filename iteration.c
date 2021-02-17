#include <iteration.h>

static float randomFloat(gsl_rng *);

static int randomInt(gsl_rng *, int, int);

/*return a random float, uniformly distributed*/
static float randomFloat(gsl_rng *r)
{

   float randFloat = gsl_ran_flat(r, 0, 1);
   return randFloat;
}

/*return a random int, uniformly distributed between min and max*/
static int randomInt(gsl_rng *r, int min, int max)
{
   float randFloat = randomFloat(r);
   float floatInRange = randFloat * (max - min) + min;
   int intInRange = (int) floatInRange;
   return intInRange;
}

/*
 * - check the customers being served to see if they are finished so they can leave
 * - the next customer in the queue starts to get served
 * - check all customers in the queue to see if they reached their waiting limit
 * - customers join the back of the queue
 */

extern int customersFinishedBeingServedLeave(SERVICE_POINTS *servicePoints, INPUT_OPTIONS *inputOptions, SSTATS *stats)
{
   /* customers have a x% chance of finishing being served each time point. If random > x then customer leaves */
   int numberOfCustomersBeingServed = servicePoints->totalServicePoints - servicePoints->availableServicePoints;
   int i;
   for(i = 0; i < numberOfCustomersBeingServed; ++i)
   {
      stats->totalServeTime++;
      float randomNumber = randomFloat(inputOptions->r);
      if( randomNumber < (1.00 / inputOptions->averageServeTime))
      {
         stats->customersBeingServed--;
         stats->numFulfilled++;
         servicePoints->availableServicePoints++;
      }
   }
   return 0;
}

extern int customersInQueueGetServedAtAvailableServicePoints(SERVICE_POINTS *servicePoints, QUEUE *queue,
                                                             INPUT_OPTIONS *inputOptions, SSTATS *stats)
{
   /* no random numbers, just move customers to service points */
   while( servicePoints->availableServicePoints > 0 && stats->customersInQueue > 0 )
   {
      /* While there are available service points and customers waiting... */
      servicePoints->availableServicePoints =
            servicePoints->availableServicePoints - 1;
      /* only aggregates the time spent waiting in queue of fulfilled customers */
      stats->totalWaitTime += queue->head->customer->timeSpentWaiting;
      shift(queue);
      stats->customersBeingServed++;
      stats->customersInQueue--;
   }
   return 0;
}

extern int customersLeaveQueueAfterReachingWaitingTolerance(QUEUE *queue, INPUT_OPTIONS *inputOptions, SSTATS *stats)
{
   /* no random generator here, just check if timeSpentWaiting++==toleranceToWaiting */
   QUEUE_ITEM *currentQitem = queue->head;
   int i;
   for(i = 0; i < queue->length; ++i)
   {
      if( currentQitem->customer->toleranceRemaining <
          ++currentQitem->customer->timeSpentWaiting )
      {
         stats->numTimedOut++;
         stats->customersInQueue--;
         if( currentQitem->previous == NULL )
         { /*this is if the head times out*/
            shift(queue);
            currentQitem = queue->head;
         }
         else if( currentQitem->next == NULL )
         { /*this is if the tail times out*/
            queue->tail = currentQitem->previous;
            queue->length--;
            currentQitem->previous->next = NULL;
            free(currentQitem);
            break;
         }
         else
         {
            /*this is if a regular customer times out*/
            currentQitem->previous->next = currentQitem->next;
            currentQitem->next->previous = currentQitem->previous;
            queue->length--;
            currentQitem = currentQitem->next;
         }
      }
      else
      {
         if( currentQitem->next == NULL ) break;
         /*go to the next customer*/
         currentQitem = currentQitem->next;
      }
   }
   return 0;
}

extern int customersArriveAtBackOfQueue(QUEUE *queue, INPUT_OPTIONS *inputOptions, SSTATS *stats)
{
   /* randomly distributed around averageNumNewCustomers (eg 3) */
   int minToleranceToWaiting = (int) (inputOptions->averageToleranceToWaiting / 2);
   int maxToleranceToWaiting = minToleranceToWaiting * 3;
   if( minToleranceToWaiting < 1 ) minToleranceToWaiting = 0;
   if( maxToleranceToWaiting < 2 ) minToleranceToWaiting = 2;
   int numberOfNewCustomers = randomInt(inputOptions->r, 0, inputOptions->averageNewCustomersPerInterval * 2);
   int numberOfRejectedCustomers = 0;
   for(;
         numberOfNewCustomers > 0; numberOfNewCustomers--)
   {
      if( queue->length == inputOptions->maxQueueLength )
      {
         stats->numUnfulfilled++;
         numberOfRejectedCustomers++;
      }
      else
      {
         push(randomInt(inputOptions->r, minToleranceToWaiting, maxToleranceToWaiting), queue);
         stats->customersInQueue++;
      }
   }
   return 0;
}
