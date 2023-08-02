#include "assembler.h"

int main(int argc, char *argv[])
{   
    int i;
    for (i = 1; i < argc; i++) 
    {
        preAssembler(argv[i]); /*for test*/
        /*if (preAssembler(argv[i]) == success)*/
            /*firstRun(argv[i]);*/
    }
    return 0;
}