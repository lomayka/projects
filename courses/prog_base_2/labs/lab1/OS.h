#ifndef OS_H_INCLUDED
#define OS_H_INCLUDED
#include <stdlib.h>

#include "program.h"

typedef struct OS os_t;

typedef enum {
SUCCESSFUL,
FULL,
EMPTY,
WRONG_INDEX,
WRONG_NAME,
ERROR,
DIFFERENT_OS
} status_t;



os_t * os_new(char *);
status_t os_free(os_t * self) ;

int os_getPrograms(os_t *, prog_t **);
prog_t * os_getProgramByName(os_t * self, char * name);
prog_t * prog_new(os_t * self, char * name);
status_t prog_free(os_t * self, prog_t * );
status_t os_sendMessage(os_t *,prog_t *, prog_t *, char *);
#endif
