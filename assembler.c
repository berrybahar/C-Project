#include "assembler.h"

int main(int argc, char *argv[])
{   
    int flag, i;
    int IC, DC;
    
    /***********************************************************************************************************************/
    opcodes opcode[] = 
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

    instructions instruction[] = 
    {
        {".data", data},
        {".string", string},
        {".entry", entry},
        {".extern", ext}, /*extern is a key word of c++ be aware of this*/
        {"not_valid", NULL}
    };

    char registers[8][3]  = {"@r0", "@r1", "@r2", "@r3", "@r4", "@r5", "@r6", "@r7"};
/*******************************************************************************************************************************/    
    for (i = 1; i < argc; i++)
    {
        struct  Macro* Mtail= NULL;
        struct  Macro* Mhead = NULL;

        Mhead = (struct Macro*)malloc(sizeof(struct Macro));
        Mtail = (struct Macro*)malloc(sizeof(struct Macro));
        Mtail = Mhead;
    
        flag = PreReadFile(i,argv,Mhead);
        if(!flag)
        {
            PreWriteFile(i,argv,Mtail);
        }
    }
    return 1;
}