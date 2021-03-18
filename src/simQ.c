#include "simQ.h"

int main(int argc, char *argv[])
{
   if( argc < 4 )
   {
      fprintf(stderr,
              "\x1b[31mError:\x1b[0m Not enough command line arguments. Try ./simQ fileIn numSims fileOut\n");
      return -1;
   }

   char *inputFile = argv[1];
   int numSims = 0;
   sscanf(argv[2], "%d", &numSims);
   char *outputFileName = argv[3];
   FILE *outputFile = NULL;
   if((outputFile = fopen(outputFileName, "w")) == NULL )
   {
      fprintf(stderr,
              "Cannot create/write to output file %s: \n\x1b[31mError:\x1b[0m %s",
              outputFileName, strerror(errno));
   }
   /*Get input options from file (command line argument)*/
   INPUT_OPTIONS *inputOptions = NULL;
   inputOptions = (INPUT_OPTIONS *) malloc(sizeof(INPUT_OPTIONS));
   if( inputOptions == NULL )
   {
      fprintf(stderr,
              "\x1b[31mError:\x1b[0m Memory allocation failed for inputOptions");
      return -2; /* minus two for failed memory allocation */
   }
   if( readInputOptionsFromFile(inputFile, inputOptions, outputFile) != 0 )
      return -1;
   inputOptions->numSims = numSims;
   MULTIPLE_STATISTICS *multipleStatistics = NULL;
   multipleStatistics = (MULTIPLE_STATISTICS *) malloc(
         sizeof(MULTIPLE_STATISTICS));
   if( multipleStatistics == NULL )
   {
      /*todo: if i have time, make each error print out the line number and file that generated it*/
      fprintf(stderr,
              "\x1b[31mError:\x1b[0m Memory allocation failed for multipleStatistics");
      return -2; /* minus two for failed memory allocation */
   }

   int i;
   for(i = 0; i < numSims; ++i)
   {
      /* run post office once, and save statistics */
      int status = singleSimulation(inputOptions, outputFile,
                                    multipleStatistics);
      if( status != 0 ) return status;
   }
   if( numSims > 1 )
   {
      printMultipleStatistics(outputFile, multipleStatistics);
   }
   free(inputOptions);
   free(multipleStatistics);
   fclose(outputFile);
   printf("Successfully written output of simulation to %s\n", outputFileName);
   return 0;
}