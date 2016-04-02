#include <stdio.h>

typedef struct Programmer programmer;
programmer * progr_create();
void set_progr(programmer * p,char * programmer_name,char * programmer_surn, char * programmer_birthdate, char * programmer_company, char * programmer_position,char * prog_language, int hired, double rating);
void set_proj(programmer * p,char * project_name,char * project_start, char * project_release, int project_hours, int project_percent,int i);
void prog_print(programmer * p);
void progr_free(programmer * p);
