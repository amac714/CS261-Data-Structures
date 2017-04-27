/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post:	
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function */		
	

	char ch;
	int flag = 0;
	DynArr *stack = newDynArr(5);		//starting cap of our dynamic array stack is 5
	
	while((ch = nextChar(s))) {
		
		//push any opening parentheses into stack
		if(ch == '(' || ch == '{' || ch == '[') {
			pushDynArr(stack, ch);
		}
		
		//pop stack if a closing parenthesis matches an opening parenthesis 
		if((ch == ')' && topDynArr(stack) == '(') || (ch == '}' && topDynArr(stack) == '{') 
			|| (ch == ']' && topDynArr(stack) == '[')) {
			
				popDynArr(stack);
		}

		//if stack is empty then parentheses are balanced
		if(isEmptyDynArr(stack)) {
			flag = 1;
		}
	}

	deleteDynArr(stack);
	return flag;
}

int main(int argc, char* argv[]){
	
	char* s=argv[1];	
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

