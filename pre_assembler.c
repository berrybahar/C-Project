#include "assembler.h"

FILE *macroSpreading(FILE *iofp, char *fileName, List* macro_list, int isThereProblematicMacro)
{
    FILE *fileAfterSpreadingMacros = fopen(fileExtensionChanger(fileName, ".am"), "w");
    char line_in_file[MAX_LINE_LENGTH];
    char *macro;
    char *macro_info;
    int hasMacro = FALSE;
    
    while (!feof(iofp)) 
    {
       fgets(line_in_file, MAX_LINE_LENGTH, iofp);/*this works perfect*/
       
       if((macro = strstr(line_in_file, "mcro")) != NULL) /*if there is macro*/
       {
         hasMacro = TRUE;
         while(*macro != ' ')
            *++macro;
         
         while(hasMacro == TRUE){
            
         }

         add_to_list(macro_list, macro, macro_info);/*adds the macro to the list of macros*/
       }else
       {
            fprintf(fileAfterSpreadingMacros, "%s", line_in_file);
       }
    }
    
    return fileAfterSpreadingMacros;
}