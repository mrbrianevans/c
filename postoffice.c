/* Coursework - post office queueing system */
#include <queue.h>
#include <getInstructions.h>
#include <servicePoints.h>
#include <iteration.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

/* MAIN --------------------------------------------------*/
int main(int argc, char *argv[])
{
   if( argc < 4 )
   {
      fprintf(stderr,
              "Not enough command line arguments. Try fileIn numSims fileOut\n");
      return -1;
   }

   char *inputFile = argv[1];
   int numSims = 0;
   sscanf(argv[2], "%d", &numSims);
   char *outputFileName = argv[3];
   FILE *outputFile = NULL;
   if((outputFile = fopen(outputFileName, "w")) == NULL )
   {
      fprintf(stderr,
              "Cannot create/write to output file %s: \n\x1b[31mError:\x1b[0m %s",
              outputFileName, strerror(errno));
   }
   /*Get input options from file (command line argument)*/
   INPUT_OPTIONS *inputOptions = NULL;
   inputOptions = (INPUT_OPTIONS *) malloc(sizeof(INPUT_OPTIONS));
   if( readInputOptionsFromFile(inputFile, inputOptions, outputFile) != 0 )
      return -1;


   QUEUE *queue = makeNewQueue();
   SERVICE_POINTS *servicePoints = makeServicePoints(
         inputOptions->numServicePoints);

   SSTATS *statistics = NULL;
   statistics = (SSTATS *) malloc(sizeof(SSTATS));
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
   fprintf(outputFile, "------------ CLOSING TIME ------------\n");
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

   fprintf(outputFile,
           "Time from closing until all customers were served: %d intervals\n",
           statistics->closingTimeToCompletion);
   fprintf(outputFile,
           "Average wait time for fulfilled customers: %.2f intervals\n",
           1.0 * statistics->totalWaitTime / statistics->numFulfilled);

   fclose(outputFile);
   printf("Successfully written output of simulation to %s\n", outputFileName);
   return 0;
}

