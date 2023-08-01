#include "assembler.h"
/*macro name can not be a register name also don't forget to check it*/

FILE *macroSpreading(FILE *iofp, char *fileName, int isMacroLegal, opcodes opcode[], instructions instruction[], char registers[8][3])
{
   FILE *fileAfterSpreadingMacros = fopen(fileExtensionChanger(fileName, ".am"), "w");
   Node *temp = (Node*)malloc(sizeof(Node));/*node temp*/
   long fileSize = getFileSize(iofp);
   char *line_in_file = (char *)(malloc(sizeof(char *) * fileSize));
   List* macro_list = create_list();
   char *macro = (char *)(malloc(sizeof(char *) * fileSize));/*macro's name*/
   char *macro_info = (char *)(malloc(sizeof(char *) * fileSize));/*the macro's content*/
   char *macro_temp = (char *)(malloc(sizeof(char *) * fileSize));/*temp for everything. He's the best!*/
   int hasMacro = FALSE;
   
   if(macro_temp == NULL || line_in_file == NULL || macro == NULL || macro_info == NULL || temp == NULL)
   {
      printf("memory allocation failed, continuing to the next file...\n");
      return fileAfterSpreadingMacros;
   } 
    
   while (!feof(iofp))
   {
      fgets(line_in_file, fileSize, iofp);

      if((macro_temp = strstr(line_in_file, "mcro")) != NULL) /*if the  re is macro*/
      {
         hasMacro = TRUE;
         macro = getMacroName(macro_temp, macro);

         isMacroLegal = islegalMacro(opcode, instruction, registers, line_in_file, macro, macro_temp);
         if(isMacroLegal == FALSE)
         {
            printf("The macro name %s is not legal! continuing to the next file!\n", macro);
         }

         while(hasMacro == TRUE)/*for adding the macro's definition*/
         {
            fgets(macro_temp, fileSize, iofp);/*get to the next line*/
   
            if(strstr(macro_temp, "endmcro") != NULL)
               hasMacro = FALSE;  
            
            if(hasMacro == TRUE)
               strcat(macro_info, macro_temp);/*copy the line to the macro's content*/
         }

         if(add_to_list(macro_list, macro, macro_info) == FALSE)/*if the macro name does exist in the macro list*/
         {
            printf("The macro name %s can not be added to the list! continuing to the next file!\n", macro);
         }
         printf("macro info: %s\n", macro_info);
         macro_info = strcpy(macro_info, " ");
      }
      else
      {
         /*for checking if there is a macro name*/
         if(is_node_in_list(macro_list, line_in_file, IS_THERE_MACRO) == TRUE)/*if there is a macro name in the file*/
         {
            temp = getPointerForMacro(macro_list, line_in_file);
            fprintf(fileAfterSpreadingMacros, "%s", (char *)(temp->data));
         }
         else
         {
            fprintf(fileAfterSpreadingMacros, "%s", line_in_file);
         }
      }
   }
   free_list(macro_list);
   free(line_in_file);
   free(macro);
   free(macro_temp);
   free(macro_info);
    
   return fileAfterSpreadingMacros;
}

/**
 * checks and returns true if the macro name is legal
*/
int islegalMacro(opcodes opcode[], instructions instruction[], char registers[8][3], char *line_in_file, char *macro, char *macro_temp)
{
   int i;
   /*you need to get to after the macro name for macro temp to check if there are more characters after macro name*/

   for(i = 0; i < 16; i++)
   {
      if(i < 4)/*for instructions*/
      {
         if(strstr(macro, instruction[i].instruction) != NULL)
         {
            printf("Illegal Macro Name!");
            return FALSE;/*macro is illegal*/
         }
      }
      
      if(strstr(macro, opcode[i].opcode) != NULL)/*for opcodes*/
      {
         printf("Illegal Macro Name!");
         return FALSE;/*macro is illegal*/
      }

      if(i < 8)/*for registers*/
      {
         if(strstr(macro, registers[i]) != NULL)
         {
            printf("Illegal Macro Name!");
            return FALSE;/*macro is illegal*/
         }
      }
   }
   
   /*for checking if there are characters after macro declaration*/
   

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

Node *getPointerForMacro(List *macro_list, char *macro)
{
   Node *temp;
   if (macro_list->size == 0) 
   {
      return NULL;
   }
   temp = macro_list->head;
   while(temp != NULL)
   {
      if(strstr(macro, temp->name) != NULL)
         return temp;
   }

   return NULL;
}