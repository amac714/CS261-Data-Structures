/* CS261- Assignment 1 - Q.2*/
/* Name: Alan Macabuhay
 * Date: 4/11/17
 * Solution description: This program demonstrates what happens to variables when passed
 *	to a function as reference and as value.
 */
 
#include <stdio.h>
#include <stdlib.h>

/********************************************************
 * Function: foo()
 * Paramaters: int *a, int *b, int c
 * Doubles value of a, halves value of b, and assigns
 * a+b to c and returns c.
 * Pre-conditions: a & b passed as reference. c as value
 * Post-conditions: a is doubled, b is halved
 *******************************************************/
int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
	*a = *a * 2;    

    /*Set b to half its original value*/
    *b = *b / 2; 

    /*Assign a+b to c*/
    c = *a + *b;

    /*Return c*/
	return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5;
	int y = 6;
	int z = 7;

    /*Print the values of x, y and z*/
	printf("\nx = %d", x);
	printf("\ny = %d", y);
	printf("\nz = %d", z);    
	printf("\n");
 
	 /*Call foo() appropriately, passing x,y,z as parameters*/
    int temp = foo(&x, &y, z);

    /*Print the value returned by foo*/
	printf("\nc = %d\n", temp); 
   
    /*Print the values of x, y and z again*/
 	printf("\nx = %d", x);
	printf("\ny = %d", y);
	printf("\nz = %d \n", z);    
 
    /*Is the return value different than the value of z?  Why?*/

	/*Yes, return value is different because z was passed as value. Therefore,
     *the value of z could not be changed from inside foo().
	 *The values for x and y were changed because they were passed as reference.*/

    return 0;
}
    
    
