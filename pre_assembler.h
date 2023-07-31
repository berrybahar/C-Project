#include "instructions.h"
#include "opcodes.h"
FILE *macroSpreading(FILE *iofp, char *fileName, int isMacroLegal, opcodes opcode[], instructions instruction[]);
int islegalMacro(opcodes opcode[], instructions instruction[], char *line_in_file, char *macro, char *macro_temp);
int getFileSize(FILE *iofp);
char *getMacroName(char *macro_temp, char *macro);