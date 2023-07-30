#include "assembler.h"
/*macro name can not be a register name also don't forget to check it*/
/*after that you can check if there is a call to any macro before it's declaration*/

FILE *macroSpreading(FILE *iofp, char *fileName, int isMacroLegal, opcodes opcode[], instructions instruction[])
{
   FILE *fileAfterSpreadingMacros = fopen(fileExtensionChanger(fileName, ".am"), "w");
   char line_in_file[MAX_LINE_LENGTH];
   List* macro_list = create_list();
   char macro[MAX_LINE_LENGTH];/*macro's name*/
   char *macro_temp;/*temp for macro's name*/
   char *macro_info;/*the macro's content*/
   int hasMacro = FALSE;
   int i = 0;
    
   while (!feof(iofp))
   {
      fgets(line_in_file, MAX_LINE_LENGTH, iofp);/*this works perfect*/
      printf("%s", line_in_file);
      break;

      if((macro_temp = strstr(line_in_file, "mcro")) != NULL) /*if there is macro*/
      {
         hasMacro = TRUE;
         macro_temp = strchr(macro_temp, ' ');/*going to the end of the word macro*/
         while(*++macro_temp == ' ');/*for getting the macro name*/
         /*Copy characters until space or end of string is reached*/
         while (*macro_temp && *macro_temp != ' ') 
         {
            macro[i] = *macro_temp;
            macro_temp++;
            i++;
         }
         macro[strcspn(macro, "\r\n")] = '\0'; /* Remove trailing newline or carriage return */
         /*you need to check if there are characters after the macro name*/
         /*if(*++macro_temp != )*/
         i = 0;
         printf("The macro name %s.\n", macro);

         isMacroLegal = legalMacro(opcode, instruction, macro);
         if(isMacroLegal == FALSE)
         {
            printf("The macro name %s is not legal! continuing to the next file!\n", macro);
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
               
            if(strstr(line_in_file, "endmcro") != NULL)
            {
               hasMacro = FALSE;
               printf("macro info is: %s", macro_info);
            }
         }

         if(add_to_list(macro_list, macro, macro_info) == FALSE)/*if the macro name does exist in the macro list*/
         {
            printf("The macro name %s can not be added to the list! continuing to the next file!", macro);
            break;
         }
         free(macro_info);
      }else
      {
         /*for checking if there is a macro name
         if()if there is a macro name in the file
         {

         }
         else
         {
            fprintf(fileAfterSpreadingMacros, "%s", line_in_file);
         }*/
      }
   }
   free_list(macro_list);
    
   return fileAfterSpreadingMacros;
}

int legalMacro(opcodes opcode[], instructions instruction[], char *macro)
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