#include "cdictlib.h"
#include <stdio.h>

int main(int argc, char** argv) {
    Dictionary * dictionary = newDictionary();
    printf("Dictionary initalized.\n");

    setContents(dictionary, "Test", "Other test");
    setContents(dictionary, "Other Test", "Test");
    setContents(dictionary, "My name", "centip3de");
    setContents(dictionary, "Your name", "Not centip3de");

    printf("Output: %s\n", getContents(dictionary, "Test"));
    printf("Output: %s\n", getContents(dictionary, "Other Test"));
    printf("Output: %s\n", getContents(dictionary, "My name"));
    printf("Output: %s\n", getContents(dictionary, "Your name"));

    freeDictionary(dictionary);
    return 0;
}