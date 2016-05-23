#include <stdlib.h>


typedef struct news_s news_t;

news_t * news_new();
void news_free(news_t * self);
void news_setNews(news_t * self,char * data, char * header, char * body);
char * news_getHeader(news_t * self);
char * news_getTime(news_t * self);
char * news_getBody(news_t * self);
