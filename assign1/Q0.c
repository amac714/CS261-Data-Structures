/* CS261- Assignment 1 - Q. 0*/
/* Name: Alan Macabuhay
 * Date: 4/6/17
 * Solution description: This program demonstrates how to work with pointers.
 */
 
#include <stdio.h>
#include <stdlib.h>


/*****************************************************************
 ** Function: fooA
 ** Prints value pointed to, address pointed to, and address of iptr
 ** Parameters: int *iptr
 ** Pre-conditions: parameter passed as address of an int variable
 *****************************************************************/
void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
     printf("\nValue pointed to by iptr: %d", *iptr);

     /*Print the address pointed to by iptr*/
	 printf("\nAddress pointed to by iptr: %p", iptr);
     
     /*Print the address of iptr itself*/
	 printf("\nAddress of iptr: %p", &iptr);
}

int main(){
    
    int x = 5;		/*declare an integer x*/
    
    /*print the address of x*/
	printf("\nAddress of x: %p", &x);
    
    /*Call fooA() with the address of x*/
	fooA(&x);
    
    /*print the value of x*/
	printf("\nValue of x: %d \n", x);
    
    return 0;
}
