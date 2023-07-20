#include "assembler.h"
#include "file_handling.h"

/**
 * for checking if the file name has an extension
*/
int checkIfFileHasExtension(char *fileName)
{
    char *cp;

    cp = strchr(fileName, '.');

    if(cp != NULL)
        return TRUE;

    return FALSE;
}

/**
 * This program changes the extension of file to the desired extension type
*/
char *fileExtensionChanger(char *fileName, char *extension)
{   
    int lengthOfFileName = lenCharArray(fileName);
    char *extendedFile = (char *)malloc(sizeof(char)*(lengthOfFileName + 3));
    int i = 0;

    while(i < lengthOfFileName)
    {
        *(extendedFile + i) = *(fileName + i); 
        i++;
    }
    
    return strcat(extendedFile, extension);
}

int lenCharArray(char *string)
{
    int count = 0;
    int i = 0;
    while(*(string + i) != '\0')
    {
        count++;
        i++;
    }
    count++;

    return count;
}