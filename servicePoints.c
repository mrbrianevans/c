#include <servicePoints.h>

/*extern SERVICE_POINTS *makeServicePoints(int numServicePoints)
{
   printf("Asked to make %d new service points\n", numServicePoints);
   SERVICE_POINTS *servicePoints = NULL;
   servicePoints = (SERVICE_POINTS *) malloc(sizeof(SERVICE_POINTS));
   if( servicePoints == NULL )
   {
      printf("Memory allocation failed on makeServicePoints:servicePoints");
      exit(-1);
   }
   servicePoints->numServicePoints = numServicePoints;
   SERVICE_POINT *points = NULL;
   points = (SERVICE_POINT *) malloc(sizeof(SERVICE_POINT));
   if( points == NULL )
   {
      printf("Memory allocation failed on makeServicePoints:points");
      exit(-1);
   }
   SERVICE_POINT *s = NULL;

   points[0] =
   *servicePoints->points = points;
   return servicePoints;
}*/

/*
extern int getNumAvailableServicePoints()
{
}

extern int serveCustomer(CUSTOMER customer)
{
}*/
extern SERVICE_POINTS *makeServicePoints(int numServicePoints)
{
   SERVICE_POINTS *servicePoints = NULL;
   servicePoints = (SERVICE_POINTS *) malloc(sizeof(SERVICE_POINTS));
   if( servicePoints == NULL )
   {
      printf("Memory allocation failed on makeServicePoints:servicePoints");
      exit(-1);
   }
   servicePoints->totalServicePoints = numServicePoints;
   servicePoints->availableServicePoints = numServicePoints;
   return servicePoints;
}
/*

extern int serveCustomer(SERVICE_POINTS *servicePoints, CUSTOMER *customer)
{
   */
/* Free the memory holding the customer *//*

   free(customer);
   */
/* Decrease the number of available service points *//*

   servicePoints->availableServicePoints--;
}*/
