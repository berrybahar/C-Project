#include "assembler.h"

FILE *macroSpreading(FILE *iofp, char *fileName, List* macro_list, int isThereProblematicMacro, opcodes opcode[], instructions instruction[])
{
   FILE *fileAfterSpreadingMacros = fopen(fileExtensionChanger(fileName, ".am"), "w");
   char line_in_file[MAX_LINE_LENGTH];
   char *macro;/*macro's name*/
   char *macro_info;/*the macro's content*/
   int hasMacro = FALSE;
    
   while (!feof(iofp)) 
      {
         fgets(line_in_file, MAX_LINE_LENGTH, iofp);/*this works perfect*/
       
         if((macro = strstr(line_in_file, "mcro")) != NULL) /*if there is macro*/
         {
            hasMacro = TRUE;
            /*you need to find the name of the macro!!!!*/
            /*this is the function for finding the macro name (I need to write it)*/

            isThereProblematicMacro = isMacroLegal(opcode, instruction,macro);
            if(isThereProblematicMacro == TRUE)
            {
               printf("The macro name %s is not legal! continuing to the next file!\n", macro);
               break;
            }

            while(hasMacro == TRUE)/*for adding the macro's definition*/
            {
               fgets(line_in_file, MAX_LINE_LENGTH, iofp);/*get to the next line*/

               macro_info = (char *)malloc(MAX_LINE_LENGTH);
               if(macro_info == NULL)
               {
                  printf("memory allocation failed, continuing to the next file...");
                  break;
               } 

               strncpy(macro_info,line_in_file, MAX_LINE_LENGTH);/*copy the line to the macro's content*/
               
               if(strstr(line_in_file, "endmcro") != NULL){
                  hasMacro = FALSE;
                  printf("%s", macro_info);
               }
            }

            if(add_to_list(macro_list, macro, macro_info) == FALSE)/*if the macro name does exist in the macro list*/
            {
               printf("The macro name %s can not be added to the list! continuing to the next file!", macro);
               break;
            }
       }else
         {
            fprintf(fileAfterSpreadingMacros, "%s", line_in_file);
         }
      }
    
   return fileAfterSpreadingMacros;
}

int isMacroLegal(opcodes opcode[], instructions instruction[], char *macro)
{
   int i;

   for(i = 0; i < 16; i++)
   {
      if(i < 4)
      {
         if(strstr(macro, instruction[i].instruction) != NULL)
         {
            printf("Illegal Macro Name!");
            return FALSE;/*macro is illegal*/
         }
      }
      
      if(strstr(macro, opcode[i].opcode) != NULL)
         {
            printf("Illegal Macro Name!");
            return FALSE;/*macro is illegal*/
         }
   }
   return TRUE;
}