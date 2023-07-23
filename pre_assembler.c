#include "assembler.h"

FILE *macroSpreading(FILE *iofp)
{
    List* macro_list = create_list();
    FILE *fileAfterSpreadingMacros = fopen(fileExtensionChanger(), ".am");
    char *line_in_file;
    int hasMacro = FALSE;
    
    while (!feof(iofp)) 
    {
       fread(line_in_file, MAX_LINE_LENGTH, 1, iofp);
       printf("%s\n", line_in_file);
    }
    
    return fileAfterSpreadingMacros;
}