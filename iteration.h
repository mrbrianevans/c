#ifndef __ITERATION_H
#define __ITERATION_H

#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <queue.h>
#include <getInstructions.h>
#include <servicePoints.h>

struct singleStatistics
{
	int timeInterval;
	int customersInQueue;
	int customersBeingServed;
	int numFulfilled;
	int numUnfulfilled;
	int numTimedOut;
	int totalCustomersServed;
	int averageWaitTime;
	int closingTimeToCompletion;
};

typedef struct singleStatistics SSTATS;

extern int customersFinishedBeingServedLeave(SERVICE_POINTS *, INPUT_OPTIONS *, SSTATS *);
extern int customersInQueueGetServedAtAvailableServicePoints(SERVICE_POINTS *, QUEUE *, INPUT_OPTIONS *, SSTATS *);
extern int customersLeaveQueueAfterReachingWaitingTolerance(QUEUE *, INPUT_OPTIONS *, SSTATS *);
extern int customersArriveAtBackOfQueue(QUEUE *, INPUT_OPTIONS *, SSTATS *);
extern void printIterationStatistics(SSTATS *);
#endif
