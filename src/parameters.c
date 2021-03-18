#include "parameters.h"

extern int readInputOptionsFromFile(char *filename, INPUT_OPTIONS *inputOptions,
                                    FILE *outputFile)
{
   FILE *filepointer;
   filepointer = fopen(filename, "r");
   if( filepointer == NULL )
   {
      fprintf(stderr,
              "Cannot open input file %s to read options. \n\x1b[31mError:\x1b[0m %s\n",
              filename, strerror(errno));
      return -1; /* non-zero return value for error. negative for fatal error */
   }
   char templine[200]; /*200 characters should be enough for any input*/
   /* by scanning each line for the variables, it ensures that commented lines are ignored */
   /* scanning the whole file for these variable names would also scan the comments */
   while( !feof(filepointer))
   {
      fgets(templine, 200, filepointer);
      if( templine[0] != '#' && strlen(templine) > 1 )
      {
         sscanf(templine, "maxQueueLength %d", &inputOptions->maxQueueLength);
         sscanf(templine, "numServicePoints %d",
                &inputOptions->numServicePoints);
         sscanf(templine, "closingTime %d", &inputOptions->closingTime);
         sscanf(templine, "averageNewCustomersPerInterval %d",
                &inputOptions->averageNewCustomersPerInterval);
         sscanf(templine, "averageToleranceToWaiting %d",
                &inputOptions->averageToleranceToWaiting);
         sscanf(templine, "averageServeTime %d",
                &inputOptions->averageServeTime);
      }
   }
   fprintf(outputFile, "\x1b[32mParameters read from %s:\x1b[0m\n", filename);
   fprintf(outputFile, "Max queue length:          %d\n",
           inputOptions->maxQueueLength);
   fprintf(outputFile, "Number of service points:  %d\n",
           inputOptions->numServicePoints);
   fprintf(outputFile, "Closing time:              %d\n",
           inputOptions->closingTime);
   fprintf(outputFile, "Average new customers per interval: %d\n",
           inputOptions->averageNewCustomersPerInterval);
   fprintf(outputFile, "Average tolerance to waiting:       %d\n",
           inputOptions->averageToleranceToWaiting);
   fprintf(outputFile, "Average serve time:                 %d\n",
           inputOptions->averageServeTime);
   /* if values are unspecified, defaults are used and the user is notified */
   if( inputOptions->maxQueueLength == 0 )
   {
      fprintf(outputFile, "Using default value of %d for maxQueueLength\n", 20);
      inputOptions->maxQueueLength = 20;
   }
   if( inputOptions->numServicePoints == 0 )
   {
      fprintf(outputFile, "Using default value of %d for numServicePoints\n",
              3);
      inputOptions->numServicePoints = 3;
   }
   if( inputOptions->closingTime == 0 )
   {
      fprintf(outputFile, "Using default value of %d for closingTime\n", 100);
      inputOptions->closingTime = 100;
   }
   if( inputOptions->averageNewCustomersPerInterval == 0 )
   {
      fprintf(outputFile,
              "Using default value of %d for averageNewCustomersPerInterval\n",
              3);
      inputOptions->averageNewCustomersPerInterval = 3;
   }
   if( inputOptions->averageServeTime == 0 )
   {
      fprintf(outputFile, "Using default value of %d for averageServeTime\n",
              2);
      inputOptions->averageServeTime = 2;
   }
   if( inputOptions->averageToleranceToWaiting == 0 )
   {
      fprintf(outputFile,
              "Using default value of %d for averageToleranceToWaiting\n", 15);
      inputOptions->averageToleranceToWaiting = 15;
   }
   fprintf(outputFile, "\n");
   fclose(filepointer);

   /* setup random number generator */
   const gsl_rng_type *T;
   /*gsl_rng *r;*/
   gsl_rng_env_setup();
   T = gsl_rng_default;
   inputOptions->r = gsl_rng_alloc(T);
   gsl_rng_set(inputOptions->r, time(0));
   return 0; /*return SUCCESS if no errors have occurred*/
}
