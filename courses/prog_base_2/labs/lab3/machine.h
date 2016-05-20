#ifndef MACHINE_H_INCLUDED
#define MACHINE_H_INCLUDED
#include "list.h"
typedef struct machine_s machine_t;

typedef
    void
    (*machine_notification_fn)
    (void * receiver, machine_t * sender);

machine_t *
machine_new(char * name);



void
machine_subscribeNotification(machine_t * self, void * reciever,machine_notification_fn callback,enum event ev);

void
machine_generate(machine_t * self);

void
machine_sendResult(machine_t * self,enum event state);

char *
machine_getState(machine_t * self);

int
machine_getArray(machine_t * self, int i);

char *
machine_getName(machine_t * self);

void
machine_free(machine_t * self);

#endif // MACHINE_H_INCLUDED
