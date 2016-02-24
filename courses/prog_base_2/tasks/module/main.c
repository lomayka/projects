#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

int main()
{
list_t * ls1 = list_new();
list_add(5,list_size(ls1),0,ls1);
list_add(10,list_size(ls1),1,ls1);
list_add(4,list_size(ls1),0,ls1);
list_add(2,list_size(ls1),0,ls1);
assert(list_max(ls1) == 10);
assert(list_size(ls1) == 4);
list_delete(list_size(ls1),3,ls1);
//printf("%d ", list_max(ls1));
//printf("%d ", list_min(ls1));
//printf("%d ", list_size(ls1));
assert(list_max(ls1) == 5);
assert(list_min(ls1) == 2);
assert(list_size(ls1) == 3);

printf("OK!\n");
//test(ls1); //  to print the list


    return 0;
}
