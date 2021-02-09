#ifndef __GET_INSTRUCTIONS_H
#define __GET_INSTRUCTIONS_H 1
#include <stdio.h>

struct inputOptionsStruct
{
	int maxQueueLength;
	int numServicePoints;
	int closingTime;
	int averageNewCustomersPerInterval;
};

typedef struct inputOptionsStruct INPUT_OPTIONS;

/*--- Function prototypes --------------------*/
extern INPUT_OPTIONS readInputOptionsFromFile(char *);

#endif
