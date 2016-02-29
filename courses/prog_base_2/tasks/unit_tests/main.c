#include <stdlib.h>  // !
#include <stdarg.h>  // !
#include <stddef.h>  // !
#include <setjmp.h>  // !

#include <cmocka.h>

#include "list.h"

#define ADD 4
#define MAX 15
#define MIN -3


// hope the names are correct
static void new_void_listAddDelete(void **state)
{
    list_t * ls1 = list_new();
    assert_int_equal(list_add(ls1,ADD,0),SUCCESSFUL);
    assert_int_equal(list_delete(ls1,5),WRONG_INDEX);
    assert_int_equal(list_delete(ls1,0),SUCCESSFUL);
    assert_int_equal(list_add(ls1,9,3),WRONG_INDEX);
    list_free(ls1);
}

static void new_void_listSizeCheck(void **state)
{
    list_t * ls3 = list_new();
    assert_int_equal(list_size(ls3),0);
    assert_int_equal(list_add(ls3,MIN,0),SUCCESSFUL);
    assert_int_equal(list_add(ls3,ADD,1),SUCCESSFUL);
    assert_int_equal(list_check(ls3,1),ADD);
    assert_int_equal(list_size(ls3),2);
   list_free(ls3);
}

static void new_void_listMaxMin(void **state)
{
    list_t * ls4 = list_new();
    assert_int_equal(list_add(ls4,ADD,0),SUCCESSFUL);
    assert_int_equal(list_add(ls4,MAX,1),SUCCESSFUL);
    assert_int_equal(list_add(ls4,MIN,2),SUCCESSFUL);
    assert_int_equal(list_max(ls4),MAX);
    assert_int_equal(list_min(ls4),MIN);
    assert_int_equal(list_free(ls4),SUCCESSFUL);
}



int main(void) {
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(new_void_listAddDelete),
        cmocka_unit_test(new_void_listSizeCheck),
        cmocka_unit_test(new_void_listMaxMin),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
