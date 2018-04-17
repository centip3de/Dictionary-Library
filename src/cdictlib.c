#include <stdlib.h>
#include "cdictlib.h"

// TODO: Improve this hash function
int getHash(char * key) {
    int sum = 0;
    while(key != NULL) {
        sum += *key;
        key++;
    }
    return sum;
}

void * initDictionary(Dictionary * targetDict) {
    int initialSize = 256;
    targetDict->contents = (char *)malloc(sizeof(char *) * initialSize);
    targetDict->totalSize = initialSize;
}

void * initDictionaryWithSize(Dictionary * targetDict, int initialSize) {
    targetDict->contents = (char *)malloc(sizeof(char *) * initialSize);
    targetDict->totalSize = initialSize;
}

char * getContents(Dictionary * targetDict, char * key) {
    int hash = getHash(*key);
    int index = hash % targetDict->currentSize;
    return targetDict->contents[index];
}

void setContents(Dictionary * targetDict, char * key, char * value) {

    // Double this every time we hit the limit
    if(targetDict->currentSize == targetDict->totalSize) {
        targetDict->contents = (char *)malloc(sizeof(char * ) * targetDict->totalSize * 2);
        targetDict->totalSize = targetDict->totalSize * 2;
    }

    int hash = getHash(*key);
    int index = hash % targetDict->currentSize;
    targetDict->contents[index] = *value;
    targetDict->currentSize++;
}

void freeDictionary(Dictionary * targetDict) {
    free(targetDict->contents);
}