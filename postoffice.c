/* Coursework - post office queueing system */
#include <queue.h>
#include <getInstructions.h>

/* MAIN --------------------------------------------------*/
int main (int argc, char **argv)
{
  /* Get input options from file (command line argument) */
  INPUT_OPTIONS *inputOptions = NULL;
	inputOptions = (INPUT_OPTIONS *)malloc(sizeof(INPUT_OPTIONS));
  if( readInputOptionsFromFile(argv[1], inputOptions) == 0 )
  {
    printf("Options:\n");
    printf("Max queue length: %d\n", inputOptions->maxQueueLength);
    printf("Number of service points: %d\n", inputOptions->numServicePoints);
    printf("Closing time: %d\n", inputOptions->closingTime);
    printf("Average new customers per interval: %d\n", inputOptions->averageNewCustomersPerInterval);
  }
  else
    return -1;

  int *numSims = argv[2]; /*not sure if this type conversion will work*/

	/* --- Example queue --- */
	QUEUE *head = makeNewQueueItem(3);
	QUEUE *tail = makeNewQueueItem(0);
	head->next = tail;
	tail->previous = head;
	tail = push(1, tail);
	tail = push(4, tail);
	tail = push(1, tail);
	tail = push(5, tail);
	tail = push(9, tail);
	head = shift(head);
	tail = push(2, tail);
	tail = push(6, tail);
	head = shift(head);
	tail = push(5, tail);
	tail = push(3, tail);
	printQueueFromHead(head);

	char *fileOut = argv[3];
	/*write output to file*/
	return 0;
}

