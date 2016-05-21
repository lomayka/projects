#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "programmer.h"


typedef struct list_s list_t;

list_t * list_new();
void list_free(list_t * self);
void list_add(list_t * self,programmer_t * programmer);
programmer_t * list_delete(list_t * self, int index);
int list_getSize(list_t * self);
programmer_t * list_getById(list_t * self, int id);

