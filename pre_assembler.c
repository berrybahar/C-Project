#include "assembler.h"
/*macro name can not be a register name also don't forget to check it*/

FILE *macroSpreading(FILE *iofp, char *fileName, int isMacroLegal, opcodes opcode[], instructions instruction[])
{
   FILE *fileAfterSpreadingMacros = fopen(fileExtensionChanger(fileName, ".am"), "w");
   int fileSize = getFileSize(iofp);
   char *line_in_file = (char *)(malloc(sizeof(char *) * fileSize));
   List* macro_list = create_list();
   char *macro = (char *)(malloc(sizeof(char *) * fileSize));/*macro's name*/
   char *macro_temp;/*temp for macro's name*/
   char *macro_info;/*the macro's content*/
   int hasMacro = FALSE;
    
   while (!feof(iofp))
   {
      fgets(line_in_file, fileSize, iofp);

      if((macro_temp = strstr(line_in_file, "mcro")) != NULL) /*if there is macro*/
      {
         hasMacro = TRUE;
         macro = getMacroName(macro_temp, macro);
         /*you need to check if there are characters after the macro name*/

         printf("The macro name %s.\n", macro);

         isMacroLegal = islegalMacro(opcode, instruction, line_in_file, macro, macro_temp);
         if(isMacroLegal == FALSE)
         {
            printf("The macro name %s is not legal! continuing to the next file!\n", macro);
         }

         macro_info = (char *)malloc(fileSize);
         while(hasMacro == TRUE)/*for adding the macro's definition*/
         {
            fgets(line_in_file, fileSize, iofp);/*get to the next line*/

            macro_info = (char *)malloc(fileSize);
            if(macro_info == NULL)
            {
               printf("memory allocation failed, continuing to the next file...\n");
               break;
            } 

            strncpy(macro_info,line_in_file, fileSize);/*copy the line to the macro's content*/
               
            if(strstr(line_in_file, "endmcro") != NULL)
            {
               hasMacro = FALSE;
               printf("macro info is: %s\n", macro_info);
            }
         }
         free(macro_info);/*free the macro info*/

         if(add_to_list(macro_list, macro, macro_info) == FALSE)/*if the macro name does exist in the macro list*/
         {
            printf("The macro name %s can not be added to the list! continuing to the next file!\n", macro);
         }
      }else
      {
         /*for checking if there is a macro name*/
         /*if()if there is a macro name in the file
         {

         }
         else
         {
            fprintf(fileAfterSpreadingMacros, "%s", line_in_file);
         }*/
         fprintf(fileAfterSpreadingMacros, "%s", line_in_file);
      }
   }
   free_list(macro_list);
    
   return fileAfterSpreadingMacros;
}

/**
 * checks and returns true if the macro name is legal
*/
int islegalMacro(opcodes opcode[], instructions instruction[], char *line_in_file, char *macro, char *macro_temp)
{
   int i;
   /*you need to get to after the macro name for macro temp tgo check if there are more characters after macro name*/

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
   
   while(*macro_temp != '\n' && *macro_temp != '\0')
   {
      if(*macro_temp != '\t' || *macro_temp != ' ' || *macro_temp != '\n')
         return FALSE; /*macro is illegal*/
      macro_temp++;
   }
   return TRUE;
}

/**
 * returns the size of the file
*/
int getFileSize(FILE *iofp)
{
   int size; 
   fseek(iofp, 0, SEEK_END); /* seek to end of file*/
   size = ftell(iofp); /* get current file pointer (this is the size of the file)*/
   fseek(iofp, 0, SEEK_SET); /* seek back to beginning of file*/
   return size;
}

/**
 * returns macro name
*/
char *getMacroName(char *macro_temp, char *macro)
{
   int i = 0;
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
   return macro;
}