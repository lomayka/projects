#ifndef PROGRAM_H_INCLUDED
#define PROGRAM_H_INCLUDED
#include <stdlib.h>


typedef struct program prog_t;

int prog_getMessages(prog_t * prog, char * message[]);
char * prog_getName(prog_t * prog);
int prog_getMessagesCount(prog_t *);
#endif
