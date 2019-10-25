#include <stdlib.h>
#include <stdio.h>
#include "hashMap.h"
#include "structs.h"
#include <string.h>
#include <assert.h>

int stringHash1(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += str[i];
	return r;
}

int stringHash2(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += (i+1) * str[i]; /*the difference between 1 and 2 is on this line*/
	return r;
}

void initMap (struct hashMap * ht, int tableSize)
{
	int index;
	if(ht == NULL)
		return;
	ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
	ht->tableSize = tableSize;
	ht->count = 0;
	for(index = 0; index < tableSize; index++)
		ht->table[index] = NULL;
}

void freeMap (struct hashMap * ht)
{  /*write this*/
	struct hashLink* current;
	struct hashLink* next;
	int i;

	/* loop for size of hash */
	for (i = 0; i < ht->tableSize; i++)
	{
		current = ht->table[i];
		/* loop through all */
		while(current != NULL){
			next = current->next;
			free(current->key);
			free(current);
			current = next;
		}
	}
	free(ht->table);
	/* reset values */
	ht->count = 0;
	ht->tableSize = 0;
	ht->table = 0;
}

/* resizes table to the specified size */
void _tableSizeNew(struct hashMap * ht, int newSize){
	hashLink* current;
	hashLink* previous;
	hashMap* oldHash = ht;
	int oldSize = ht->tableSize;
	int i;

	/* initialize new hash with updated size */
	initMap(ht, newSize);
	/* loop for size of old hash */
	for (i = 0; i < oldSize; i++)
	{
		current = oldHash->table[i];
		/* replace keys and values */
		while(current != 0){
			insertMap(ht, current->key, current->value);
			previous = current;
			current = current->next;
			free(previous);
		}
	}
	free(oldHash);
}

void insertMap (struct hashMap * ht, KeyType k, ValueType v)
{  /*write this*/
	int idx;
	hashLink* newHash = (hashLink*)malloc(sizeof(hashLink));
	assert(newHash != 0);
	assert(ht != 0);

	/* index of hash */
	if(HASHING_FUNCTION == 1)
		idx = (ValueType)(labs(stringHash1(k)) % ht->tableSize);
	else
		idx = (ValueType)(labs(stringHash2(k)) % ht->tableSize);

	if(containsKey(ht, k))
		removeKey(ht, k);

	/* key to new hash */
	newHash->key = k;
	newHash->value = v;

	if(ht->table[idx])
		newHash->next = ht->table[idx];
	
	ht->table[idx] = newHash;
	ht->count++;

	/* if reached capacity */
	if(ht->count >= ht->tableSize)
		_tableSizeNew(ht, (2* ht->tableSize));
}

ValueType* atMap (struct hashMap * ht, KeyType k)
{ /*write this*/
	int idx;
	hashLink* current;

	assert(ht != 0);

	/* index of hash */
	if(HASHING_FUNCTION == 1)
		idx = (ValueType)(labs(stringHash1(k)) % ht->tableSize);
	else
		idx = (ValueType)(labs(stringHash2(k)) % ht->tableSize);

	current = ht->table[idx];
	/* loop until the end */
	while(current != 0){
		if(*(current->key) == *k) /* if found value */
			return (&(current->value)); /* return the address of key */
		
		current = current->next;
	}
	/* did not find */
	return NULL;
}

int containsKey (struct hashMap * ht, KeyType k)
{  /*write this*/
	if(atMap(ht, k) == 0) /* did not find */
		return 0;
	else /* found */
		return 1;
}

void removeKey (struct hashMap * ht, KeyType k)
{  /*write this*/
	struct hashLink* current;
	struct hashLink* previous;
	int idx;

	/* index of hash */
	if(HASHING_FUNCTION == 1)
		idx = (ValueType)(labs(stringHash1(k)) % ht->tableSize);
	else
		idx = (ValueType)(labs(stringHash2(k)) % ht->tableSize);

	assert(ht->table[idx != 0]);
	current = ht->table[idx];
	previous = ht->table[idx];

	/* loop until end */
	while(current != 0){
		if(*(current->next->key) == *k){ /* if found */
			if(current == ht->table[idx]){
				ht->table[idx] = current->next;
			}
			else
				previous->next = current->next;

			free(current);
			ht->count--;
			return;
		}
		else{ /* did not find, move to next */
			previous = current;
			current = current->next;
		}
	}
}

int sizeMap (struct hashMap *ht)
{  /*write this*/
	return ht->count;
}

int capacityMap(struct hashMap *ht)
{  /*write this*/
	return ht->tableSize;
}

int emptyBuckets(struct hashMap *ht)
{  /*write this*/
	int bucket = 0;
	int i;

	for (i = 0; i < ht->tableSize; i++)
		if(ht->table[i] == 0)
			bucket++;
	
	return bucket;
}

float tableLoad(struct hashMap *ht)
{  /*write this*/
	float ratio;
	ratio = (ht->count)/(ht->tableSize);
	return ratio;
}
