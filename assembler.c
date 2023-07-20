#include "assembler.h"

int main(int argc, char *argv[])
{   /*
    FILE *iofp;
    
    if(argc == 1){
        printf("No file entered!");
    }
    
    while(--argc > 0)
    {
        fileTypeChanger(*++argv, ".as");
        if((iofp = fopen(*argv, "r")) == NULL){/*change the extension of the file to .as if it does alredy have an extension than it*/
        /*    printf("Cannot open file %s, continue with next file.\n", *argv);
        }else{
            
        }
    }*/

    fileTypeChanger("anan", ".as");
    
    return 0;
}