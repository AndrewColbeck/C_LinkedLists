// This Program is designed to insert
// new nodes into a list, and arrange
// the list in ascending order.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* self-referential structure*/
struct listNode
{
	int data; /* each listNode contains a character*/
	struct listNode *nextPtr; /*pointer to next node*/
}; /* end structure listNode*/
typedef struct listNode ListNode; /* synonym for struct listNode*/
typedef ListNode *ListNodePtr; /* synonym for ListNode* */
/* prototypes*/
void insert( ListNodePtr *sPtr, char value);
int sumList( ListNodePtr currentPtr );
void printList( ListNodePtr currentPtr);

int main( void )
{
	
	ListNodePtr startPtr = NULL; /* initially there are no nodes*/
	int i, item, sum;
	float avg;
	srand(time(NULL));
	for (i = 0; i < 10; i++)
	{
		item = rand()%51;
		insert (&startPtr, item);
	}

	printList(startPtr);
	sum=sumList(startPtr);
	printf("sum = %d\n", sum);
	avg=(float)sum/10;
	printf("Average = %.2f\n", avg);

} /* end main*/
/* display program instructions to user*/

/* insert a new value into the list in sorted order*/
void insert( ListNodePtr *sPtr, char value )
{
	ListNodePtr newPtr; /* pointer to new node*/
	ListNodePtr previousPtr; /* pointer to previous node in list*/
	ListNodePtr currentPtr; /*	pointer to current node in list*/
	newPtr = malloc( sizeof( ListNode ));	/* create node*/
	if ( newPtr != NULL )  /* is space available*/
	{
		newPtr->data = value; /* place value in node*/
		newPtr->nextPtr = NULL; /*	node does not link to another node*/
		previousPtr = NULL;
		currentPtr = *sPtr;
		/* loop to find the correct location in the list*/
		while ( currentPtr != NULL && value > currentPtr ->data)
		{
			previousPtr = currentPtr; /* walk to ...*/
			currentPtr = currentPtr->nextPtr; /* ... next node*/
		} /* end while*/
		/* insert new node at beginning of list*/
		if ( previousPtr == NULL )
		{
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		} /* end if*/
		else   /* insert new node between previousPtr and currentPtr*/
		{
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		} /* end else*/
	} /* end if*/
	else
	{
		printf( "%c not inserted. No memory available.\n", value );
	} /* end else*/
} /* end function insert*/
/* delete a list element*/

void printList( ListNodePtr currentPtr )
{
		puts( "The list is: " );
		/* while not the end of the list*/
		while ( currentPtr != NULL )
		{
			printf( "%d --> ", currentPtr->data );
			currentPtr = currentPtr ->nextPtr;
		} /* end while*/
		puts( "NULL\n" );
	 /* end else*/
} /* end function printList */

int sumList( ListNodePtr currentPtr )
{
		int sum=0;
		/* while not the end of the list*/
		while ( currentPtr != NULL )
		{
			sum += currentPtr->data;
			currentPtr = currentPtr ->nextPtr;
		} /* end while*/
		return sum;
	 /* end else*/
} /* end function printList */


