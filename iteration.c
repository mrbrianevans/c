#include <iteration.h>

static float randomFloat();

static int randomInt(int, int);

/*return a random float, uniformly distributed*/
static float randomFloat()
{
/* setup random number generator */
   const gsl_rng_type *T;
   gsl_rng *r;
   gsl_rng_env_setup();
   T = gsl_rng_default;
   r = gsl_rng_alloc(T);
   gsl_rng_set(r, time(0));
   gsl_ran_flat_pdf();
}

/*return a random int, uniformly distributed between min and max*/
static int randomInt(int min, int max)
{
/* setup random number generator */
   const gsl_rng_type *T;
   gsl_rng *r;
   gsl_rng_env_setup();
   T = gsl_rng_default;
   r = gsl_rng_alloc(T);
   gsl_rng_set(r, time(0));
}

/*
 * - check the customers being served to see if they are finished so they can leave
 * - the next customer in the queue starts to get served
 * - check all customers in the queue to see if they reached their waiting limit
 * - customers join the back of the queue
 */

extern int customersFinishedBeingServedLeave(SERVICE_POINTS *servicePoints, INPUT_OPTIONS *inputOptions, SSTATS *stats)
{
   /* customers have a x% chance of finishing being served each timepoint. If rng > 0.4 then cust leaves */
   int numberOfCustomersBeingServed = servicePoints->totalServicePoints - servicePoints->availableServicePoints;
   printf("Customers occupying service points: %d\n", numberOfCustomersBeingServed);
   int i;
   for(i = 0; i < numberOfCustomersBeingServed; ++i)
   {
      float randomNumber = randomFloat();
      if( randomNumber > (1 / inputOptions->averageServeTime))
      {
         printf("Customer %d leaves service point", i);
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
   while( servicePoints->availableServicePoints && queue->length )
   {
      /* While there are available service points and customers waiting... */
      servicePoints->availableServicePoints--;
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
      if( currentQitem->customer.toleranceRemaining > currentQitem->customer.timeSpentWaiting++ )
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
         /*this is if a regular customer times out*/
         QUEUE_ITEM *swapNextItem = currentQitem->next;
         currentQitem->previous->next = swapNextItem;
         currentQitem->next->previous = currentQitem->previous;
         free(currentQitem);
         currentQitem = swapNextItem;
         free(swapNextItem);
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
   int minToleranceToWaiting = inputOptions->averageToleranceToWaiting / 2;
   int maxToleranceToWaiting = minToleranceToWaiting * 3;
   int numberOfNewCustomers;
   for(numberOfNewCustomers = randomInt(0, inputOptions->averageNewCustomersPerInterval * 2);
       numberOfNewCustomers > 0; numberOfNewCustomers--)
   {
      push(randomInt(minToleranceToWaiting, maxToleranceToWaiting), queue);
   }
   return 0;
}

extern void printIterationStatistics(char *outputFile, SSTATS *stats)
{
   printf("\n");
   printf("Statistics:\n");
   printf("timeInterval: %d\n", stats->timeInterval);
   printf("customersInQueue: %d\n", stats->customersInQueue);
   printf("customersBeingServed: %d\n", stats->customersBeingServed);
   printf("numFulfilled: %d\n", stats->numFulfilled);
   printf("numUnfulfilled: %d\n", stats->numUnfulfilled);
   printf("numTimedOut: %d\n", stats->numTimedOut);
   printf("totalWaitingTime: %d\n", stats->totalWaitTime);
   printf("closingTimeToCompletion: %d\n", stats->closingTimeToCompletion);
   printf("\n");
}
