#include "instructions.h"
#include "opcodes.h"
FILE *macroSpreading(FILE *iofp, char *fileName, int isMacroLegal, opcodes opcode[], instructions instruction[]);
int legalMacro(opcodes opcode[], instructions instruction[], char *macro);