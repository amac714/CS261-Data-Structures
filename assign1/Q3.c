/* CS261- Assignment 1 - Q.3*/
/* Name: Alan Macabuhay
 * Date: 4/14/17
 * Solution description: Sorts an array of length n in ascending order
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

/***********************************************************
 * Function: sort()
 * Parameters: int *number, int n
 * Performs a selection sort to sort given array of length n
 * Pre-Conditions: unsorted array
 * Post-Conditions: sorted array in ascending order
 **********************************************************/
void sort(int *number, int n){
     /*Sort the given array number , of length n*/     
	int i, a, minIndex, minVal;
	
	/* Performs Selection Sort */
	for(i = 0; i < (n - 1); i++)
	{
		minIndex = i;
		minVal = number[i];

		for(a = i + 1; a < n; a++)
		{
			if(number[a] < minVal)
			{
				minVal = number[a];
				minIndex = a;
			}
		}

		number[minIndex] = number[i];
		number[i] = minVal;
	}
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
	int n = 20;
	int i;
	int *intArray;
    
	/*Allocate memory for an array of n integers using malloc.*/
	intArray = malloc(sizeof(int*) * n);   

	/*Fill this array with random numbers, using rand().*/
	for(i = 0; i < n; i++) 
	{
		intArray[i] = rand() % 100;
	}

	printf("\nUnsorted:\n");

	/*Print the contents of the array.*/
	for(i = 0; i < n; i++) 
	{
		printf("%d ", intArray[i]);
	}


    /*Pass this array along with n to the sort() function of part a.*/
    sort(intArray, n);

	printf("\n\nSorted: \n");

    /*Print the contents of the array.*/    
 	for(i = 0; i < n; i++) 
	{
		printf("%d ", intArray[i]);
	}

	free(intArray);
	printf("\n");
	
    return 0;
}
