#include <stdio.h>
#include <stdlib.h>
#include "word_list.h"
#include "nlp.h"
#define MAX_WORD_LENGTH       500

struct word_list_s {
int wordsCount;
word_t * words[MAX_WORD_LENGTH];
};

word_list_t * word_list_new(){
word_list_t * self = malloc(sizeof(struct word_list_s));
self->wordsCount = 0;
return self;
}
void word_list_free(word_list_t * self){
for (int i = 0; i < self->wordsCount;i++){
word_free(self->words[i]);
}
free(self);
}

void list_add(word_list_t * self, word_t * word)
{
self->words[self->wordsCount] = word;
self->wordsCount++;
}

void list_delete(word_list_t * self,int index){
word_setWord(self->words[index],NULL);
 // hot fix sorry for this
}

word_t * list_getByIndex(word_list_t * self,int index)
{
    return self->words[index];
}

int list_getSize(word_list_t * self)
{
    return self->wordsCount;
}
