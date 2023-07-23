#include "assembler.h"

int main(int argc, char *argv[])
{   
    FILE *iofp;
    char *extendedFileName;
    /*List *opcodeList = createListOfOpcode();*/
    /*int i = 0;*/
    
    if(argc == 1){
        printf("No file entered!\n");
    }
    
    while(--argc > 0)
    {
        extendedFileName = fileExtensionChanger(*++argv, ".as");/*changes the extension of the file to .as*/
        if((iofp = fopen(extendedFileName, "r")) == NULL)
        {
            printf("Cannot open file %s, continue with next file.\n", *argv);
        }
        else
        {
            /*success!*/
            
        }
    }
    
    return 0;
}