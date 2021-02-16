/* Coursework - post office queueing system */
#include <queue.h>
#include <getInstructions.h>
#include <servicePoints.h>
#include <iteration.h>
#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

/* MAIN --------------------------------------------------*/
int main(int argc, char *argv[])
{

   if( argc < 4 )
   {
      fprintf(stderr, "Not enough command line arguments. Try fileIn numSims fileOut\n");
      return -1;
   }
   printf("Number of args: %d\n", argc);

   char *inputFile = argv[1];
   int numSims = ((int) *argv[2]) - ((int) '0'); /*not sure if this type conversion will work*/
   printf("Number of sims to run: %d\n", numSims);
   char *outputFile = argv[3];
   /*Get input options from file (command line argument)*/
   INPUT_OPTIONS *inputOptions = NULL;
   inputOptions = (INPUT_OPTIONS *) malloc(sizeof(INPUT_OPTIONS));
   if( readInputOptionsFromFile(inputFile, inputOptions) == 0 )
   {
      printf("Options:\n");
      printf("Max queue length: %d\n", inputOptions->maxQueueLength);
      printf("Number of service points: %d\n", inputOptions->numServicePoints);
      printf("Closing time: %d\n", inputOptions->closingTime);
      printf("Average new customers per interval: %d\n", inputOptions->averageNewCustomersPerInterval);
      printf("Average tolerance to waiting: %d\n", inputOptions->averageToleranceToWaiting);
      printf("Average serve time: %d\n", inputOptions->averageServeTime);
      printf("\n");
   }
   else
      return -1;


   QUEUE *queue = makeNewQueue();
   SERVICE_POINTS *servicePoints = makeServicePoints(inputOptions->numServicePoints);

   SSTATS *statistics = NULL;
   statistics = (SSTATS *) malloc(sizeof(SSTATS));
   for(statistics->timeInterval = 0; statistics->timeInterval < inputOptions->closingTime; statistics->timeInterval++)
   {
      customersFinishedBeingServedLeave(servicePoints, inputOptions, statistics);
      customersInQueueGetServedAtAvailableServicePoints(servicePoints, queue, inputOptions, statistics);
      customersLeaveQueueAfterReachingWaitingTolerance(queue, inputOptions, statistics);
      customersArriveAtBackOfQueue(queue, inputOptions, statistics);
      if( numSims == 1 )
      {
         printIterationStatistics(outputFile, statistics);
         printf("QUEUE: ");
         printf(" %d long\n", queue->length);
         /*printQueue(queue);*/
      }
   }/*todo: need a while loop here until all customers in queue have been served*/

   printIterationStatistics(outputFile, statistics);
   /* todo: report on accuracy of outcomes, compared with inputs */
   printf("Average serve time: Target: %d, actual: %f\n", inputOptions->averageServeTime,
          1.0 * statistics->totalServeTime / statistics->numFulfilled);
   /*todo: average wait time is coming out way too high! */
   printf("Average wait time: actual: %f\n", 1.0 * statistics->totalWaitTime / (statistics->numFulfilled +
                                                                                statistics->numTimedOut)); /*includes timed out customers*/
   printf("Average new customers per interval: Target: %d, actual: %f\n", inputOptions->averageNewCustomersPerInterval,
          1.0 * (statistics->numFulfilled + statistics->numUnfulfilled + statistics->numTimedOut) /
          statistics->timeInterval);

/*
   QUEUE *queue = makeNewQueue();
   push(5, queue);
   push(3, queue);
   push(8, queue);
   push(6, queue);
   printf("Length: %d\n", queue->length);
   printQueue(queue);*/
   return 0;
}

