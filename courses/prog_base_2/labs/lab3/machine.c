#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "machine.h"
#include "list.h"


struct machine_s
{
    char name[100];
    int arr[3];
    list_t * event_notification;
    char state[10];
    enum event ev;
};





machine_t *
machine_new(char * name)
{
    machine_t * self = malloc(sizeof(struct machine_s));
    self->event_notification = list_new();
    strcpy(self->name,name);
    return self;
}

void machine_free(machine_t * self){
int count = list_getCount(self->event_notification);
    for (int i = 0; i < count; i++) {
        event_t * ev = list_pop_back(self->event_notification);
        free(ev);
    }
    list_free(self->event_notification);
    free(self);
}

void machine_subscribeNotification(machine_t * self, void * receiver,machine_notification_fn callback, enum event ev){
    event_t * sb = malloc(sizeof(struct event_s));
    sb->receiver = receiver;
    sb->callback = callback;
    sb->state = ev;
    list_push_back(self->event_notification, sb);
}


void machine_generate(machine_t * self){
srand(time(NULL));
for (int i = 0; i < 3; i++){
    self->arr[i] = rand() % 10;
}
if (self->arr[0] < self->arr[1] && self->arr[1] < self->arr[2]){
        machine_sendResult(self,Up) ;
        self->ev = Up;
        strcpy(self->state, "UP");
}
else if (self->arr[0] > self->arr[1] &&  self->arr[1] > self->arr[2]){
        machine_sendResult(self,Down);
        self->ev = Down;
        strcpy(self->state, "DOWN");
}
else if (self->arr[0] == self->arr[1] && self->arr[1] == self->arr[2])
{
    machine_sendResult(self,Normal);
    self->ev = Normal;
    strcpy(self->state, "NORMAL");
}
}
void
machine_sendResult(machine_t * self, enum event state) {
    int count = list_getCount(self->event_notification);
    for (int i = 0; i < count; i++) {
        event_t * ev = list_getEl(self->event_notification, i);
        if (NULL != ev->callback && ev->state == state) {
            machine_notification_fn fn = ev->callback;
            fn(ev->receiver, self);
        }
    }
}


char * machine_getState(machine_t * self){
return self->state;
}

int  machine_getArray(machine_t * self, int i){
return self->arr[i];
}

char * machine_getName(machine_t * self){
return self->name;

}

