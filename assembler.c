#include "assembler.h"

int main(int argc, char *argv[])
{   
    FILE *iofp;
    char *extendedFileName;
    List *opcodeList = createListOfOpcode();
    
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
            printf("success!\n");
            /*Don't forget fclose!*/
        }
    }
    
    return 0;
}

/**
 * 
*/
List *createListOfOpcode()
{   
    int i;
    char *opcode[] = {"mov", "cmp", "add", "sub", "not", "clr", "lea", "inc", "dec", "jmp", "bne", "red", "prn", "jsr", "rts", "stop"};
    List *opcodeList = create_list();
    
    for(i = 0; i < 16; i++)
    {
        add_to_list(opcodeList, opcode[i], decimalToFourBitBinary(opcode[i]));
    }
    
    return opcodeList;
}

/**
 * 
*/
short *decimalToFourBitBinary(short num)
{
    int i = 0;
    short binaryNum[4];
    while(num > 0)
    {
        binaryNum[i] = num % 2;
        num = num / 2; 
        i++;
    }
    return binaryNum;
}