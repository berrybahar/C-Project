void data(FILE *iofp);
void string(FILE *iofp);
void entry(FILE *iofp);
void ext(FILE *iofp);

typedef struct instructions
{
    char *instruction;
    void (*func)(FILE *iofp);
} instructions;