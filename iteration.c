#include <iteration.h>

static int randomNumber();


/*return a random float, uniformly distributed*/
static int randomFloat()
{
/* setup random number generator */
	const gsl_rng_type	*T;
	gsl_rng			*r;
	gsl_rng_env_setup();
	T = gsl_rng_default;
	r = gsl_rng_alloc(T);
	gsl_rng_set(r, time(0));

}
/*return a random int, uniformly distributed between min and max*/
static int randomFloat(int min, int max)
{
/* setup random number generator */
	const gsl_rng_type	*T;
	gsl_rng			*r;
	gsl_rng_env_setup();
	T = gsl_rng_default;
	r = gsl_rng_alloc(T);
	gsl_rng_set(r, time(0));

}
/*
 * - check the customers being served to see if they are finished so they can leave
 * - the next customer in the queue starts to get served
 * - check all customers in the queue to see if they reached their waiting limit
 * - customers join the back of the queue
 */

extern int customersFinishedBeingServedLeave(SERVICE_POINTS servicePoints, INPUT_OPTIONS inputOptions)
{
  /* customers have a x% chance of finishing being served each timepoint. If rng > 0.4 then cust leaves */
  return 0;
}

extern int customersInQueueGetServedAtAvailableServicePoints(SERVICE_POINTS servicePoints, QUEUE queue, INPUT_OPTIONS inputOptions)
{
  /* no random numbers, just move customers to service points */
  return 0;
}

extern int customersLeaveQueueAfterReachingWaitingTolerance(QUEUE queue, INPUT_OPTIONS inputOptions)
{
  /* no random generator here, just check if timeSpentWaiting++==toleranceToWaiting */
  return 0;
}

extern int customersArriveAtBackOfQueue(QUEUE queue, INPUT_OPTIONS inputOptions)
{
  /* randomly distributed around averageNumNewCustomers (eg 3) */
  return 0;
}

