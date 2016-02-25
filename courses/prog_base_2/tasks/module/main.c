#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

int main()
{
list_t * ls1 = list_new();
list_add(ls1,5,list_size(ls1),0);
list_add(ls1,10,list_size(ls1),1);
list_add(ls1,4,list_size(ls1),0);
list_add(ls1,2,list_size(ls1),0);
assert(list_max(ls1) == 10);
assert(list_size(ls1) == 4);
list_delete(ls1,list_size(ls1),3);
//printf("%d ", list_max(ls1));
//printf("%d ", list_min(ls1));
//printf("%d ", list_size(ls1));
assert(list_max(ls1) == 5);
assert(list_min(ls1) == 2);
assert(list_size(ls1) == 3);

printf("OK!\n");
//print_list(ls1); //  to print the list
list_free(ls1);

    return 0;
}
