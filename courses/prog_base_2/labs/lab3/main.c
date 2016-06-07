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
machine_free(joycasino);
  return 0;
}




/*



#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>  // !
#include <stdarg.h>  // !
#include <stddef.h>  // !
#include <setjmp.h>  // !
#include <cmocka.h>
#include "machine.h"
#include "list.h"

static void list_new_void_sizeZero(void ** state){
list_t * list = list_new();
assert_non_null(list);
assert_int_equal(list_getCount(list),0);
list_free(list);
}

static void list_add_void_sizeCount(void ** state){
list_t * list = list_new();
event_t * ev = malloc(sizeof(struct event_s));
list_push_back(list,ev);
assert_int_equal(list_getCount(list),1);
list_pop_back(list);
assert_int_equal(list_getCount(list),0);
list_free(list);
}

static void list_void_popPush(void ** state){
list_t * list = list_new();
event_t * ev = malloc(sizeof(struct event_s));
char * receiver = "Ruslan";
char * callback = "Smth";
ev->callback = callback;
ev->receiver = receiver;
list_push_back(list,ev);
ev = list_pop_back(list);
assert_string_equal(ev->receiver,receiver);
assert_string_equal(ev->callback,callback);

list_free(list);
}

static void list_void_getElem(void ** state){
list_t * list = list_new();
event_t * ev = malloc(sizeof(struct event_s));
char * receiver = "Ruslan";
char * callback = "Smth";
ev->callback = callback;
ev->receiver = receiver;
list_push_back(list,ev);
ev = list_getEl(list,0);
assert_string_equal(ev->receiver,receiver);
assert_string_equal(ev->callback,callback);
assert_int_equal(list_getCount(list),1);
list_free(list);
}


int main(void) {
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(list_new_void_sizeZero),
        cmocka_unit_test(list_add_void_sizeCount),
        cmocka_unit_test(list_void_popPush),
        cmocka_unit_test(list_void_getElem),

    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}*/
