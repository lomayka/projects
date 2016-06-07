#include <stdlib.h>
#include <stdio.h>
#include "programmers.h"

typedef struct list_s list_t;

list_t * list_new();
void list_free(list_t * self);

