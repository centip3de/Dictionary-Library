#include "cdictlib.h"
#include <stdio.h>

int main(int argc, char** argv) {
    Dictionary * dictionary = newDictionary();
    printf("Dictionary initalized.\n");
    setContents(dictionary, "Test", "Other test");
    printf("Output: %s\n", getContents(dictionary, "Test"));
    freeDictionary(dictionary);
    return 0;
}