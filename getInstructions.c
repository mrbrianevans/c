#include <getInstructions.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

extern int readInputOptionsFromFile(char *filename, INPUT_OPTIONS *inputOptions)
{
	printf("Trying to read options from: %s\n", filename);
	FILE *filepointer;
	filepointer = fopen(filename, "r");
	if( filepointer == NULL )
	{
		fprintf(stderr, "Cannot open input file %s to read options. \n\x1b[31mError:\x1b[0m %s\n", filename, strerror(errno));
		return -1; /* non-zero return value for error. negative for fatal error */
	}
	char templine[200]; /*200 characters should be enough for any input*/
	int maxQueueLength = 0;
	while( !feof(filepointer) )
	{
		fgets(templine, 200, filepointer);
		if( templine[0] != '#' && strlen(templine) > 1 )
		{	
			if( sscanf(templine, "maxQueueLength %d", &inputOptions->maxQueueLength) == 1)
				printf("Read %d as max queue length\n", inputOptions->maxQueueLength);
			if( sscanf(templine, "numServicePoints %d", &inputOptions->numServicePoints) == 1)
				printf("Read %d as number of service points\n", inputOptions->numServicePoints);
			if( sscanf(templine, "closingTime %d", &inputOptions->closingTime) == 1)
				printf("Read %d as closing time\n", inputOptions->closingTime);
			if( sscanf(templine, "averageNewCustomersPerInterval %d", &inputOptions->averageNewCustomersPerInterval) == 1)
				printf("Read %d as average new customers per interval\n", inputOptions->averageNewCustomersPerInterval);
		}
	}
	if(inputOptions->maxQueueLength == 0)
		printf("You failed to enter the required parameter: maxQueueLength\n");
	if(inputOptions->numServicePoints == 0)
		printf("You failed to enter the required parameter: numServicePoints\n");
	if(inputOptions->closingTime == 0)
		printf("You failed to enter the required parameter: closingTime\n");
	if(inputOptions->averageNewCustomersPerInterval == 0)
		printf("You failed to enter the required parameter: averageNewCustomersPerInterval\n");
	fclose(filepointer);
	return 0;
}
