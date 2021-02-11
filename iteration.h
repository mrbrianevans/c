#ifndef __ITERATION_H
#define __ITERATION_H

#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <queue.h>
#include <getInstructions.h>

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

extern int customersFinishedBeingServedLeave(SERVICE_POINTS servicePoints, INPUT_OPTIONS inputOptions);
extern int customersInQueueGetServedAtAvailableServicePoints(SERVICE_POINTS servicePoints, QUEUE queue, INPUT_OPTIONS inputOptions);
extern int customersLeaveQueueAfterReachingWaitingTolerance(QUEUE queue, INPUT_OPTIONS inputOptions);
extern int customersArriveAtBackOfQueue(QUEUE queue, INPUT_OPTIONS inputOptions);
extern void printIterationStatistics(singleStatistics);
#endif
