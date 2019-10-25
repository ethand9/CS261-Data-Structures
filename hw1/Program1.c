/* CS261- HW1 - Program1.c*/
/* Name: Ethan Duong
 * Date: 4/4/19
 * Solution description: This program creates three integers randomly from 0 to 10 then passes them into a function. 
 * The first number is increased, the second is decreased, then the second number is subtracted from the first and the answer is returned.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int foo(int* a, int* b, int c){
    /* Increment a */
    (*a)++;
    /* Decrement  b */
    (*b)--;
    /* Assign a-b to c */
    c = ((*a) - (*b));
    /* Return c */
    return c;
}

int main(){
    /* Declare three integers x,y and z and initialize them randomly to values in [0,10] */
    srand(time(NULL)); /* randomize time */
    /* assign these a random integer from 0 to 10 */
    int x = (rand() % 11);
    int y = (rand() % 11);
    int z = (rand() % 11);
    
    int answer;

    /* Print the values of x, y and z */
    printf("\nThe initial values of XYZ are\n");
    printf("%s%d%s%d%s%d\n", "X:", x, "\nY:", y, "\nZ:", z);
    
    /* Call foo() appropriately, passing x,y,z as parameters */
    answer = foo(&x, &y, z);
    
    /* Print the values of x, y and z */
    printf("\nThe updated values of XYZ are\n");
    printf("%s%d%s%d%s%d\n", "X:", x, "\nY:", y, "\nZ:", z);
    
    /* Print the value returned by foo */
    printf("\n%s%d\n\n", "Return value:", answer);
    
    /* Is the return value different than the value of z?  Why? */
    printf("Yes the return value is different because the answer was returned into \na different variable that was not Z.\n\n");
    return 0;
}
    
    
