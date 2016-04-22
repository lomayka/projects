#ifndef PROGRAMMERS_H_INCLUDED
#define PROGRAMMERS_H_INCLUDED

typedef struct programmer_s {
    int id;
    char name[256];
    char surname[256];
    char language[20];
    char data[11];
    double rating;
    int year;
} programmer_t;

void programmer_print(programmer_t * st);
void programmer_printList(programmer_t * arr, int len);

#endif // PROGRAMMERS_H_INCLUDED
