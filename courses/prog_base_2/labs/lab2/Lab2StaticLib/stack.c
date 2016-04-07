#include "stack.h"

struct stack_s{
int * arr;
int size;
};

stack_t * stack_new(){
stack_t * newStack = malloc(sizeof(struct stack_s));
newStack->arr = malloc(sizeof(int) * 10);
newStack->size = 0;
return newStack;
}

int stack_getCount(stack_t * self){
return self->size;
}

void stack_push(stack_t * self, int val){
self->arr[self->size] = val;
self->size++;
}

int stack_pop(stack_t * self){
if (self->size > 0){
int val =  self->arr[self->size-1];
self->size--;
return val;
 }
}

int stack_peek(stack_t * self){
if (self->size > 0){
return self->arr[self->size-1];
}
}

void stack_print(stack_t * self){
for (int i = 0; i < self->size; i++){
    printf("%d ",self->arr[i]);
}
printf("\n");

}

void stack_copy(stack_t * a, stack_t * b){
for (int i = 0; i < a->size; i++){
    b->arr[i] = a->arr[i];
}
b->size = a->size;
}


void stack_free(stack_t * self){
free(self->arr);
free(self);
}
