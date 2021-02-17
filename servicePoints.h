#ifndef __SERVICE_POINTS_H
#define __SERVICE_POINTS_H
#include <customer.h>
#include <stdio.h>
#include <stdlib.h>

struct servicePoints
{
   int totalServicePoints;
   int availableServicePoints;
};
typedef struct servicePoints SERVICE_POINTS;

extern SERVICE_POINTS *makeServicePoints(int);

#endif