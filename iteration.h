#ifndef __ITERATION_H
#define __ITERATION_H

#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

extern int customersFinishedBeingServedLeave(QUEUE queue, INPUT_OPTIONS inputOptions);
extern int customersInQueueGetServedAtAvailableServicePoints(QUEUE queue, INPUT_OPTIONS inputOptions);
extern int customersLeaveQueueAfterReachingWaitingTolerance(QUEUE queue, INPUT_OPTIONS inputOptions);
extern int customersArriveAtBackOfQueue(QUEUE queue, INPUT_OPTIONS inputOptions);

#endif
