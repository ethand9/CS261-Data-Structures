/*	stackapp.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	char ch;  /*stores the current character from the input string*/
	char ts;  /*stores the top element of the stack*/
	int b=1;  /*Boolean variable b=1 means balanced; b=0 means unbalanced string*/

	DynArr *stack;
	stack=newDynArr(5);/*initialize stack with capacity = 5*/


	if (s && strlen(s))
		while(1)
		{
			ch=nextChar(s);
			
			if(ch==0 || ch=='\0')
				break;

 
			if(ch=='(' || ch=='[' || ch=='{' ){
				pushDynArr(stack,ch);
				ts = topDynArr(stack);
			}
			else
			{
				/* FIXME: You will write this part of the function */
				/* if closing end: ), ], }, and matching, then pop off stack */
				/* check if closing does not have a pair*/
				if((ch == ')' ) && (ts != '(')){
					deleteDynArr(stack);
					b = 0;
					return b;
				}
				else if((ch == ']' ) && (ts != '[')){
					deleteDynArr(stack);
					b = 0;
					return b;
				}
				else if((ch == '}' ) && (ts != '{')){
					deleteDynArr(stack);
					b = 0;
					return b;
				}
				/* remove pairs */
				if((ch == ')' ) && (ts == '('))
					popDynArr(stack);
				else if((ch == ']' ) && (ts == '['))
					popDynArr(stack);
				else if((ch == '}' ) && (ts == '{'))
					popDynArr(stack);
				/* if stack is not empty, point to newest top */
				if(!(isEmptyDynArr(stack)))
					ts = topDynArr(stack);
			}
		}

        /* Free the memory allocated to stack, and return b=1 or b=0 */
		/* if nothing is in the stack at the end, then it is balanced */
		if(isEmptyDynArr(stack))
			b = 1;
		else
			b = 0;
		deleteDynArr(stack);
		return b; 
	/* FIXME: You will write this part of the function */

}

int main(int argc, char* argv[]){

	char* s=argv[1];	

	/* char s[]="()+x+r*{{{((--{{[()[]]}}))}}}";	 */


	int res;

	printf("Assignment 2\n");
	
	if(argc==2)
	{
		res = isBalanced(s);

		if (res)
			printf("The string %s is balanced\n",s);
		else 
			printf("The string %s is not balanced\n",s);
	}
	else
		printf("Please enter a string to be evaluated.\n");

	
	return 0;	
}

