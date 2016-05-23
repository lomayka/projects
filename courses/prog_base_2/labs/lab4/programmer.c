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
    char date[11];
    double rating;
    int year;
};

programmer_t * programmer_new()
{
    programmer_t * self = malloc(sizeof(struct programmer_s));
    return self;
}

void programmer_free(programmer_t * self)
{
    free(self);
}

void programmer_set(programmer_t * self,char * name, char * surname, char * company, char * language, double rating, int year, char * date)
{
    strcpy(self->name,name);
    strcpy(self->surname,surname);
    strcpy(self->company,company);
    strcpy(self->language,language);
    strcpy(self->date,date);
    self->rating = rating;
    self->year = year;
}

char * programmer_getName(programmer_t * self)
{
    return self->name;
}

char * programmer_getSurname(programmer_t * self)
{
    return self->surname;
}

char * programmer_getCompany(programmer_t * self)
{
    return self->company;
}

char * programmer_getLanguage(programmer_t * self)
{
    return self->language;
}

double  programmer_getRating(programmer_t * self)
{
    return self->rating;
}
char * programmer_getDate(programmer_t * self)
{
    return self->date;
}

int programmer_getYear(programmer_t * self)
{
    return self->year;
}

char * programmer_toJSON(programmer_t * self)
{
    cJSON * jProgrammer = cJSON_CreateObject();
    cJSON_AddItemToObject(jProgrammer, "name", cJSON_CreateString(self->name));
    cJSON_AddItemToObject(jProgrammer, "surname", cJSON_CreateString(self->surname));
    cJSON_AddItemToObject(jProgrammer, "company", cJSON_CreateString(self->company));
    cJSON_AddItemToObject(jProgrammer, "language", cJSON_CreateString(self->language));
    cJSON_AddItemToObject(jProgrammer, "rating", cJSON_CreateNumber(self->rating));
    cJSON_AddItemToObject(jProgrammer, "year", cJSON_CreateNumber(self->year));
    cJSON_AddItemToObject(jProgrammer, "date", cJSON_CreateString(self->date));
    char * jsonString = cJSON_Print(jProgrammer);
    return jsonString;
}

char * programmer_toHTML(programmer_t * self, int id)
{
    char * text = malloc(sizeof(char) * 10240);
    sprintf(text,
            "<p>"
            "Name: %s<br>"
            "Surname: %s<br>"
            "Company: %s<br>"
            "Language: %s<br>"
            "Year: %i<br>"
            "Rating: %.1f<br>"
            "Date: %s"
            "</p>",
            self->name, self->surname, self->company,self->language,
            self->year, self->rating,self->date);
    char * pageTextLink = "<a href=\"/programmers\" onclick=\"doDelete()\"/>Delete<br><br></a>\n";
    strcat(text, pageTextLink);

    char pageTextScript[1024];
    sprintf(pageTextScript,
            "<script>"
            "function doDelete() {"
            "var xhttp = new XMLHttpRequest();"
            "xhttp.open(\"DELETE\", \"http://127.0.0.1:5000/programmers/%i\", true);"
            "xhttp.send();"
            "}"
            "</script>", id);
    strcat(text, pageTextScript);
    return text;
}
