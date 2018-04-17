#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * dictionary[256][256];
char * dictNames[256];
int numDictNames;


void initDict(const char * dictName, int numElement, const char * dictContains);
char *nextElem(const char * dictName, int curElement);
char *previousElem(const char * dictName, int curElement);

struct dictionary
{
    void (*initDict)(const char *, int, const char *);
    char * (*nextElem)(const char *, int);
    char * (*previousElem)(const char *, int);
};

void initDict(const char * dictName, int numElement, const char * dictContains) /* Initializing the dictionary, with the name, the number of elements in the dictionary,
                                                                        and what the dictionary contains */
{
    if(dictName == NULL) /* No dictionary name, automatically assigning one. */
    {
        dictName = "dictTemp";
        strcpy(dictionary[numDictNames][0], dictName);
        printf("WARNING: Didn't assign a name for your dictionary! Assigning %s as name...\n", dictName);
    }
    else /* There is a dictionary name */
    {
        dictionary[numDictNames][0] = (char*)malloc(sizeof(numDictNames));
        strcpy(dictionary[numDictNames][0], dictName);
    }
    if(numElement == 0)/* Non-specified elements */
    {
        printf("ERROR: You need to specify how many elements your dictionary has!\n");
        free(dictionary);
        free(dictNames);
        exit(EXIT_FAILURE);
    }
    if(numElement >= 256) /*Too many elements */
    {
        printf("ERROR: Too many elements in the dictionary!\n");
        free(dictionary);
        free(dictNames);
        exit(EXIT_FAILURE);
    }
    char dictContainsC[256]; /* dictContains Copy */
    strcpy(dictContainsC, dictContains); /* Copying contents of dictContains to dictContainsC */
    char *dictTokens = NULL; /* Hold parsed tokens */
    dictTokens = strtok(dictContainsC, ","); /* Setting up the parser */
    int i = 1; /* To keep track of dictionary elements. Needs to be one, because dictionary[0][0] is already in use for the dictionary name! */
    while(dictTokens != NULL)
    {
        dictionary[numDictNames][i] = (char*)malloc(sizeof(numDictNames)+sizeof(i)); /* Allocating space for the dictionary */
        strcpy(dictionary[numDictNames][i], dictTokens); /* Copying the parsed tokens to the dictionary */
        dictTokens = strtok(NULL, ",");
        i++; /* Next dictionary element */
    }
    numDictNames++; /* Because we just used a name, we want to add one to it so that it doesn't get overwritten. */
}

char *nextElem(const char * dictName, int curElement) /* Go to the next element in the dictionary. Needs the current dictionary, and what element you start on */
{
    curElement++; /* Needs to be taken up by one, because the dictionaries name resides at; dictionary[0][0] */
    int foundDict = 0; /* My quasi-bool */
    int dictID = 0; /* The ID in the array; dictionary[IDHERE][ELEMENTS_HERE] */
    if(foundDict == 0) /* Searching for the dictionary */
    {
        int i;
        for(i = 0; i < 256; i++) /* Only 256 possible places */
        {
            if(!strcmp(dictName, dictionary[i][0])) /*Checking to see if the dictionary name specified in the parameter equals the current name */
                                                    /* NOTE: The name is stored in; dictionary[id_here][0] */
            {
                foundDict = 1;
                break;
            }
            else
            {
                dictID++; /* If you didn't find it, add one to the ID, and keep going */
            }
        }
        if(foundDict == 0) /* If you can't find it, it was a faulty parameter */
        {
            printf("ERROR: Couldn't find the specified dictionary!");
            free(dictionary);
            free(dictNames);
            exit(EXIT_FAILURE);
        }
    }
    int b;
    curElement++;
    b = curElement; /* In order to return the item requested */
    return dictionary[dictID][b]; /* Returning the item requested */
}

char *previousElem(const char * dictName, int curElement) /* Exact same thing as above, except a different name, and a -- instead of a ++ */
{
    curElement++; /* Needs to be taken up by one, because the dictionaries name resides at; dictionary[0][0] */
    int foundDict = 0;
    int dictID = 0;
    if(foundDict == 0)
    {
        int i;
        for(i =0; i < 256; i++)
        {
            if(!strcmp(dictName, dictionary[i][0]))
            {
                foundDict = 1;
                break;
            }
            else
            {
                dictID++;
            }
        }
        if(foundDict == 0)
        {
            printf("ERROR: Couldn't find the specified dictionary!");
            free(dictionary);
            free(dictNames);
            exit(EXIT_FAILURE);
        }
    }
    if(curElement == 0)
    {
        printf("ERROR: Can't go farther back than 0!");
        free(dictionary);
        free(dictNames);
        exit(EXIT_FAILURE);
    }
    int b;
    b = curElement;
    b = --curElement;
    return dictionary[dictID][b];
}

