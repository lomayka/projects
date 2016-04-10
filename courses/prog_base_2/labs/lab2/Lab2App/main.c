#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "stack.h"

typedef int (*cmp_f)(stack_t * a);
typedef void (*react_f)(stack_t * a);

typedef struct dynamic_s {
    HANDLE hLib;
    cmp_f cmp;
    react_f react;
} dynamic_t;

dynamic_t * dynamic_init(const char * dllName);
void dynamic_clean(dynamic_t * dyn);

const char * userChoice();
void printStacks(stack_t * a);

int main(void) {
    const int MAX_STACK_SIZE = 10;
    stack_t * stack = stack_new();
    const char * dllName = userChoice();
    dynamic_t * dll = dynamic_init(dllName);
    if (NULL == dll) {
        printf("Can't load dynamic!\n");
        return 1;
    }
    if (NULL == dll->cmp) {
        printf("Can't get compare function!\n");
        return 1;
    }
    if (NULL == dll->react) {
        printf("Can't get reaction function!\n");
        return 1;
    }
    printf("Dynamic loaded!");
    srand(time(NULL));
    for (int i = 0; i < MAX_STACK_SIZE;i++){
        stack_push(stack,rand()%150 - 50);
        if (dll->cmp(stack)){
            dll->react(stack);
            }
        printStack(stack);
        printf("\n");
    }

    stack_free(stack);
    dynamic_clean(dll);
    return 0;
}

const char * userChoice() {
    int dllNum = 0;
    while (dllNum < 1 || dllNum > 2) {
        printf("Choose DLL to load:\n1. Lab2DLL1\n2. Lab2DLL2\n> ");
        scanf("%i", &dllNum);
        if (dllNum == 1) {
            return "Lab2DLL1.dll";
        } else if (dllNum == 2) {
            return "Lab2DLL2.dll";
        }
    }
    return NULL;
}

void printStack(stack_t * a) {
    system("cls");
    printf("Stack: ");
    stack_print(a);
    Sleep(500);
}

dynamic_t * dynamic_init(const char * dllName) {
    dynamic_t * dyn = malloc(sizeof(struct dynamic_s));
    dyn->hLib = LoadLibrary(dllName);
    dyn->cmp = NULL;
    dyn->react = NULL;
    if (NULL != dyn->hLib) {
        dyn->cmp = (cmp_f)GetProcAddress(dyn->hLib, "compare");
        dyn->react = (react_f)GetProcAddress(dyn->hLib, "reaction");
        return dyn;
    } else {
        return NULL;
    }
}

void dynamic_clean(dynamic_t * dyn) {
    FreeLibrary(dyn->hLib);
    free(dyn);
}

/*int main(){
stack_t * stack1 =  stack_new();
for (int i = 0; i < 10; i++){
    stack_push(stack1,i);
}
int peek = stack_peek(stack1);
//int pop = stack_pop(stack1);
printf("%d ", peek);
//printf("%d\n", pop);
stack_print(stack1);


return 0;
}*/
