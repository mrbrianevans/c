#include "servicePoints.h"

extern SERVICE_POINTS *makeServicePoints(int numServicePoints)
{
   SERVICE_POINTS *servicePoints = NULL;
   servicePoints = (SERVICE_POINTS *) malloc(sizeof(SERVICE_POINTS));
   if( servicePoints == NULL )
   {
      printf("Memory allocation failed on makeServicePoints:servicePoints");
      exit(-2);
   }
   servicePoints->totalServicePoints = numServicePoints;
   servicePoints->availableServicePoints = numServicePoints;
   return servicePoints;
}
