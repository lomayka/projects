#include <stdio.h>
#include <stdlib.h>
#include "sentence_list.h"
#include "nlp.h"
#define MAX_SENTENCE_LENGTH   10000

struct sentence_list_s {
int sentenceCount;
sentence_t * sentences[MAX_SENTENCE_LENGTH];
};

sentence_list_t * sentence_list_new(){
sentence_list_t * self = malloc(sizeof(struct sentence_list_s));
self->sentenceCount = 0;
return self;
}
void sentence_list_free(sentence_list_t * self){
for (int i = 0; i < self->sentenceCount;i++){
sentence_free(self->sentences[i]);
}
free(self);
}

void list_sentence_add(sentence_list_t * self, sentence_t * sentence)
{
self->sentences[self->sentenceCount] = sentence;
self->sentenceCount++;
}

void list_sentence_delete(sentence_list_t * self,int index){
// todo
}

sentence_t * list_sentence_getByIndex(sentence_list_t * self,int index)
{
    return self->sentences[index];
}

int list_sentence_getSize(sentence_list_t * self)
{
    return self->sentenceCount;
}

