#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "cJSON.h"
#include "quote.h"

void parse(char * text,  quote_t * quote)
{
    char * text_part = strstr(text,"{");
	cJSON * jList = cJSON_Parse(text_part);
	if (!jList) {
		printf("Error before: [%s]\n", cJSON_GetErrorPtr());

	}

    quote_set(quote,cJSON_GetObjectItem(jList, "author")->valuestring,cJSON_GetObjectItem(jList, "quote")->valuestring);

    cJSON_Delete(jList);

}
