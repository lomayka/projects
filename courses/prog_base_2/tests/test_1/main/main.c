#include <stdio.h>
#include <stdlib.h>
#include "web.h"
#include "news.h"

typedef struct user_s {
    char name[100];
} user_t;

void user_onNotification(void * receiver, web_t * sender, news_t * news) {
    user_t * user = (user_t *)receiver;
    const char * pageName = web_getName(sender);
    printf("User: %s get from: %s\nThis news:\nHeader:%s\nBody:%s\nTime:%s\n\n",receiver,pageName,news_getHeader(news),news_getBody(news),news_getTime(news));
}


int main()
{
    user_t users[4] = {{"Taras"}, {"Olya"}, {"Ira"}, {"Andriy"}};
    web_t * vk = web_new("vk.com");
    news_t * news = news_new();
    news_setNews(news,"2016-05-21","Cool header here", "Something interesting here");

    for (int i = 0; i < 4; i++) {
        webpage_subscribeNotification(vk, &users[i], user_onNotification);
    }
    printf("Web site: %s\n",web_getName(vk));
    printf("Subscribed users: %d\n\n",web_getSubscribersCount(vk));

    for (int i = 0; i < web_getSubscribersCount(vk); i++)
   {
      printf("Username: %s \n",web_getUserName(vk,i));
    }
     printf("\n");

    web_setNews(vk,news);
    printf("News on site: %d\n\n",web_getNewsCount(vk));
    webpage_Unsubscribe(vk,"Taras");  // Taras unsubscribed

    printf("Subscribed users: %d\n",web_getSubscribersCount(vk));
    for (int i = 0; i < web_getSubscribersCount(vk); i++)
   {
      printf("Username: %s \n",web_getUserName(vk,i));
    }
     printf("\n");

    return 0;
}
