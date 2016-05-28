#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "programmers.h"
#define MAX_ARRAY_SIZE 100

struct list_s {
programmer_t * arr[MAX_ARRAY_SIZE];
int size;
};

list_t * list_new()
{
    list_t * self = malloc(sizeof(struct list_s));
    self->size = 0;
    return self;
}

void list_add(list_t * self,programmer_t * programmer){
self->arr[self->size] = programmer;
self->size++;
}
void list_free(list_t * self)
{
    for (int i = 0; i < self->size; i++){
        programmer_free(self->arr[i]);
    }
}

programmer_t * list_getByID(list_t * self,int index)
{
    return self->arr[index];
}
int list_getSize(list_t * self)
{
    return self->size;
}
