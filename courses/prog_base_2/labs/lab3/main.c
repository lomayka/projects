#include <stdio.h>
#include <stdlib.h>
#include "machine.h"
#include "list.h"

typedef struct user_s {
    char name[100];
} user_t;

void user_onNotification(void * receiver, machine_t * sender) {
    user_t * user = (user_t *)receiver;

    printf("User: %s\n",receiver);
    printf("Singed on %s event\n",machine_getState(sender));
    printf("Machine name: %s\n", machine_getName(sender));
    printf("Numbers: %d %d %d\n\n", machine_getArray(sender,0),machine_getArray(sender,1),machine_getArray(sender,2));
}

void user_over_onNotification(void * receiver, machine_t * sender) {
    user_t * user = (user_t *)receiver;
    printf("Dear %s\n",receiver);
    printf("For success access to xCasino use 8xCasino\n\n");
}


int main()
{
user_t users[4] = {{"Taras"}, {"Olya"}, {"Ira"}, {"Andriy"}};

machine_t * joycasino = machine_new("Joycasino");

machine_subscribeNotification(joycasino,&users[0],user_onNotification,Up);
machine_subscribeNotification(joycasino,&users[1],user_onNotification,Down);
machine_subscribeNotification(joycasino,&users[2],user_onNotification,Normal);
machine_subscribeNotification(joycasino,&users[3],user_onNotification,Up);


while(!kbhit()){
machine_generate(joycasino);
}
getch();
getch();
  return 0;
}
