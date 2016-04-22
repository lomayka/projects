#include <stdlib.h>
#include <stdio.h>

#include "programmers.h"

void programmer_print(programmer_t * st) {
    printf("Name: %s\nSurname: %s\nLanguage: %s\nData: %s\nRating: %f\nYear: %i\n\n",
        st->name, st->surname,st->language,st->data, st->rating, st->year);
}

void programmer_printList(programmer_t * arr, int len) {
    for (int i = 0; i < len; i++) {
        programmer_print(&arr[i]);
    }
}
