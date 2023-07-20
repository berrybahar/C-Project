#include "assembler.h"

int main(int argc, char *argv[])
{   
    FILE *iofp;
    char *orhan = "anan";
    char *newFileName;
    
    if(argc == 1){
        printf("No file entered!");
    }
    
    while(--argc > 0)
    {
        /**/
        if((iofp = fopen(*argv, "r")) == NULL)
        {
            printf("Cannot open file %s, continue with next file.\n", *argv);
        }
        else
        {
            
        }
    }

    *newFileName = fileExtensionChanger(orhan, ".as");

    printf("Hello\n");
    printf("%s\n", newFileName);
    
    return 0;
}