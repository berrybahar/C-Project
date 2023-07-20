#include "assembler.h"
#include "file_handling.h"

/**
 * for checking if the file name has an extension
*/
int checkIfFileHasExtension(char *fileName)
{
    char *cp;

    cp = strchr(fileName, '.');

    if(cp == NULL)
        return TRUE;

    return FALSE;
}

/**
 * This program changes the extension of file to the desired extension type
*/
void fileTypeChanger(char *fileName, char *extension)
{
    char *cp;

    if(checkIfFileIsLegal(fileName))/*if the file name already has an extension*/
    {
        cp = strchr(fileName, '.');
    }
    else
    {
        cp = strchr(fileName, '\0');        
    }

    while(*extension != '\0')
    {
        *cp = *extension;
        *++cp;
        *++extension;    
    }
    *cp = '\0';
    printf("%s", &fileName);
}