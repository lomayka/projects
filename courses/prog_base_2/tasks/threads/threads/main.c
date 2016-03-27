#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "producer.h"
#include "consumer.h"
#include "mutex.h"
#include "array.h"


int main(void) {// vse krivo, ale ya staravsya, 4esno
    mutex_t * m1 = new_mutex();
    module_t * p1 = new_producer(m1);
    module_t * p2 = new_producer(m1);
    module_t * p3 = new_producer(m1);
    module_t * c1 = new_comsumer(m1);
    module_t * c2 = new_comsumer(m1);

    WaitForSingleObject(p1, INFINITE);
    free_producer(p1);
    free_producer(p2);
    free_producer(p3);
    free_consumer(c1);
    free_consumer(c2);
    free_mutex(m1);

    return 0;
}




