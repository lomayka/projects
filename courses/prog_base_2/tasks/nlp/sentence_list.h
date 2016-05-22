#include <stdio.h>
#include <stdlib.h>
#include "nlp.h"

typedef struct sentence_list_s sentence_list_t;
sentence_list_t * sentence_list_new();
void sentence_list_free(sentence_list_t * self);
void list_sentence_add(sentence_list_t * self,sentence_t * sentence);
void list_sentence_delete(sentence_list_t * self,int index);
sentence_t * list_sentence_getByIndex(sentence_list_t * self, int index);
int list_sentence_getSize(sentence_list_t * self);

