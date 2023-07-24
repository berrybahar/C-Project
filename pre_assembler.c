#include "assembler.h"

FILE *macroSpreading(FILE *iofp, char *fileName)
{
    List* macro_list = create_list();
    FILE *fileAfterSpreadingMacros = fopen(fileExtensionChanger(fileName, ".am"), "w");
    char line_in_file[MAX_LINE_LENGTH];
    int hasMacro = FALSE;
    
    while (!feof(iofp)) 
    {
       fread(line_in_file, MAX_LINE_LENGTH, 1, iofp);
       printf("%s\n", line_in_file);
       break;
    }
    
    return fileAfterSpreadingMacros;
}