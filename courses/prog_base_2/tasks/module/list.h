#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdlib.h>

typedef struct list_s list_t;

typedef enum {
SUCCESSFUL,
FULL,
EMPTY,
WRONG_INDEX
} list_status;


list_t * list_new();

list_status list_add(list_t *,int,int);
list_status list_delete(list_t *,int);
int list_size(list_t *);
int list_max(list_t *);
int list_min(list_t *);

list_status list_free(list_t *);

void print_list(list_t *);


#endif
