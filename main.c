#include "main.h"

int main(int argc, char *argv[])
{   
    int i;
    for (i = 1; i < argc; i++) 
    {
        if (preAssembler(argv[i]) == success)
            firstRun(argv[i]);
    }
    return 0;
}