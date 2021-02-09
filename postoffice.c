/* Coursework - post office queueing system */
#include <queue.h>


/* MAIN --------------------------------------------------*/
int main ()
{
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
	return 0;
}

