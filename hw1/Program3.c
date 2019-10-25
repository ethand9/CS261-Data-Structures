/* CS261- HW1 - Program3.c*/
/* Name: Ethan Duong
 * Date: 4/4/19
 * Solution description: This program uses a bubble sort algorithm to sort the
 * random numbers in ascending order.
 */
 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

void sort(int* number, int n){
    assert(number != NULL);
    assert(n > 0);
    /*Sort the array of integeres of length n*/
    int i, j, temp;
    /* compare elements, if first is bigger then swap*/
    for(i = 0; i < n-1; i++)
        for(j = 0; j < n-i-1; j++)
            if(number[j] > number[j+1]){
                temp = number[j];
                number[j] = number[j+1];
                number[j+1] = temp;
            }
}

int main(){
    srand(time(NULL)); /* randomize time */
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    int i;
    /*Allocate memory for an array of n integers using malloc.*/
    int *array = malloc(n*sizeof(int));
    /*Fill this array with random numbers, using rand().*/
    for(i = 0; i < n; i++)
        array[i] = rand();
    /*Print the contents of the array.*/
    printf("Unsorted:\n");
    for(i = 0; i < n; i++)
        printf("%d%s%d\n", i+1, ". ", array[i]);
    /*Pass this array along with n to the sort() function of part a.*/
    sort(array, n);
    /*Print the contents of the array.*/
    printf("\nSorted:\n");
    for(i = 0; i < n; i++)
        printf("%d%s%d\n", i+1, ". ", array[i]);
    return 0;
}
