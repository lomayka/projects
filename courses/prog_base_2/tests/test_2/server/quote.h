#include <stdlib.h>
#include <stdio.h>

typedef struct quote_s quote_t;

quote_t * quote_new();
void quote_free(quote_t * self);
