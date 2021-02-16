#ifndef __ITERATION_H
#define __ITERATION_H

#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <queue.h>
#include <getInstructions.h>
#include <servicePoints.h>
#include <math.h>

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

extern int customersFinishedBeingServedLeave(SERVICE_POINTS *, INPUT_OPTIONS *, SSTATS *);

extern int customersInQueueGetServedAtAvailableServicePoints(SERVICE_POINTS *, QUEUE *, INPUT_OPTIONS *, SSTATS *);

extern int customersLeaveQueueAfterReachingWaitingTolerance(QUEUE *, INPUT_OPTIONS *, SSTATS *);

extern int customersArriveAtBackOfQueue(QUEUE *, INPUT_OPTIONS *, SSTATS *);

extern void printIterationStatistics(char *, SSTATS *);

#endif
