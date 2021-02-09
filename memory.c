#include <stdio.h>
#include <stdlib.h>

int main() 
{
	int *p = NULL;
	
	p = (int *)malloc(100*sizeof(int)); /* use sizeof rather than hard coding 4 bytes */
	if( p==NULL)
	{
		printf("Memory allocation failed\n");
		exit(-1);
	}	
	printf("P = %p\n", p);

	return 0;
}
