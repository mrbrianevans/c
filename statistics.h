#ifndef C_STATISTICS_H
#define C_STATISTICS_H
#include <stdio.h>
struct multipleStatistics
{
   int totalFulfilled;
   int totalUnfulfilled;
   int totalTimedOut;
   int totalWaitTime;
   int totalClosingToCompletion;
   int numSuccessfulSims;
};

typedef struct multipleStatistics MULTIPLE_STATISTICS;

struct singleStatistics
{
   int timeInterval;
   int customersInQueue;
   int customersBeingServed;
   int numFulfilled; /* finished being served at postoffice */
   int numUnfulfilled; /* arrived and queue was full */
   int numTimedOut; /* arrived and left queue after waiting too long */
   int totalWaitTime; /* used to calculate average wait time */
   int closingTimeToCompletion;
   int totalServeTime;
};

typedef struct singleStatistics SSTATS;

extern void printIterationStatistics(FILE *, SSTATS *);

extern void printMultipleStatistics(FILE *, MULTIPLE_STATISTICS *);

#endif /*C_STATISTICS_H*/
