// This program will read & append up to 100 Student details
// in a text file stored locally.

#include <stdio.h>
#include <stdlib.h>
#define grades "Linked_List_Example_with_TextFile.txt"

//---------------------------------------------------
//					**** STRUCTURES ****
//---------------------------------------------------
typedef struct student{
	char name[30];
	int id;
	float mark;
}student;

//---------------------------------------------------
//					**** ARRAYS ****
//---------------------------------------------------
typedef struct student_array{
	int size;
	student *ptr;
}student_array;

//---------------------------------------------------
//					**** PROTOTYPES ****
//---------------------------------------------------
void print_title();
void print_menu();
void draw_top_border(int border_size);
void draw_bottom_border(int border_size);
void read_file(FILE *fp1, student_array *sample);
void display_students(student_array *a);
float calculate_average(student_array *sample);
void update_file();

//---------------------------------------------------
//					**** MAIN PROGRAM ****
//---------------------------------------------------
int main(){
	int i, answer;
	FILE *fp1;
	fp1 = fopen (grades, "r");
	student_array sample={0, NULL};

	read_file(fp1, &sample);
		//Reads Student Info from grades.txt and stores all in sample array

	print_title();
		//Prints the Program Title

	printf("\n    Welcome to the Student Database Program.\n");
	printf("    This Software can be used to manage (up to 100)\n");
	printf("    student records, which can be found in a file called\n");
	printf("    grades.txt located in the program's root directory.\n\n");
		//Introduces the Program

    while (answer !=4){
   		
    	//While Loop for Menu options.  Entering '4' will quit.
   		print_menu();
   		printf("Please select a menu option (1 - 4) to continue:\n\n");
		scanf("%d",&answer);

		switch (answer)
		{
			case 1: //Display a Student's Details
				display_students(&sample);
				answer=0;
			 	break;

			case 2: //Calculate the average of all Students' Marks
				draw_top_border(1);
				printf("*        The average score per student was %f       *\n", calculate_average(&sample));
				draw_bottom_border(1);
				printf("\n");
				answer=0;
				break;

			case 3: //Add a new Student Record
				if (sample.size >= 100)
				
					//Validate whether Array is full
					printf("Array is full, please try another option.\n");
					
				else{
					update_file();
					fp1 = fopen (grades, "r");
					sample.size=0;
					read_file(fp1, &sample);
				}
				answer=0;
				break;

			case 4: printf("Quit Program.\n");
				break;

			default: printf("You have entered an invalid option.\n");
				answer=0;
				break;
		}
	}
}

//---------------------------------------------------
//					**** FUNCTIONS ****
//---------------------------------------------------


void print_title(){

	//Prints the Title of the Program on the screen
	draw_top_border(2); 	
	printf("*                 Student Database Program                 *\n");
	draw_bottom_border(2);
}


void print_menu(){

	//Prints the Menu of the Program on the screen
	draw_top_border(4);
	printf("*           (1) Display a Student's Details                *\n");
	printf("*           (2) Calculate the average of all marks         *\n");
	printf("*           (3) Add a new Student Record                   *\n");
	printf("*           (4) Quit Program                               *\n");	
	draw_bottom_border(4);
}


void draw_top_border(int border_size){

	//Draws the top half of a graphic border
	int i, j;
	for (i = 0; i < 60; i++)
		printf("*");
	printf("\n");
	for (i = 0; i < border_size/2; i++){
		printf("*");
		for (j = 0; j < 58; j++)
			printf(" ");
		printf("*\n");
	}	
}


void draw_bottom_border(int border_size){

	//Draws the bottom part of the Border
	int i,j;
	for (i = 0; i < border_size/2; i++){
		printf("*");
		for (j = 0; j < 58; j++)
			printf(" ");
		printf("*\n");
	}
	for (i = 0; i < 60; i++)
		printf("*");
	printf("\n");
}


void read_file(FILE *fp1, student_array *sample){

	//Opens grades.txt file and extracts data 
	//into student_array:
	int i;
	fp1 = fopen (grades, "r");
	student *new_array;

	
	if (fp1 == NULL)

		//Returns An error if unable to open file
		printf("Error opening input file\n");
	
	else{
		do{
			if(feof(fp1) )
				break;

			sample->size++;
			new_array=(student*)realloc(sample->ptr,sample->size*sizeof(student));
				//This line of code will prepare an extra 
				//block of memmory for a future element

			if(new_array){
				sample->ptr=new_array;
				
				//Return Pointer to previous memory block 
				//and begin storing data into the array element
				fscanf (fp1, "%s %i %f", sample->ptr[sample->size-1].name, &sample->ptr[sample->size-1].id, &sample->ptr[sample->size-1].mark);
			}

			else{

				//An else clause to prepare for case of unavailable mem.
				printf("Out of memmory!\n");
				sample->size--;
			}
		}while(1);		
		printf("\n");
	}
	fclose(fp1);
}


void display_students(student_array *a){

	//displays the contents of the studentArray array on the 
	//screen in an appropriate format.
	int i;
	printf("\n");
	draw_top_border(2);
	printf("*                     Student Details                      *\n");
	draw_top_border(1);
	for (i = 0; i <a->size; i++){
		printf("* Name: %s\tStudent ID: %d\t\tMark: %f    *\n", a->ptr[i].name, a->ptr[i].id, a->ptr[i].mark );
	}
	draw_bottom_border(1);
	printf("\n");
}


float calculate_average(student_array *sample){

	//calculate the average value of all marks in 
	//studentArray and return the result to the main()
	int i;
	float total=0;
	for (i = 0; i < sample->size; i++)
		total +=sample->ptr[i].mark;
	return total/sample->size;
}


void update_file(){

	//Opens grades.txt in append mode, and 
	//reads in new student details, refreshing
	//The array with the new data by calling read_file()

	student temp;
	student_array new_array={0, NULL};
	FILE *fp1;
	//Normalise temp.id & temp.value for purpose of validation while loops:
	temp.id=0;
	temp.mark=0;	

	printf("Enter Student's Name:\n");
	scanf("%s", temp.name);

	while (temp.id == 0 || temp.id < 0){

		//While loop to validate Student ID No.:
		printf("Enter Student's ID Number:\n");
		scanf("%d", &temp.id);
		if (temp.id >= 1)
			break;
		else
			printf("Please enter a valid Student ID Number.\n");
	}

	while (temp.mark == 0){

		//While loop to validate Student Mark
		printf("Enter Student's mark:\n");
		scanf("%f", &temp.mark);
		if (temp.mark >= 1)
			break;
		else
			printf("Please enter a value greater than zero.\n");		
	}

	fp1 = fopen (grades, "a");
	fprintf(fp1, "\n%s\t%d\t%f", temp.name, temp.id, temp.mark);
	fclose(fp1);
	read_file(fp1, &new_array);

}