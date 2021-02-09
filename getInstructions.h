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
INPUT_OPTIONS readInputOptionsFromFile(char[]);
