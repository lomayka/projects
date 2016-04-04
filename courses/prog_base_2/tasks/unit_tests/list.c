#include "list.h"
#include <stdlib.h>
#define MAX_LIST_SIZE 100


struct list_s {
int * arr;
int size;

};


list_t * list_new (){

list_t * ls = malloc(sizeof(list_t));
ls->arr = malloc(MAX_LIST_SIZE*sizeof(int));
ls->size = 0;
return ls;
}

list_status list_add(list_t * self,int val, int index) {
 if (index > self->size) {
    return WRONG_INDEX;
 }
 else {
    if (index < self->size){
    for (int i = self->size - 1; i >= index; i--){
        self->arr[i+1] = self->arr[i];

    }
    }
 self->arr[index] = val;
 self->size++;
 return SUCCESSFUL;

 }
}


list_status list_delete(list_t * self, int index)
{
    if (index > self->size) {
        return WRONG_INDEX;
    }
    else {
        if (index < self->size){
            for (int i = index; i < self->size ; i++ ){
                self->arr[i] = self->arr[i+1];
            }
        }
        self->size--;
        return SUCCESSFUL;
    }

}


int list_size(list_t * self){
return self->size;
}


int list_max(list_t * self){
    int max = self->arr[0];
for (int i = 1; i < self->size; i++){
       if (self->arr[i] > max){
        max = self->arr[i];
       }

}
return max;
}

int list_min(list_t * self){
    int min = self->arr[0];
for (int i = 1; i < self->size; i++){
       if (self->arr[i] < min){
        min = self->arr[i];
       }

}
return min;
}

void print_list(list_t * self){
for (int i = 0; i < self->size; i++){
    printf("%d ", self->arr[i]);
}
}

int list_check(list_t * self, int index){      // special for unit_tests
return self->arr[index];
}

list_status list_free(list_t * self){
free(self->arr);
free(self);
return SUCCESSFUL;
}

