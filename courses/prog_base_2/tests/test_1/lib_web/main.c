#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "web.h"
#include "news.h"
#include "list.h"
#define NEWS_COUNT 100

struct web_s
{
    char name[50];
    list_t *   event_notification;
    news_t * arr[NEWS_COUNT];
    int newsCount;
};

web_t * web_new(char * name)
{
web_t * self = malloc(sizeof(struct web_s));
strcpy(self->name, name);
self->event_notification = list_new();
self->newsCount = 0;
return self;
}

void web_free(web_t * self)
{
for (int i = 0; i < self->newsCount; i++){
    news_free(self->arr[i]);
}
int count = list_getCount(self->event_notification);
    for (int i = 0; i < count; i++) {
        event_t * ev = list_pop_back(self->event_notification);
        free(ev);
    }
  list_free(self->event_notification);
  free(self);
}

const char *
web_getName(web_t * self) {
    return self->name;
}

void web_setNews(web_t * self,news_t * news)
{
  self->arr[self->newsCount];
  self->newsCount++;
  webpage_sendMessage(self,news);
}

void
webpage_subscribeNotification(web_t * self, void * receiver, webpage_notification_fn callback) {
    event_t * sb = malloc(sizeof(struct event_s));
    sb->receiver = receiver;
    sb->callback = callback;
    list_push_back(self->event_notification, sb);
}

void
webpage_Unsubscribe(web_t * self, void * receiver)
{
    for (int i = 0; i < web_getSubscribersCount(self); i++){
        if (0 == strcmp(list_getEl(self->event_notification,i)->receiver,receiver))
            list_pop_back_byId(self->event_notification,i);
    }
}

void
webpage_sendMessage(web_t * self,news_t * news) {
    int count = list_getCount(self->event_notification);
    for (int i = 0; i < count; i++) {
        event_t * ev = list_getEl(self->event_notification, i);
        if (NULL != ev->callback) {
           webpage_notification_fn fn = ev->callback;
            fn(ev->receiver, self, news);
       }
    }
}

int
web_getSubscribersCount(web_t * self)
{
    return list_getCount(self->event_notification);
}

char * web_getUserName(web_t * self, int index){
event_t * ev;
ev = list_getEl(self->event_notification,index);
return ev->receiver;
}

int web_getNewsCount(web_t * self)
{
return self->newsCount;
}


