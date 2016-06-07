#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct list_s list_t;

typedef struct event_s {
    void * receiver;
    void * callback;
} event_t;

list_t *
list_new();

void
list_free(list_t * self);

void
list_push_back(list_t * self, event_t * ptr);

event_t *
list_pop_back(list_t * self);

int
list_getCount(list_t * self);

event_t *
list_getEl(list_t * self, int index);
event_t *
list_pop_back_byId(list_t * self,int id);

#endif // LIST_H_INCLUDED

