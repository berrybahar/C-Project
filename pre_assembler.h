#include "instructions.h"
#include "opcodes.h"
FILE *macroSpreading(FILE *iofp, char *fileName, List* macro_list, int isThereProblematicMacro, opcodes opcode[], instructions instruction[]);
int isMacroLegal(opcodes opcode[], instructions instruction[], char *macro);