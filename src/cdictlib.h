// TODO: Put this in the .h file
typedef struct Dictionary
{
    char ** contents;
    int currentSize;
    int totalSize;
} Dictionary;

int getHash(char * key);
Dictionary * newDictionary();
Dictionary * initDictionaryWithSize(int initialSize);
char * getContents(Dictionary * targetDict, char * key);
void setContents(Dictionary * targetDict, char * key, char * value);
void freeDictionary(Dictionary * targetDict);