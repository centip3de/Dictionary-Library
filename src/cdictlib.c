#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cdictlib.h"

// TODO: Improve this hash function
int getHash(char * key) {
    int sum = 0;
    while(*key) {
        sum += *key;
        key++;
    }
    return sum;
}

Dictionary * newDictionary() {
    int initialSize = 256;

    Dictionary * targetDict = (Dictionary*)malloc(sizeof(Dictionary));
    targetDict->contents = (char **)malloc(sizeof(char **) * initialSize);

    if(targetDict->contents == NULL) {
        printf("[ERROR]: Couldn't initialize dictionary.");
    }

    targetDict->totalSize = initialSize;
    return targetDict;
}

Dictionary * newDictionaryWithSize(int initialSize) {
    Dictionary * targetDict = (Dictionary*)malloc(sizeof(Dictionary));
    targetDict->contents = (char **)malloc(sizeof(char **) * initialSize);

    if(targetDict->contents == NULL) {
        printf("[ERROR]: Couldn't initialize dictionary.");
    }

    targetDict->totalSize = initialSize;
    return targetDict;
}

char * getContents(Dictionary * targetDict, char * key) {
    int hash = getHash(key);
    int index = hash % targetDict->totalSize;
    return targetDict->contents[index];
}

void setContents(Dictionary * targetDict, char * key, char * value) {
    // Double this every time we hit the limit
    if(targetDict->currentSize == targetDict->totalSize) {
        // Malloc should overwrite our memory with 0's, so just create a temp copy and swap
        char ** currentContents = targetDict->contents;
        targetDict->contents = (char **)malloc(sizeof(char ** ) * targetDict->totalSize * 2);
        memcpy(targetDict->contents, currentContents, sizeof(char *)*targetDict->totalSize);

        targetDict->totalSize = targetDict->totalSize * 2;
    }

    int hash = getHash(key);
    int index = hash % targetDict->totalSize;
    targetDict->contents[index] = (char *)malloc(sizeof(char) * strlen(value));
    targetDict->contents[index] = value;
    targetDict->currentSize++;
}

void freeDictionary(Dictionary * targetDict) {
    free(targetDict->contents);
}