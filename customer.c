#include <customer.h>
#include <stdlib.h>
#include <stdio.h>

extern CUSTOMER makeNewCustomer(int toleranceRemaining)
{
   CUSTOMER *newCustomer = NULL;

   /* allocate memory */
   newCustomer = (CUSTOMER *) malloc(sizeof(CUSTOMER));
   if( newCustomer == NULL )
   {
      printf("Memory allocation failed on makeNewCustomer");
      exit(-1);
   }
   newCustomer->toleranceRemaining = toleranceRemaining;
   newCustomer->timeSpentWaiting = 0;
   return *newCustomer;
}
