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
static void new_void_listAddDeleteElement(void **state)
{
    list_t * ls1 = list_new();
    assert_int_equal(list_add(ls1,ADD,0),SUCCESSFUL);
    assert_int_equal(list_delete(ls1,5),WRONG_INDEX);
    assert_int_equal(list_delete(ls1,0),SUCCESSFUL);
    assert_int_equal(list_add(ls1,9,3),WRONG_INDEX);
    assert_int_equal(list_free(ls1),SUCCESSFUL);
}

static void new_void_listSizeFind(void **state)
{
    list_t * ls3 = list_new();
    assert_int_equal(list_size(ls3),0);
    list_add(ls3,MIN,0);
    list_add(ls3,ADD,1);
    assert_int_equal(list_check(ls3,1),ADD);
    assert_int_equal(list_size(ls3),2);
    list_free(ls3);
}

static void new_void_listMaxValue(void **state)
{
    list_t * ls4 = list_new();
    list_add(ls4,ADD,0);
    list_add(ls4,MAX,1);

    assert_int_equal(list_max(ls4),MAX);
    list_free(ls4);
}

static void new_void_listMinValue(void **state)
{
    list_t * ls4 = list_new();
    list_add(ls4,ADD,0);
    list_add(ls4,MIN,1);
    assert_int_equal(list_min(ls4),MIN);
    list_free(ls4);
}



int main(void) {
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(new_void_listAddDeleteElement),
        cmocka_unit_test(new_void_listSizeFind),
        cmocka_unit_test(new_void_listMaxValue),
        cmocka_unit_test(new_void_listMinValue),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
