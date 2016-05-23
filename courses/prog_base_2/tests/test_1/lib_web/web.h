#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "news.h"

typedef struct web_s web_t;


typedef
    void
    (*webpage_notification_fn)
    (void * receiver, web_t * sender, news_t * news);

web_t * web_new(char * name);

void web_free(web_t * self);

const char *
web_getName(web_t * self);

void
webpage_subscribeNotification(web_t * self, void * receiver, webpage_notification_fn callback);

void
webpage_sendMessage(web_t * self, news_t * news);

void
web_setNews(web_t * self,news_t * news);

int
web_getSubscribersCount(web_t * self);

char *
web_getUserName(web_t * self, int index);

int web_getNewsCount(web_t * self);

void
webpage_Unsubscribe(web_t * self, void * receiver);
