#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "programmers.h"
#include "cJSON.h"
typedef struct programmer_s {
    char name[256];
    char surname[256];
    char language[20];
    char data[11];
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

char * getName(programmer_t * self){
   return  self->name;
}

void programmer_setName(programmer_t * self,char * name)
{
    strcpy(self->name,name);
}
void programmer_setSurname(programmer_t * self,char * surname){
strcpy(self->surname,surname);
}
void programmer_setLanguage(programmer_t * self,char * language){
strcpy(self->language,language);
}
void programmer_setRating(programmer_t * self,double rating)
{
    self->rating = rating;
}
void programmer_setYear(programmer_t * self,int year){
    self->year = year;
}

void programmer_setData(programmer_t * self,char * data){
    strcpy(self->data,data);
}

char * programmer_getName(programmer_t * self)
{
    return self->name;
}

char * programmer_toJSON(programmer_t * self)
{
cJSON * jProgrammer = cJSON_CreateObject();
    cJSON_AddItemToObject(jProgrammer, "name", cJSON_CreateString(self->name));
    cJSON_AddItemToObject(jProgrammer, "surname", cJSON_CreateString(self->surname));
    cJSON_AddItemToObject(jProgrammer, "language", cJSON_CreateString(self->language));
    cJSON_AddItemToObject(jProgrammer, "data", cJSON_CreateString(self->data));
    cJSON_AddItemToObject(jProgrammer, "year", cJSON_CreateNumber(self->year));
    cJSON_AddItemToObject(jProgrammer, "rating", cJSON_CreateNumber(self->rating));
    char * jsonString = cJSON_Print(jProgrammer);
    return jsonString;
}









