#include <getInstructions.h>

extern int readInputOptionsFromFile(char *filename, INPUT_OPTIONS *inputOptions)
{
   FILE *filepointer;
   filepointer = fopen(filename, "r");
   if( filepointer == NULL )
   {
      fprintf(stderr, "Cannot open input file %s to read options. \n\x1b[31mError:\x1b[0m %s\n", filename,
              strerror(errno));
      return -1; /* non-zero return value for error. negative for fatal error */
   }
   char templine[200]; /*200 characters should be enough for any input*/
   while( !feof(filepointer))
   {
      fgets(templine, 200, filepointer);
      if( templine[0] != '#' && strlen(templine) > 1 )
      {
         sscanf(templine, "maxQueueLength %d", &inputOptions->maxQueueLength);
         sscanf(templine, "numServicePoints %d", &inputOptions->numServicePoints);
         sscanf(templine, "closingTime %d", &inputOptions->closingTime);
         sscanf(templine, "averageNewCustomersPerInterval %d", &inputOptions->averageNewCustomersPerInterval);
         sscanf(templine, "averageToleranceToWaiting %d", &inputOptions->averageToleranceToWaiting);
         sscanf(templine, "averageServeTime %d", &inputOptions->averageServeTime);
      }
   }
   if( inputOptions->maxQueueLength == 0 )
      printf("You failed to enter the required parameter: maxQueueLength\n");
   if( inputOptions->numServicePoints == 0 )
      printf("You failed to enter the required parameter: numServicePoints\n");
   if( inputOptions->closingTime == 0 )
      printf("You failed to enter the required parameter: closingTime\n");
   if( inputOptions->averageNewCustomersPerInterval == 0 )
      printf("You failed to enter the required parameter: averageNewCustomersPerInterval\n");
   if( inputOptions->averageServeTime == 0 )
      printf("You failed to enter the required parameter: averageServeTime\n");
   if( inputOptions->averageToleranceToWaiting == 0 )
      printf("You failed to enter the required parameter: averageToleranceToWaiting\n");
   fclose(filepointer);

   /* setup random number generator */
   const gsl_rng_type *T;
   /*gsl_rng *r;*/
   gsl_rng_env_setup();
   T = gsl_rng_default;
   inputOptions->r = gsl_rng_alloc(T);
   gsl_rng_set(inputOptions->r, time(0));


   return 0;
}
