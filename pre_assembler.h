#include "instructions.h"
#include "opcodes.h"
FILE *macroSpreading(FILE *iofp, char *fileName, int isMacroLegal, opcodes opcode[], instructions instruction[], char registers[8][3]);
int islegalMacro(opcodes opcode[], instructions instruction[], char registers[8][3], char *line_in_file, char *macro, char *macro_temp);
int getFileSize(FILE *iofp);
char *getMacroName(char *macro_temp, char *macro);
Node *getPointerForMacro(List *macro_list, char *macro);