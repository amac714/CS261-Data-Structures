/* CS261- Assignment 1 - Q.1*/
/* Name: Alan Macabuhay
 * Date: 4/6/17
 * Solution description: This program demonstrates working with structs and dynamic memory
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

/***************************************************************
 * Function: allocate()
 * Allocates memory for ten students. 
 * Returns a pointer to struct student
 **************************************************************/
struct student* allocate(){
     /*Allocate memory for ten students*/
	struct student *roster = malloc(sizeof(struct student) * 10);
     
     /*return the pointer*/
	return roster;
}

/****************************************************************
 * Function: generate()
 * Parameter: struct student *students
 * Generates random scores and unique IDs for ten students
 * Pre-Conditions: memory allocated for 10 students
 * Post-Conditions: student IDs and scores are assigned values
 ***************************************************************/
void generate(struct student* students){
	 /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
    
	int i, temp, swap;
	
	for(i = 0; i < 10; i++) {
		students[i].id = i + 1;
		students[i].score = rand() % (100 + 1);
	}

	/* shuffle IDs around */
	for(i = 0; i != 10; i++) {
		swap = rand() % (i + 1);

		temp = students[i].id;
		students[i].id = students[swap].id;
		students[swap].id = temp;
	}
}

/****************************************************************
 * Function: output()
 * Parameter: struct student *students
 * Prints out student IDs and their scores
 * Pre-Condition: IDs and scores have values
 ***************************************************************/
void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
	printf("\n");
	for(int i = 0; i < 10; i++) {
		printf("ID%d %d \n", students[i].id, students[i].score); 
	}

}

/******************************************************************
 * Function: summary()
 * Parameter: struct student *students
 * Prints min, max, and avg of the 10 scores
 * Pre-Condition: scores have been generated
 ******************************************************************/
void summary(struct student* students){
	
	int		min = 100;
	int		max = 0;
	int		count = 0;
	int		total = 0;
	double	avg = 0.0;
	

     /*Compute and print the minimum, maximum and average scores of the ten students*/

	/* get minimum and maximum */
	while(count < 10) {
		
		if(students[count].score > max)
			max = students[count].score;

		if(students[count].score < min)
			min = students[count].score;

		count++;
	}   

	/* compute total score */
	for(int i = 0; i < 10; i++) {
		
		total = total + students[i].score;
	}  

	/* compute average score */
	avg = total / 10.0;

	/* prints min, max, and avg */
	printf("\nMinimum: %d", min);
	printf("\nMaximum: %d", max);
	printf("\nAverage: %f", avg);
	printf("\n\n");
}

/****************************************************************
 * Function: deallocate()
 * Parameter: struct student *stud
 * Deallocates memory from pointer to struct student
 * Pre-Condition: students is not NULL
 * Post-Condition: memory free'd 
 ***************************************************************/
void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
	if(stud != NULL)
		free(stud);
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
	stud = allocate();
    
    /*call generate*/
    generate(stud);

    /*call output*/
	output(stud);
    
    /*call summary*/
	summary(stud);
 
    /*call deallocate*/
	deallocate(stud);

    return 0;
}
