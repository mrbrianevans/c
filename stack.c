#include <stdio.h>
#include <stdlib.h>

struct stackStruct
{
   char data;
   struct stackStruct *nextNode;
};
typedef struct stackStruct STACK;

/* FUNCTION PROTOTYPES */
STACK *makeNewNode(char);

int main()
{
   STACK *root = NULL;
   return 0;
}

STACK *makeNewNode(char data)
{

   STACK *newNode = NULL;

   newNode = (STACK *) malloc(sizeof(STACK));
   if( newNode == NULL )
   {
      printf("Error");
      exit(-1);
   }
   newNode->data = data;
   newNode->nextNode = NULL;
   return newNode;
}
