#include <stdlib.h>
#include <stdio.h>
#include "quote.h"

struct quote_s {
char author[30];
char quote[200];
};

quote_t * quote_new(){
quote_t * self = malloc(sizeof(struct quote_s));
return self;
}

void quote_free(quote_t * self){
free(self);
}

