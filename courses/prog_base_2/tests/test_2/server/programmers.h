#ifndef PROGRAMMERS_H_INCLUDED
#define PROGRAMMERS_H_INCLUDED

typedef struct programmer_s programmer_t;

programmer_t * programmer_new();
void programmer_free(programmer_t * self);
void programmer_print(programmer_t * st);
void programmer_printList(programmer_t * arr, int len);
void programmer_setName(programmer_t * self,char * name);
void programmer_setSurname(programmer_t * self,char * surname);
void programmer_setLanguage(programmer_t * self,char * language);
void programmer_setCompany(programmer_t * self,char * company);
void programmer_setRating(programmer_t * self,double rating);
void programmer_setYear(programmer_t * self,int year);

#endif // PROGRAMMERS_H_INCLUDED
