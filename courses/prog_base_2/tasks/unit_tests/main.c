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
static void ListAddDelete_fewValues_Status(void **state)
{
    list_t * ls1 = list_new();
    assert_int_equal(list_add(ls1,ADD,0),SUCCESSFUL);
    assert_int_equal(list_delete(ls1,5),WRONG_INDEX);
    assert_int_equal(list_delete(ls1,0),SUCCESSFUL);
    assert_int_equal(list_add(ls1,9,3),WRONG_INDEX);
    assert_int_equal(list_free(ls1),SUCCESSFUL);
}

static void ListSize_twoValues_Two(void **state)
{
    list_t * ls3 = list_new();
    assert_int_equal(list_size(ls3),0);
    list_add(ls3,MIN,0);
    list_add(ls3,ADD,1);
    assert_int_equal(list_size(ls3),2);
    list_free(ls3);
}

static void ListMaxValue_twoValues_MAX(void **state)
{
    list_t * ls4 = list_new();
    list_add(ls4,ADD,0);
    list_add(ls4,MAX,1);

    assert_int_equal(list_max(ls4),MAX);
    list_free(ls4);
}

static void ListMinValue_twoValues_MIN(void **state)
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
        cmocka_unit_test(ListAddDelete_fewValues_Status),
        cmocka_unit_test(ListSize_twoValues_Two),
        cmocka_unit_test(ListMaxValue_twoValues_MAX),
        cmocka_unit_test(ListMinValue_twoValues_MIN),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
