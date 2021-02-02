#include <stdio.h>

void funcA (int);
void funcB (int *);

int main ()
{
	int num = 4;

	printf("num = %d\n", num);
	funcB(&num);
	printf("num = %d\n", num);
	return 0;
}

/* pass by value (x is a new memory location with the value copied) */
void funcA (int x)
{
	x = 99;
}
/* this is pass by reference, will modify the original memory location */
void funcB (int *x)
{
	*x = 99;
}
/* NOTE:
 *
 * Pass by reference is generally superior because it allows you to 
 * update multiple values, but you can only return a single value from a function.
 */
