#include <stdlib.h>
#include <stdio.h>

#include "cJSON.h"

#include "programmers.h"

static cJSON * _programmer_serializeJSON(const programmer_t * self) {
    cJSON * jProgrammer = cJSON_CreateObject();
	cJSON_AddItemToObject(jProgrammer, "name", cJSON_CreateString(self->name));
	cJSON_AddItemToObject(jProgrammer, "surname", cJSON_CreateString(self->surname));
	cJSON * jCompany = cJSON_CreateObject();
	cJSON_AddItemToObject(jCompany, "name", cJSON_CreateString(self->company.name));
	cJSON_AddItemToObject(jCompany, "position", cJSON_CreateString(self->company.position));
	cJSON_AddItemToObject(jProgrammer, "working", jCompany);
	cJSON_AddItemToObject(jProgrammer, "hired", cJSON_CreateNumber(self->year));
	cJSON_AddItemToObject(jProgrammer, "rating", cJSON_CreateNumber(self->rating));
	return jProgrammer;
}

programmer_t
programmer_empty(void) {
    programmer_t st = {
        .name = "",
        .surname = "",
        .year = 0,
        .rating = 0.0,
        .company = {
            .name = "",
            .position = ""
        }
    };
    return st;
}

const char *
programmer_toJSON(const programmer_t * self) {
    cJSON * jProgrammer = _programmer_serializeJSON(self);
	const char * jsonString = cJSON_Print(jProgrammer);
	cJSON_Delete(jProgrammer);
    return jsonString;
}

const char *
programmer_listToJSON(const programmer_t * const programmerList, int programmerListSize) {
    cJSON * jArr = cJSON_CreateArray();
    for (int i = 0; i < programmerListSize; i++) {
        cJSON * jProgrammer = _programmer_serializeJSON(programmerList + i);
        cJSON_AddItemToArray(jArr, jProgrammer);
    }
    const char * jsonString = cJSON_Print(jArr);
	cJSON_Delete(jArr);
    return jsonString;
}


