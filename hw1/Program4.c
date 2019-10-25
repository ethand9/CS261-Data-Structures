/* CS261- HW1 - Program4.c*/
/* Name: Ethan Duong
 * Date: 4/4/19
 * Solution description: This program uses a bubble sort algorithm to sort
 * students' by their randomized initials
 */
 
#include <stdio.h>
#include <stdlib.h>
#include<time.h> 
#include<assert.h>

struct student{
	char initials[2];
	int score;
};

void sort(struct student* students, int n){
    assert(students != NULL);
    assert(n > 0);
    /*Sort n students based on their initials*/   
    int i, j;
    char temp;
    /* compare elements, if first letter comes afterwards then swap*/
    for(i = 0; i < n-1; i++)
        for(j = 0; j < n-i-1; j++){
            if(students[j].initials[0] > students[j+1].initials[0]){
                /* swap first initials */
                temp = students[j].initials[0];
                students[j].initials[0] = students[j+1].initials[0];
                students[j+1].initials[0] = temp;
                /* swap second initials */
                temp = students[j].initials[1];
                students[j].initials[1] = students[j+1].initials[1];
                students[j+1].initials[1] = temp;
                /* swap scores */
                temp = students[j].score;
                students[j].score = students[j+1].score;
                students[j+1].score = temp;
            }
            /* if first initial same, then compare the second */
            else if(students[j].initials[0] == students[j+1].initials[0]){
                if(students[j].initials[1] > students[j+1].initials[1]){
                    /* swap second initials */
                    temp = students[j].initials[1];
                    students[j].initials[1] = students[j+1].initials[1];
                    students[j+1].initials[1] = temp;
                    /* swap scores */
                    temp = students[j].score;
                    students[j].score = students[j+1].score;
                    students[j+1].score = temp;
                }
            }
        }
}

int main(){
    srand(time(NULL)); /* randomize time */
    /*Declare an integer n and assign it a value.*/
    int n = 10;
    int i;
    /*Allocate memory for n students using malloc.*/
    struct student* stud = (struct student*) malloc(n*sizeof(struct student));
    /*Generate random IDs and scores for the n students, using rand().*/
    for(i = 0; i < n; i++) /* loop for all students */
    {
        /* ascii values 65 to 90 */
        stud[i].initials[0] = (rand()%(90-65))+65;
        stud[i].initials[1] = (rand()%(90-65))+65;
        /* random integer from 0 to 100 */
        stud[i].score = (rand() % 101); 
    }
    /*Print the contents of the array of n students.*/
    printf("Unsorted:\n");
    for(i = 0; i < n; i++) /* loop for all students */
        printf("%d%s%c%c%s%d\n", i+1, ". ", stud[i].initials[0], stud[i].initials[1], " ", stud[i].score);
    /*Pass this array along with n to the sort() function*/
    sort(stud, n);
    /*Print the contents of the array of n students.*/
    printf("Sorted:\n");
    for(i = 0; i < n; i++) /* loop for all students */
        printf("%d%s%c%c%s%d\n", i+1, ". ", stud[i].initials[0], stud[i].initials[1], " ", stud[i].score);
    
    return 0;
}
