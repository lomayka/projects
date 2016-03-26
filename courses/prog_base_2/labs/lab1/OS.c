#include "OS.h"
#include <stdlib.h>
#include <string.h>
#include "program.h"

#define MAX_SIZE 10
#define MAX_LENGTH 20

struct OS {
int count;
char * name;
prog_t ** pointers;
};

struct program {
char * name;
prog_t ** progs;
char ** message;
int mCount;
};

os_t * os_new(char * os_name){
    if (os_name == NULL){
        return NULL;
    }
os_t * self = malloc(sizeof(os_t));
self->pointers = malloc(sizeof(prog_t *) * MAX_SIZE * MAX_LENGTH);
self->name = malloc(sizeof(char) * 20);
strcpy(self->name,os_name);
self->count = 0;
return self;
}

status_t os_free(os_t * self){
if(self == NULL){
    return ERROR;
}
free(self->pointers);
free(self->name);
free(self);
return SUCCESSFUL;
}

prog_t * prog_new(os_t * self, char * name){
if (name == NULL){
        return NULL;
    }
prog_t * newProg = malloc(sizeof(prog_t));
newProg->name = malloc(sizeof(char) * 20);
strcpy(newProg->name,name);
newProg->progs = malloc(20*sizeof(prog_t *));
newProg->message = malloc(120*100*sizeof(char));
strcpy(newProg->message,"\0");
self->pointers[self->count] = newProg;
newProg->mCount = 0;
self->count++;
return newProg;
}

status_t prog_free(os_t * self, prog_t * prog){
if(self == NULL || prog == NULL){
    return ERROR;
}
        free(prog->progs);
        free(prog->name);
        free(prog->message);
        free(prog);
return SUCCESSFUL;
}

int os_getPrograms(os_t * self, prog_t ** progs ){
if (self != NULL && progs != NULL){
for(int i = 0; i < self->count; i++){
    progs[i] = self->pointers[i];
}
return self->count;
}
return ERROR;
}


prog_t * os_getProgramByName(os_t * self, char * name){
  if (name != NULL){
for (int i = 0; i < self->count; i++){
    if (strcmp(self->pointers[i]->name,name) == 0){
        return self->pointers[i];
    }
}
  }
return NULL;

}

status_t os_sendMessage(os_t * self ,prog_t * sender , prog_t * recipient , char * message){
   if (self == NULL || sender == NULL || recipient == NULL || message == NULL ){
    return ERROR;
   }
    int status = 0;
    for (int i = 0; i < self->count; i++){
        if (self->pointers[i] == sender || self->pointers[i] == recipient){
            status++;
        }
    }
    if (status == 2){
      recipient->message[recipient->mCount] = malloc(200*sizeof(char));
      strcpy(recipient->message[recipient->mCount], message);
      recipient->progs[recipient->mCount] = sender;
      recipient->mCount++;
      return SUCCESSFUL;
}
    else return DIFFERENT_OS;



}

int prog_getMessages(prog_t * prog, char ** message){
if (prog == NULL || message == NULL ) return ERROR;
for (int i = 0; i < prog->mCount;i++){
    strcpy(message[i],prog->message[i]);
}
return prog->mCount;
}

char * prog_getName(prog_t * prog){

return prog->name;
}

int prog_getMessagesCount(prog_t * prog){
return prog->mCount;
}










