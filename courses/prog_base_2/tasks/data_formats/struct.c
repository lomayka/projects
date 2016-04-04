#include <stdio.h>
#include "struct.h"

struct Project{
char  name[25];
char started[15];
char release[15];
int hours;
int percent;
};
struct Programmer{
char  name[15];
char  surname[15];
char  birthdate[15];
char  company[15];
char  position[15];
char language[15];
int hired;
double rating;
struct Project prog[2];
};

programmer * progr_create(){
programmer * p = malloc(sizeof(struct Programmer));
return p;
}


void set_progr(programmer * p,char * programmer_name,char * programmer_surn, char * programmer_birthdate, char * programmer_company, char * programmer_position,char * prog_language, int hired, double rating){
strcpy(p->name,programmer_name);
strcpy(p->surname,programmer_surn);
strcpy(p->birthdate,programmer_birthdate);
strcpy(p->company,programmer_company);
strcpy(p->position,programmer_position);
strcpy(p->language,prog_language);
p->hired = hired;
p->rating = rating;
}

void set_proj(programmer * p,char * project_name,char * project_start, char * project_release, int project_hours, int project_percent,int i){
strcpy(p->prog[i].name,project_name);
strcpy(p->prog[i].started,project_start);
strcpy(p->prog[i].release,project_release);
p->prog[i].hours = project_hours;
p->prog[i].percent = project_percent;
}

void prog_print(programmer * p){
printf("Name: %s, Surname: %s, Birthdate: %s, Company: %s, Position: %s, Language: %s, Hired(year): %d, Rating: %f ",p->name,p->surname,p->birthdate,p->company,p->position,p->language,p->hired,p->rating);
for (int i =0 ;i < 2; i++){
    printf("Project: %s, Started: %s, Release: %s, Spend hours: %d, Percent: %d ",p->prog[i].name,p->prog[i].started,p->prog[i].release,p->prog[i].hours,p->prog[i].percent);
}
printf("\n\n");
}

void progr_free(programmer * p){
free(p);
}
