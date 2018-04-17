#include "cdictlib.h"
#include <stdio.h>

int main(int argc, char** argv) {
    Dictionary * dictionary;
    initDictionary(dictionary);
    printf("Dictionary initalized.\n");
    printf("Output: %s\n", getContents(dictionary, "Test"));
    freeDictionary(dictionary);
    return 0;
}