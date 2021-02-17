/* single post office simulation */
#include <postoffice.h>

extern int singleSimulation(INPUT_OPTIONS *inputOptions, FILE *outputFile,
                            MULTIPLE_STATISTICS *multipleStatistics)
{
   int numSims = inputOptions->numSims;
   QUEUE *queue = makeNewQueue();
   SERVICE_POINTS *servicePoints = makeServicePoints(
         inputOptions->numServicePoints);

   SSTATS *statistics = NULL;
   statistics = (SSTATS *) malloc(sizeof(SSTATS));
   if( statistics == NULL )
   {
      fprintf(stderr,
              "\x1b[31mError:\x1b[0m Memory allocation failed for statistics");
      return -2; /* minus two for failed memory allocation */
   }
   for(statistics->timeInterval = 0; statistics->timeInterval <
                                     inputOptions->closingTime; statistics->timeInterval++)
   {
      customersFinishedBeingServedLeave(servicePoints, inputOptions,
                                        statistics);
      customersInQueueGetServedAtAvailableServicePoints(servicePoints, queue,
                                                        inputOptions,
                                                        statistics);
      customersLeaveQueueAfterReachingWaitingTolerance(queue, inputOptions,
                                                       statistics);
      customersArriveAtBackOfQueue(queue, inputOptions, statistics);
      if( numSims == 1 )
      {
         printIterationStatistics(outputFile, statistics);
      }
   }
   if( numSims == 1 )
   {
      fprintf(outputFile,
              "\x1b[31m------------ CLOSING TIME ------------\x1b[0m\n");
   }
   while( queue->length > 0 || servicePoints->availableServicePoints <
                               servicePoints->totalServicePoints )
   {
      customersFinishedBeingServedLeave(servicePoints, inputOptions,
                                        statistics);
      customersInQueueGetServedAtAvailableServicePoints(servicePoints, queue,
                                                        inputOptions,
                                                        statistics);
      customersLeaveQueueAfterReachingWaitingTolerance(queue, inputOptions,
                                                       statistics);
      if( numSims == 1 )
      {
         printIterationStatistics(outputFile, statistics);
      }
      statistics->timeInterval++;
      statistics->closingTimeToCompletion++;
   }
   if( numSims == 1 )
   {
      fprintf(outputFile,
              "Time from closing until all customers were served: %d intervals\n",
              statistics->closingTimeToCompletion);
      fprintf(outputFile,
              "Average wait time for fulfilled customers: %.2f intervals\n",
              1.0 * statistics->totalWaitTime / statistics->numFulfilled);
   }
   else
   {
      /*add statistics to multiple statistics*/
      multipleStatistics->numSuccessfulSims++;
      multipleStatistics->totalWaitTime += (1.0 * statistics->totalWaitTime /
                                            statistics->numFulfilled);
      multipleStatistics->totalClosingToCompletion += statistics->closingTimeToCompletion;
      multipleStatistics->totalFulfilled += statistics->numFulfilled;
      multipleStatistics->totalUnfulfilled += statistics->numUnfulfilled;
      multipleStatistics->totalTimedOut += statistics->numTimedOut;
   }
   statistics = NULL;
   free(servicePoints);
   emptyQueue(queue);
   free(queue);
   return 0;
}

