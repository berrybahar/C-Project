#include "assembler.h"

FILE *macroSpreading(FILE *iofp, char *fileName, List* macro_list, opcodes opcode[], instructions instruction[])
{
    FILE *fileAfterSpreadingMacros = fopen(fileExtensionChanger(fileName, ".am"), "w");
    char line_in_file[MAX_LINE_LENGTH];
    char *macro;
    char *macro_info;
    int hasMacro = FALSE;
    int isThereProblematicMacro = FALSE; /*macro name can't be name of opcode or name of instruction*/
    
    while (!feof(iofp)) 
    {
       fgets(line_in_file, MAX_LINE_LENGTH, iofp);/*this works perfect*/
       
       if((macro = strstr(line_in_file, "mcro")) != NULL) /*if there is macro*/
       {
         hasMacro = TRUE;
         while(*macro != ' ')
            *++macro;

         while(hasMacro == TRUE)/*for adding the macro's definition*/
         {
            
         }

         add_to_list(macro_list, macro, macro_info);/*adds the macro to the list of macros*/
       }else
       {
            fprintf(fileAfterSpreadingMacros, "%s", line_in_file);
       }
    }
    
    return fileAfterSpreadingMacros;
}

