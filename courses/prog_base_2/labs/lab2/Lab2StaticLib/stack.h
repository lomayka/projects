#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct stack_s stack_t;

stack_t * stack_new(void);
void stack_free(stack_t * self);

int stack_getCount(stack_t * self);

void stack_push(stack_t * self, int val);
int stack_pop(stack_t * self);
int stack_peek(stack_t * self);

void stack_print(stack_t * self);
void stack_copy(stack_t * a, stack_t * b);



#endif // STACK_H_INCLUDED
