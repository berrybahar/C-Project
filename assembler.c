#include "assembler.h"

struct
{
    char *opcode;
    void (*func)(FILE *iofp);
} opcodes [] = 
{
    {"mov", mov},
    {"cmp", cmp},
    {"add", add},
    {"sub", sub},
    {"not", not},
    {"clr", clr},
    {"lea", lea},
    {"inc", inc},
    {"dec", dec},
    {"jmp", jmp},
    {"bne", bne},
    {"red", red},
    {"prn", prn},
    {"jsr", jsr},
    {"rts", rts},
    {"stop", stop},
    {"not_valid", NULL}
};

struct
{
    char *instruction;
    void (*func)(FILE *iofp);
} instructions[] = 
{
    {".data", data},
    {".string", string},
    {".entry", entry},
    {".extern", ext}, /*extern is a key word of c++ be aware of this*/
    {"not_valid", NULL}
};

int main(int argc, char *argv[])
{   
    FILE *iofp;
    char *extendedFileName;
    FILE *fileAfterSpreadingMacros;
    
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
            /*success!*/
            fileAfterSpreadingMacros = macroSpreading(iofp, *argv);
        }
    }
    
    return 0;
}