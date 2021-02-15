#ifndef __SERVICE_POINTS_H
#define __SERVICE_POINTS_H
#include <customer.h>
#include <stdio.h>
#include <stdlib.h>

/*
struct servicePoint
{
   CUSTOMER customer; */
/* the customer currently being served *//*


};

struct servicePoints
{
   */
/*need an array of service points*//*

   int numServicePoints;
   struct servicePoint *points[];
};

typedef struct servicePoint SERVICE_POINT;
typedef struct servicePoints SERVICE_POINTS;

extern SERVICE_POINTS *makeServicePoints(int);

extern int getNumAvailableServicePoints();

extern int serveCustomer(CUSTOMER);
*/

struct servicePoints
{
   int totalServicePoints;
   int availableServicePoints;
};
typedef struct servicePoints SERVICE_POINTS;

extern SERVICE_POINTS *makeServicePoints(int);

/*extern int serveCustomer(CUSTOMER);*/
#endif