#include <stdio.h>
#include <stdlib.h>
#include "nlp.h"

typedef struct word_list_s word_list_t;
word_list_t * word_list_new();
void word_list_free(word_list_t * self);
void list_add(word_list_t * self, word_t * word);
void list_delete(word_list_t * self,int index);
word_t * list_getByIndex(word_list_t * self, int index);
int list_getSize(word_list_t * self);
