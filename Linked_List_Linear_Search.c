// This Program will use Linear search
// a Linked List for a key value.
// By Andrew Colbeck 2017

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//------------------------------//
//	** STRUCTURES **        //
//------------------------------//

struct sample {
	int value;
	struct sample *next;
};

//------------------------------//
//	** FUNCTIONS **		//
//------------------------------//

struct sample* linearLinkedListSearch(struct sample* linkAddress, int key)
{
	// Linear search will begin comparing list values to
	// the key starting from link 0, until address = NULL.

	int i=1;
	struct sample* result = NULL;

	while (linkAddress != NULL)
	{
		printf("Checking Link Number [%i], value: %i - ", i, linkAddress->value);
		if (linkAddress->value == key)
		{
			return linkAddress;
		}
		printf("No Match.\n");
		linkAddress = linkAddress->next;
		i++;
	}

	return NULL;
}

void printList (struct sample *list1)
{
	//Function to print a passed list
	while (list1 != NULL){
		printf("%i->", list1->value);
		list1=list1->next;
	}
	printf("NULL\n");
}

//------------------------------//
//	** MAIN PROGRAM **	//
//------------------------------//


int main()
{
	srand(time(NULL));
	struct sample *list1 = NULL, *head = NULL, *result = NULL;
	int i, key;

	for (i = 0; i < 10; i++)
	{
		//This loop creates a random set of integers in
		//a Linked list between 0 to 100 
		list1 = malloc(sizeof(struct sample));
		list1->value = rand()%101;
		list1->next = head;
		head = list1;
	}
		
	printf("The List is:\n");
		printList(list1);

	printf("\n(Using Linear Search) enter a key to search for: ");
	scanf("%i", &key);

	result = linearLinkedListSearch(list1, key);

	if (result != NULL)
		printf("match found: %i\n\n", result->value);

	if (result == NULL)
		printf("No Match found.\n\n");	

}
