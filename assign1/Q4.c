/* CS261- Assignment 1 - Q.4*/
/* Name: Alan Macabuhay
 * Date: 4/11/17
 * Solution description: Allocates memory for an array, fills array with unsorted elements,
 *  then sorts array 
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/     
	int i, a;
	struct student temp;

	/* Performs Selection Sort */	
	for(i = 0; i < (n - 1); i++)
	{
		for(a = i + 1; a < n; a++)
		{
			if(students[i].score > students[a].score)
			{
				temp = students[a];
				students[a] = students[i];
				students[i] = temp;
			}		
		}
	}
}

int main(){
    /*Declare an integer n and assign it a value.*/
	int n = 20;
    
    /*Allocate memory for n students using malloc.*/
	struct student *students = malloc(sizeof(struct student) * n);
    
    /*Generate random and unique IDs and random scores for the n students, using rand().*/
	int i, temp, swap;
	for(i = 0; i < n; i++)
	{
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
	printf("\nUnsorted:\n"); 

	/*Print the contents of the array of n students.*/
	for(i = 0; i < n; i++)
	{
		printf("ID%d---%d\n", students[i].id, students[i].score); 
	}
    
	/*Pass this array along with n to the sort() function*/
    sort(students, n);

	printf("\nSorted by score:\n");

    /*Print the contents of the array of n students.*/
 	for(i = 0; i < n; i++)
	{
		printf("ID%d---%d\n", students[i].id, students[i].score); 
	}
   
	free(students);
 
    return 0;
}
