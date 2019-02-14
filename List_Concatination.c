//The Purpose of this Program is to concatinate
//two Linked List in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//---------------------------------
//			** STRUCTURES **
//---------------------------------

struct sample {
	char letter;
	struct sample *next;
};

//---------------------------------
//			** PROTOTYPES **
//---------------------------------
void printList (struct sample *list1);
void combine (struct sample *list1, struct sample *list2);

//---------------------------------
//			** MAIN PROGRAM **
//---------------------------------

int main(){
	struct sample *list1, *list2, *head;
	int i;

	head=NULL;

	for (i = 68; i >= 65; i--)
	{
		//This loop creates a small set of letters in
		//a Linked list, ASCII values 68(D)->67(C)->66(B)->65(A) 
		list1 = malloc(sizeof(struct sample));
		list1->letter = i;
		list1->next = head;
		head = list1;
	}

	head = NULL;

	for (i = 72; i >= 69; i--)
	{
		//This loop populates a second list with 
		//values 72(H), 71(G), 70(F), 69(E)
		list2 = malloc(sizeof(struct sample));
		list2->letter = i;
		list2->next = head;
		head = list2;
	}

	printf("List 1 is:\n");
	printList(list1);
	printf("List 2 is:\n");
	printList(list2);
	//Call function to concatinate lists:
	combine(list1, list2);
	printf("Combined List is:\n");
	printList(list1);
}


//---------------------------------
//			** FUNCTIONS **
//---------------------------------

void printList (struct sample *list1)
{
	while (list1 != NULL){
		printf("%c->\n", list1->letter);
		list1=list1->next;
	}
	printf("NULL\n");
}

void combine (struct sample *list1, struct sample *list2)
{
	while (list1->next != NULL)
	{
		//Find the end of the list
		list1=list1->next;
	}

	//change list1->next to the beginning address
	//of list 2.
	list1->next=list2;
}
