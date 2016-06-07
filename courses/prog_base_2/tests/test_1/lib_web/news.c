#include <stdlib.h>
#include "news.h"
#define BODY_SIZE 500
#define HEADER_SIZE 50

struct news_s {
char time[15];
char header[HEADER_SIZE];
char body [BODY_SIZE];
};

news_t * news_new()
{
   news_t * self = malloc(sizeof(struct news_s));
    return self;
}

void news_free(news_t * self)
{
    free(self);
}

void news_setNews(news_t * self,char * time, char * header, char * body){
strcpy(self->time,time);
strcpy(self->header,header);
strcpy(self->body,body);
}

char * news_getTime(news_t * self)
{
return self->time;
}

char * news_getHeader(news_t * self)
{
return self->header;
}

char * news_getBody(news_t * self)
{
return self->body;
}
