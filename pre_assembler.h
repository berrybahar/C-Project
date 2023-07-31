#include "instructions.h"
#include "opcodes.h"
FILE *macroSpreading(FILE *iofp, char *fileName, int isMacroLegal, opcodes opcode[], instructions instruction[]);
int islegalMacro(opcodes opcode[], instructions instruction[], char *macro);
int getLineInFile(FILE *iofp, char *line_in_file);