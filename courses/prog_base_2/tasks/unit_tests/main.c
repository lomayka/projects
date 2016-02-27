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
static void new_void_listDelete(void **state)
{
    list_t * ls1 = list_new();
    assert_int_equal(list_add(ls1,ADD,0),SUCCESSFUL);
    assert_int_equal(list_delete(ls1,5),WRONG_INDEX);
    assert_int_equal(list_delete(ls1,0),SUCCESSFUL);
    assert_int_equal(list_size(ls1),0);
    assert_int_equal(list_free(ls1),SUCCESSFUL );
}

static void new_void_listAdd(void **state)
{
    list_t * ls2 = list_new();
    assert_int_equal(list_add(ls2,ADD-1,0),SUCCESSFUL);
    assert_int_equal(list_add(ls2,9,3),WRONG_INDEX);
    assert_int_equal(list_add(ls2,ADD,0),SUCCESSFUL);
    assert_int_equal(list_check(ls2,0), ADD);
    assert_int_equal(list_check(ls2,1), ADD-1);
    assert_int_equal(list_size(ls2),2);
    assert_int_equal(list_free(ls2),SUCCESSFUL );
}

static void new_void_listSize(void **state)
{
    list_t * ls3 = list_new();
    assert_int_equal(list_size(ls3),0);
    assert_int_equal(list_add(ls3,ADD,0),SUCCESSFUL);
    assert_int_equal(list_add(ls3,ADD,1),SUCCESSFUL);
    assert_int_equal(list_add(ls3,ADD,2),SUCCESSFUL);
    assert_int_equal(list_size(ls3),3);
    assert_int_equal(list_free(ls3),SUCCESSFUL );
}

static void new_void_listMax(void **state)
{
    list_t * ls4 = list_new();
    assert_int_equal(list_add(ls4,ADD,0),SUCCESSFUL);
    assert_int_equal(list_add(ls4,MAX,1),SUCCESSFUL);
    assert_int_equal(list_add(ls4,MIN,2),SUCCESSFUL);
    assert_int_equal(list_max(ls4),MAX);
    assert_int_equal(list_add(ls4,MAX+ADD,2),SUCCESSFUL);
    assert_int_equal(list_max(ls4),MAX+ADD);
    assert_int_equal(list_free(ls4),SUCCESSFUL );
}

static void new_void_listMin(void **state)
{
    list_t * ls5 = list_new();
    assert_int_equal(list_add(ls5,ADD,0),SUCCESSFUL);
    assert_int_equal(list_add(ls5,MAX,1),SUCCESSFUL);
    assert_int_equal(list_add(ls5,MIN,2),SUCCESSFUL);
    assert_int_equal(list_min(ls5),MIN);
    assert_int_equal(list_add(ls5,MIN-ADD,2),SUCCESSFUL);
    assert_int_equal(list_min(ls5),MIN-ADD);
    assert_int_equal(list_free(ls5),SUCCESSFUL );
}

static void new_void_listCheck(void **state)
{
    list_t * ls6 = list_new();
    assert_int_equal(list_add(ls6,ADD,0),SUCCESSFUL);
    assert_int_equal(list_add(ls6,MAX,1),SUCCESSFUL);
    assert_int_equal(list_add(ls6,MIN,2),SUCCESSFUL);
    assert_int_equal(list_check(ls6,0),ADD);
    assert_int_equal(list_check(ls6,1),MAX);
    assert_int_equal(list_check(ls6,2),MIN);
    assert_int_equal(list_add(ls6,MAX+MIN,1),SUCCESSFUL);
    assert_int_equal(list_check(ls6,1),MAX+MIN);
    assert_int_equal(list_free(ls6),SUCCESSFUL );
}


int main(void) {
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(new_void_listAdd),
        cmocka_unit_test(new_void_listDelete),
        cmocka_unit_test(new_void_listSize),
        cmocka_unit_test(new_void_listMax),
        cmocka_unit_test(new_void_listMin),
        cmocka_unit_test(new_void_listCheck),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
