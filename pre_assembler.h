#include "main.h"
typedef struct Mcr {
    char *name;
    char *code;
} Mcr;

typedef struct NodeMcr {
    struct Mcr data;
    struct NodeMcr *next;
} NodeMcr;

typedef struct ListMcr {
    int count;
    NodeMcr *head;
} ListMcr;

error preAssembler(char* fileName);
char *concatenateStrings(char* str1, char* str2);
void addToList(NodeMcr * newElement, ListMcr* list);
struct NodeMcr * createNode(char * name, char* code);
error is_mcr_def( char **lineOut);
error is_mcrEnd(char *line);
error is_name_of_mcr(char* line,ListMcr * mcrList);