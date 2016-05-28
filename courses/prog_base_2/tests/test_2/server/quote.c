
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "quote.h"
#include "cJSON.h"

struct quote_s
{
    char author[30];
    char quote[200];
    char date[50];
};

quote_t * quote_new()
{
    quote_t * self = malloc(sizeof(struct quote_s));
    return self;
}

void quote_free(quote_t * self)
{
    free(self);
}

void quote_set(quote_t * self,char * author,char * quote)
{
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    strcpy(self->author,author);
    strcpy(self->quote,quote);
    char * time = asctime(timeinfo);
    time[strlen(time)-1] = '\0';
    strcpy(self->date,time);
}

char * quote_toJSON(quote_t * self)
{
    cJSON * jQuote = cJSON_CreateObject();
    cJSON_AddItemToObject(jQuote, "author", cJSON_CreateString(self->author));
    cJSON_AddItemToObject(jQuote, "quote", cJSON_CreateString(self->quote));
    cJSON_AddItemToObject(jQuote, "time", cJSON_CreateString(self->date));

    char * jsonString = cJSON_Print(jQuote);
    return jsonString;
}


