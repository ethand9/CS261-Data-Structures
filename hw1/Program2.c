/* CS261- HW1 - Program2.c*/
/* Name: Ethan Duong
 * Date: 4/4/19
 * Solution description: This program allocates memory for 10 different students.
 * Then it assigns random capital initials in ASCII then a random score from 0 to 100.
 */
 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h> 
#include<assert.h>

#define MAX_SIZE 10

struct student{ /* given */
	char initials[2];
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student* person = (struct student*) malloc(MAX_SIZE*sizeof(struct student));
     
     /*return the pointer*/
     return person;
}

void generate(struct student* students){
     /*Generate random initials and scores for ten students.
	The two initial letters must be capital and must be between A and Z. 
	The scores must be between 0 and 100*/
     int i;
     for(i = 0; i < MAX_SIZE; i++) /* loop for all students */
     {
          /* ascii values 65 to 90 */
          students[i].initials[0] = (rand()%(90-65))+65;
          students[i].initials[1] = (rand()%(90-65))+65;
          /* random integer from 0 to 100 */
          students[i].score = (rand() % 101); 
     }
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              1. Initials  Score
              2. Initials  Score
              ...
              10. Initials Score*/
     int i;
     for(i = 0; i < MAX_SIZE; i++) /* loop for all students */
          printf("%d%s%c%c%s%d\n", i+1, ". ", students[i].initials[0], students[i].initials[1], " ", students[i].score);
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     int i;
     int min = students[0].score; 
     int max = students[0].score;
     double sum = 0;
     double avg;

     for(i = 0; i < MAX_SIZE; i++) /* loop for all students*/
     {
          /* calculate sum */
          sum += students[i].score;
          /* if bigger than max then replace it */
          if(students[i].score > max)
               max = students[i].score;
          /* if smaller than min then replace it */
          if(students[i].score < min)
               min = students[i].score;
     }
     avg = sum/MAX_SIZE;

     printf("\n%s%d\n", "The highest score is:", max);
     printf("%s%d\n", "The lowest score is:", min);
     printf("%s%f\n", "The average is:", avg);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
     assert(stud != NULL);
     free(stud);
}

int main(){
     struct student* stud = NULL; /* given */

     srand(time(NULL)); /* randomize time */

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
