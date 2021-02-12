#ifndef __SERVICE_POINTS_H
#define __SERVICE_POINTS_H
#include <customer.h>
struct servicePoint
{
   CUSTOMER customer; /* the customer currently being served */

};
typedef struct servicePoint SERVICE_POINT;

struct servicePoints
{
   /*need an array of service points*/
   int numServicePoints;
   SERVICE_POINT points[];
};
typedef struct servicePoints SERVICE_POINTS;

extern SERVICE_POINTS *makeServicePoints(int numServicePoints);

extern int getNumAvailableServicePoints();

extern int serveCustomer(CUSTOMER customer);

#endif