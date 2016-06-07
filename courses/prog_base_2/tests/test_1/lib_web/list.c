#include <stdlib.h>
#include "list.h"

struct list_s {
    event_t ** arr;
    int count;
};

list_t *
list_new() {
    list_t * self = malloc(sizeof(struct list_s));
    self->count = 0;
    self->arr = malloc(0);
    return self;
}

void
list_free(list_t * self) {
    free(self->arr);
    free(self);
}

void
list_push_back(list_t * self, event_t * ptr) {
    self->count++;
    self->arr = realloc(self->arr, sizeof(void *) * self->count);
    self->arr[self->count - 1] = ptr;
}

event_t *
list_pop_back(list_t * self) {
    self->count--;
    event_t * ret = self->arr[self->count];
    self->arr = realloc(self->arr, sizeof(void *) * self->count);
    return ret;
}

event_t *
list_pop_back_byId(list_t * self,int id) {

    event_t * ret = self->arr[id];
    for (int i = 0; i < self->count-1; i++){
        self->arr[i] = self->arr[i+1];
    }

    self->count--;
    self->arr = realloc(self->arr, sizeof(void *) * self->count);

    return ret;
}

int
list_getCount(list_t * self) {
    return self->count;
}

event_t *
list_getEl(list_t * self, int index) {
    return self->arr[index];
}

