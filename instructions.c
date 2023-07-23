#include "assembler.h"

void data(FILE *iofp)
{

}

void string(FILE *iofp)
{

}

void entry(FILE *iofp)
{

}

void ext(FILE *iofp)
{

}

/***********************************************************************************************/
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