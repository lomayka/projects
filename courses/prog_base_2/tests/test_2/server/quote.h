#ifndef quote_H_INCLUDED
#define quote_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

typedef struct quote_s quote_t;

quote_t * quote_new();
void quote_free(quote_t * self);
void quote_set(quote_t * self,char * author,char * quote);
char * quote_toJSON(quote_t * self);
#endif // quote_H_INCLUDED
