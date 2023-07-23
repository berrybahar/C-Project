/*with help from the page 224-225 at the Study Guide(aka: Madrich Lemida)*/
void mov(FILE *iofp);
void cmp(FILE *iofp);
void add(FILE *iofp);
void sub(FILE *iofp);
void not(FILE *iofp);
void clr(FILE *iofp);
void lea(FILE *iofp);
void inc(FILE *iofp);
void dec(FILE *iofp);
void jmp(FILE *iofp);
void bne(FILE *iofp);
void red(FILE *iofp);
void prn(FILE *iofp);
void jsr(FILE *iofp);
void rts(FILE *iofp);
void stop(FILE *iofp);

/*struct
{
    char *opcode;
    void (*func)(FILE *iofp);
} opcodes [] = 
{
    {"mov", mov},
    {"cmp", cmp},
    {"add", add},
    {"sub", sub},
    {"not", not},
    {"clr", clr},
    {"lea", lea},
    {"inc", inc},
    {"dec", dec},
    {"jmp", jmp},
    {"bne", bne},
    {"red", red},
    {"prn", prn},
    {"jsr", jsr},
    {"rts", rts},
    {"stop", stop},
    {"not_valid", NULL}
};*/