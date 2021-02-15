/* Coursework - post office queueing system */
#include <queue.h>
#include <getInstructions.h>
#include <servicePoints.h>
#include <iteration.h>
#include <stdio.h>

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
   /* Get input options from file (command line argument) */
   INPUT_OPTIONS *inputOptions = NULL;
   inputOptions = (INPUT_OPTIONS *) malloc(sizeof(INPUT_OPTIONS));
   if( readInputOptionsFromFile(inputFile, inputOptions) == 0 )
   {
      printf("Options:\n");
      printf("Max queue length: %d\n", inputOptions->maxQueueLength);
      printf("Number of service points: %d\n", inputOptions->numServicePoints);
      printf("Closing time: %d\n", inputOptions->closingTime);
      printf("Average new customers per interval: %d\n\n", inputOptions->averageNewCustomersPerInterval);
   }
   else
      return -1;

   QUEUE *queue = makeNewQueue();
   SERVICE_POINTS *servicePoints = makeServicePoints(inputOptions->numServicePoints);
   printf("Service points in postoffice: %d\n", servicePoints->totalServicePoints);
   printf("Available service points: %d\n", servicePoints->totalServicePoints);

   SSTATS *statistics = NULL;
   statistics = (SSTATS *) malloc(sizeof(SSTATS));
   int timepoint;
   for(timepoint = 0; timepoint < inputOptions->closingTime; timepoint++)
   {
      customersFinishedBeingServedLeave(servicePoints, inputOptions, statistics);
      customersInQueueGetServedAtAvailableServicePoints(servicePoints, queue, inputOptions, statistics);
      customersLeaveQueueAfterReachingWaitingTolerance(queue, inputOptions, statistics);
      customersArriveAtBackOfQueue(queue, inputOptions, statistics);
      if( numSims == 1 )
      {
         printIterationStatistics(outputFile, statistics);
         printf("QUEUE: ");
         printQueue(queue);
      }
   }

   return 0;
}

