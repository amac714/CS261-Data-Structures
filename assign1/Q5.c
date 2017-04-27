/* CS261- Assignment 1 - Q.5*/
/* Name: Alan Macabuhay
 * Date: 4/12/17
 * Solution description: This program modifies words to appear with "sticky caps"
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

/************************************************************
 * Function: sticky()
 * Parameters: char *word
 * Modifies word passed in to appear with sticky caps.
 * Example: word = WoRd
 * Pre-conditions: word passed in as normal
 * Post-conditions: word appears in sticky caps
 ***********************************************************/
void sticky(char* word){
     /*Convert to sticky caps*/
	int i;
	
	/* even index conversion */
	for(i = 0; word[i] != '\0'; i += 2) {
		if(word[i] >= 'a' && word[0] <= 'z') {
			word[i] = toUpperCase(word[i]);
		}
	
	}

	/* odd index conversion */
	for(i = 1; word[i] != '\0'; i += 2) {
		if(word[i] >= 'A' && word[i] <= 'Z') {
			word[i] = toLowerCase(word[i]);
		}
	}
}

int main(){
    
	char word[100];		/* max # of characters in word is 100 */

	/*Read word from the keyboard using scanf*/
    printf("\nEnter a word: \n");
	scanf("%s", word);

    /*Call sticky*/
	sticky(word);
    
    /*Print the new word*/
	printf("\nStIcKy word: %s \n", word);
    
    return 0;
}
