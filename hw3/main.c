#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hashMap.h"

/*
 the getWord function takes a FILE pointer and returns you a string which was
 the next word in the in the file. words are defined (by this function) to be
 characters or numbers seperated by periods, spaces, or newlines.
 
 when there are no more words in the input file this function will return NULL.
 
 this function will malloc some memory for the char* it returns. it is your job
 to free this memory when you no longer need it.
 */
char* getWord(FILE *file); /* prototype */

/****************************************/

int main (int argc, const char * argv[]) {
    /*Write this function*/
    const char* fileName;
    struct hashMap* hashTable = (hashMap*)malloc(sizeof(hashMap));
    struct hashLink* temp;
    FILE* fileptr;
    char* word;
    char* tempWord;
    int* count;
    int i;

    /* get text file */
    if(argc == 2)
        fileName = argv[1];
    else
        fileName = "input.txt";

    /* open file */
    fileptr = fopen(fileName, "r");
    assert(fileptr != NULL);

    initMap(hashTable, 1000);

    /* get words from file */
    word = getWord(fileptr);
    while(word != 0){
        if(containsKey(hashTable, word) == 1){
            count = atMap(hashTable, word);
            (*count)++;
        }
        else
            insertMap(hashTable, word, 1);

        /* free the memory from getword */
        tempWord = word;
        word = getWord(fileptr);
        free(tempWord);
    }

    /* close file */
    fclose(fileptr);

    for (i = 0; i < hashTable->tableSize; i++){
        temp = hashTable->table[i];
        while(temp != 0){
            printf("%s%s%d\n", temp->key, ": ", temp->value);
            temp = temp->next;
        }
    }
    freeMap(hashTable);
    free(hashTable);
    return 0;
}

char* getWord(FILE* file){
    int length = 0;
    int maxLength = 20;
    char character;

    char* word = (char*)malloc(sizeof(char)*maxLength);
    assert(word != NULL);

    while((character = fgetc(file)) != EOF){
        /* only letters, numbers, and apostrophe */
        if((character >= '0' && character <= '9') || (character >= 'A' && character <= 'Z') || 
            (character >= 'a' && character <= 'z') || character == 39){
                word[length] = character;
                length++;
        } 
        else if(length > 0)
            break;
    }

    if(length == 0){
        free(word);
        return NULL;
    }

    word[length] = '\0';
    return word;
}