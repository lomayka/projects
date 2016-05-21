#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "programmer.h"
#include "List.h"
#define LIST_SIZE 100

struct list_s {
programmer_t * arr[LIST_SIZE];
int size;
};

list_t * list_new(){
list_t * self = malloc (sizeof(struct list_s));
self->size = 0;
return self;
}

void list_free(list_t * self){
for (int i = 0; i < LIST_SIZE; i++){
    programmer_free(self->arr[i]);
}
free(self);
}

void list_add(list_t * self,programmer_t * programmer)
{
self->arr[self->size] = programmer;
self->size++;
}

programmer_t * list_delete(list_t * self, int index)
{
programmer_t * save = self->arr[index];
for (int i = index; i < self->size; i++){
    self->arr[i] = self->arr[i+1];
}
self->size--;
return save;
}

int list_getSize(list_t * self){
return self->size;
}

programmer_t * list_getById(list_t * self, int id){
return self->arr[id];
}
