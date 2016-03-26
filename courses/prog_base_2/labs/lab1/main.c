#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>  // !
#include <stddef.h>  // !
#include <setjmp.h>  // !

#include <cmocka.h>
#include "OS.h"
#include "program.h"


   static void new_void_status(void **state)
{
    os_t * os1 = os_new("Windows");
    prog_t * p1 = prog_new(os1,"Explorer");
    assert_int_equal(prog_free(os1,p1),SUCCESSFUL);
    assert_int_equal(os_free(os1),SUCCESSFUL);



}

 static void new_nameNull_NULL (void **state)
{
    os_t * os2 = os_new(NULL);
    assert_null(os2);
    prog_t * p2 = prog_new(os2,NULL);
    assert_null(p2);
    assert_int_equal(prog_free(os2,p2),ERROR);
    assert_int_equal(os_free(os2),ERROR);

}





   static void getPrograms_pointers_two(void **state)
{
    os_t * os1 = os_new("Linux");
    prog_t * p1 = prog_new(os1,"Chrome");
    prog_t * p2 = prog_new(os1,"Explorer");
    prog_t * progs[10];
    int count = os_getPrograms(os1, progs);
    assert_int_equal(count,2);
    prog_free(os1,p1);
    prog_free(os1,p2);
    os_free(os1);
}

  static void getPrograms_NullPointers_ERROR(void **state)
{
    os_t * os1 = os_new("Linux");
    prog_t * p1 = prog_new(os1,"Chrome");
    prog_t * p2 = prog_new(os1,"Explorer");
    prog_t * progs[10];
    int count = os_getPrograms(NULL, NULL);
    assert_int_equal(count,ERROR);
    prog_free(os1,p1);
    prog_free(os1,p2);
    os_free(os1);
}

   static void getProgramByName_name_pointerOfProgram(void **state)
{
    os_t * os1 = os_new("Linux");
    prog_t * p1 = prog_new(os1,"Chrome");
    prog_t * pp1 = os_getProgramByName(os1,"Chrome");
    assert_memory_equal(p1,pp1,sizeof(prog_t*));
    prog_free(os1,p1);
    prog_free(os1,pp1);
    os_free(os1);

}

   static void getProgramByName_nullName_NULLPointer(void **state)
{
    os_t * os1 = os_new("Linux");
    prog_t * p1 = prog_new(os1,"Chrome");
    prog_t * pp1 = os_getProgramByName(os1,NULL);
    assert_null(pp1);
    prog_free(os1,p1);
    prog_free(os1,pp1);
    os_free(os1);

}

   static void sendMessege_message_transmitMessage(void **state)
{   int mCount;
    os_t * os1 = os_new("Linux");
    prog_t * p1 = prog_new(os1,"Chrome");
    prog_t * p2 = prog_new(os1,"Explorer");
    char * message = "I am batman!";
    char * messeges[150];
    assert_int_equal(os_sendMessage(os1,p1,p2,message),SUCCESSFUL);
    mCount = prog_getMessages(p2,&messeges);
    assert_string_equal(message,messeges[0]);
    prog_free(os1,p1);
    prog_free(os1,p2);
    os_free(os1);

}


static void messageCount_message_count(void **state)
{
  int mCount;
  os_t * os1 = os_new("Linux");
  prog_t * p1 = prog_new(os1,"Chrome");
  prog_t * p2 = prog_new(os1,"Explorer");
  mCount = prog_getMessagesCount(p1);
  assert_int_equal(mCount,0);
  char * message = "Fry potato!";
  os_sendMessage(os1,p1,p2,message);
  mCount = prog_getMessagesCount(p2);
  assert_int_equal(mCount,1);
  prog_free(os1,p1);
  prog_free(os1,p2);
  os_free(os1);

}

   static void sendMessege_message_DifferentOS(void **state)
{   int mCount;
    os_t * os1 = os_new("Linux");
    os_t * os2 = os_new("Windows");
    prog_t * p1 = prog_new(os1,"Chrome");
    prog_t * p2 = prog_new(os2,"Explorer");
    char * message = "I am batman!";
    assert_int_equal(os_sendMessage(os1,p1,p2,message),DIFFERENT_OS);
    prog_free(os1,p1);
    prog_free(os1,p2);
    os_free(os1);
    os_free(os2);
}

   static void getNameByPointer_pointer_name(void **state)
{
    os_t * os1 = os_new("Linux");
    prog_t * p1 = prog_new(os1,"Chrome");
    char *  name = prog_getName(p1);;
    assert_string_equal(name,"Chrome");
    prog_free(os1,p1);
    os_free(os1);

}





int main(void) {
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(new_void_status),
        cmocka_unit_test(getPrograms_pointers_two),
        cmocka_unit_test(getProgramByName_name_pointerOfProgram),
        cmocka_unit_test(getProgramByName_nullName_NULLPointer),
        cmocka_unit_test(new_nameNull_NULL),
        cmocka_unit_test(sendMessege_message_transmitMessage),
        cmocka_unit_test(messageCount_message_count),
        cmocka_unit_test(getPrograms_NullPointers_ERROR),
        cmocka_unit_test(sendMessege_message_DifferentOS),
        cmocka_unit_test(getNameByPointer_pointer_name),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
