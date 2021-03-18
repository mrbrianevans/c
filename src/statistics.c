#include "statistics.h"


extern void printIterationStatistics(FILE *outputFile, SSTATS *stats)
{
   fprintf(outputFile, "\n");
   fprintf(outputFile, "Time interval: %d\n", stats->timeInterval);
   fprintf(outputFile, "Customers currently being served: %d\n",
           stats->customersBeingServed);
   fprintf(outputFile, "Customers currently in queue:     %d\n",
           stats->customersInQueue);
   fprintf(outputFile, "Number of fulfilled customers:    %d\n",
           stats->numFulfilled);
   fprintf(outputFile, "Number of unfulfilled customers:  %d\n",
           stats->numUnfulfilled);
   fprintf(outputFile, "Number of timed out customers:    %d\n",
           stats->numTimedOut);
   fprintf(outputFile, "\n");
}

extern void
printMultipleStatistics(FILE *outputFile, MULTIPLE_STATISTICS *stats)
{
   fprintf(outputFile, "\n");
   fprintf(outputFile, "\x1b[36mAverage across all %d simulations\x1b[0m\n",
           stats->numSuccessfulSims);
   fprintf(outputFile, "Average number of fulfilled customers:    %.2f\n",
           1.00 * stats->totalFulfilled / stats->numSuccessfulSims);
   fprintf(outputFile, "Average number of unfulfilled customers:  %.2f\n",
           1.00 * stats->totalUnfulfilled / stats->numSuccessfulSims);
   fprintf(outputFile, "Average number of timed out customers:    %.2f\n",
           1.00 * stats->totalTimedOut / stats->numSuccessfulSims);
   fprintf(outputFile, "Average wait time per customer:           %.2f\n",
           1.00 * stats->totalWaitTime / stats->numSuccessfulSims);
   fprintf(outputFile, "Average time from closing to completion:  %.2f\n",
           1.00 * stats->totalClosingToCompletion / stats->numSuccessfulSims);
   fprintf(outputFile, "\n");
}
