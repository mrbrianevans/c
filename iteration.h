#ifndef __ITERATION_H
#define __ITERATION_H

#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <queue.h>
#include <parameters.h>
#include <servicePoints.h>
#include <math.h>
#include <statistics.h>

extern int
customersFinishedBeingServedLeave(SERVICE_POINTS *, INPUT_OPTIONS *, SSTATS *);

extern int
customersInQueueGetServedAtAvailableServicePoints(SERVICE_POINTS *, QUEUE *,
                                                  INPUT_OPTIONS *, SSTATS *);

extern int
customersLeaveQueueAfterReachingWaitingTolerance(QUEUE *, INPUT_OPTIONS *,
                                                 SSTATS *);

extern int customersArriveAtBackOfQueue(QUEUE *, INPUT_OPTIONS *, SSTATS *);


#endif
