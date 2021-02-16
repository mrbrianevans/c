#ifndef __GET_INSTRUCTIONS_H
#define __GET_INSTRUCTIONS_H 1

#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <errno.h>
#include <string.h>

struct inputOptionsStruct
{
   int maxQueueLength;
   int numServicePoints;
   int closingTime;
   int averageNewCustomersPerInterval;
   int averageServeTime;
   int averageToleranceToWaiting;
   gsl_rng *r;
};

typedef struct inputOptionsStruct INPUT_OPTIONS;

/*--- Function prototypes --------------------*/
extern int readInputOptionsFromFile(char *, INPUT_OPTIONS *);

#endif
