// TODO: Put this in the .h file
typedef struct Dictionary
{
    char * contents;
    int currentSize;
    int totalSize;
} Dictionary;

int getHash(char * key);
void * initDictionary(Dictionary * targetDict);
void * initDictionaryWithSize(Dictionary * targetDict, int initialSize);
char * getContents(Dictionary * targetDict, char * key);
void setContents(Dictionary * targetDict, char * key, char * value);
void freeDictionary(Dictionary * targetDict);