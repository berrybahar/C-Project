#include "assembler.h"

FILE *macroSpreading(FILE *iofp)
{
    List* macro_list = create_list();
    FILE *fileAfterSpreadingMacros
    char line_in_file[MAX_LINE_LENGTH];
    int hasMacro = FALSE;
    
    while (!feof(iofp)) 
    {
       fread(line_in_file, MAX_LINE_LENGTH, 1, iofp);
        
    }
    
    return fileAfterSpreadingMacros;
}