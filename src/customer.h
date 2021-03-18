#ifndef __CUSTOMER_H
#define __CUSTOMER_H
#include <stdlib.h>
#include <stdio.h>
struct customerObject
{
   int toleranceRemaining;
   int timeSpentWaiting;
};

typedef struct customerObject CUSTOMER;

/** Returns a newly created CUSTOMER
 *
 * timeSpentWaiting is set to zero
 * @param int toleranceToWaiting the number of time steps before the person leaves the queue
 * @returns CUSTOMER new customer object
 */
extern CUSTOMER *makeNewCustomer(int);

#endif