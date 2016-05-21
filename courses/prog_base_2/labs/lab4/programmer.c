#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cJSON.h"
#include "programmer.h"

struct programmer_s
{
char name[20];
char surname[20];
char company[30];
char language[20];
double rating;
int year;
};

programmer_t * programmer_new(){
programmer_t * self = malloc(sizeof(struct programmer_s));
return self;
}

void programmer_free(programmer_t * self){
free(self);
}

void programmer_set(programmer_t * self,char * name, char * surname, char * company, char * language, double rating){
strcpy(self->name,name);
strcpy(self->surname,surname);
strcpy(self->company,company);
strcpy(self->language,language);
self->rating = rating;
}

char * programmer_getName(programmer_t * self){
return self->name;
}

char * programmer_getSurname(programmer_t * self){
return self->surname;
}

char * programmer_getCompany(programmer_t * self){
return self->company;
}

char * programmer_getLanguage(programmer_t * self){
return self->language;
}

double  programmer_getRating(programmer_t * self){
return self->rating;
}

char * programmer_toJSON(programmer_t * self){
cJSON * jProgrammer = cJSON_CreateObject();
cJSON_AddItemToObject(jProgrammer, "name", cJSON_CreateString(self->name));
cJSON_AddItemToObject(jProgrammer, "surname", cJSON_CreateString(self->surname));
cJSON_AddItemToObject(jProgrammer, "company", cJSON_CreateString(self->company));
cJSON_AddItemToObject(jProgrammer, "language", cJSON_CreateString(self->language));
cJSON_AddItemToObject(jProgrammer, "rating", cJSON_CreateNumber(self->rating));
char * jsonString = cJSON_Print(jProgrammer);
return jsonString;
}

