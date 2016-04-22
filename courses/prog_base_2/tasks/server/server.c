<<<<<<< HEAD
#include <stddef.h>
#include "server.h"
http_request_t http_request_parse(const char * const request) {
    http_request_t req;
    // get method
    ptrdiff_t methodLen = strstr(request, " ") - request;  // find first whitespace
    memcpy(req.method, request, methodLen);
    req.method[methodLen] = '\0';
    // get uri
    const char * uriStartPtr = request + strlen(req.method) + 1;
    const char * uriEndPtr = strstr(uriStartPtr, " ");  // find second whitespace
    ptrdiff_t uriLen = uriEndPtr - uriStartPtr;
    memcpy(req.uri, uriStartPtr, uriLen);
    req.uri[uriLen] = '\0';
    return req;
}



void server_homepage(socket_t * client,char * text) {
    const char * pageText = "Hello, world of web!";
    char homeBuf[1024];
    sprintf(homeBuf,
        "HTTP/1.1 200 OK\n"
        "Content-Type: text/html\n"
        "Content-Length: %zu\n"
        "\n%s", strlen(text), text);
    socket_write_string(client, homeBuf);
    socket_close(client);
}


void server_notFound(socket_t * client) {
    char homeBuf[10240];
    const char * pageText = "404 Page Not Found!";
    sprintf(homeBuf,
        "HTTP/1.1 404 \n"
        "Content-Type: text/html\n"
        "Content-Length: %zu\n"
        "\n%s", strlen(pageText), pageText);
    socket_write(client, homeBuf,sizeof(homeBuf));
    socket_close(client);
}

=======
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "server.h"
#include "cJSON.h"
#include "programmers.h"


http_request_t http_request_parse(const char * const request) {
    http_request_t req;
    // get method
    ptrdiff_t methodLen = strstr(request, " ") - request;  // find first whitespace
    memcpy(req.method, request, methodLen);
    req.method[methodLen] = '\0';
    // get uri
    const char * uriStartPtr = request + strlen(req.method) + 1;
    const char * uriEndPtr = strstr(uriStartPtr, " ");  // find second whitespace
    ptrdiff_t uriLen = uriEndPtr - uriStartPtr;
    memcpy(req.uri, uriStartPtr, uriLen);
    req.uri[uriLen] = '\0';

     req.form = malloc(sizeof(keyvalue_t));
    const char * bodyStartPtr = strstr(request, "\r\n\r\n") + strlen("\r\n\r\n");
    const char * cur = bodyStartPtr;
    const char * pairEndPtr = cur;
    const char * eqPtr = cur;
    while (strlen(cur) > 0) {
        pairEndPtr = strchr(cur, '&');
        if (NULL == pairEndPtr) {
            pairEndPtr = cur + strlen(cur);
        }
        keyvalue_t kv;
        // get key
        eqPtr = strchr(cur, '=');
        ptrdiff_t keyLen = eqPtr - cur;
        memcpy(kv.key, cur, keyLen);
        kv.key[keyLen] = '\0';
        // get value
        eqPtr++;
        ptrdiff_t valueLen = pairEndPtr - eqPtr;
        memcpy(kv.value, eqPtr, valueLen);
        kv.value[valueLen] = '\0';
        // insert key-value pair into request form list
        req.formLength += 1;
        req.form = realloc(req.form, sizeof(keyvalue_t) * req.formLength);
        req.form[req.formLength - 1] = kv;
        cur = pairEndPtr + ((strlen(pairEndPtr) > 0) ? 1 : 0);
    }
    return req;
}

void server_students(socket_t * client) {
cJSON * jText = open_JSON("Programmers.json");
server_send_JSON(client,jText);
}

void server_student_id(socket_t * client, int id){
cJSON * jText = open_JSON("Programmers.json");
cJSON * jId = cJSON_GetArrayItem(jText,id-1);
server_send_JSON(client,jId);
}

void server_delete_id(socket_t * client, int id){
cJSON * jText = open_JSON("Programmers.json");
int size = cJSON_GetArraySize(jText);
if (id <= size ){
cJSON_DeleteItemFromArray(jText,id-1);
server_send_jSON_status(client,0);
}
else server_send_jSON_status(client,1);
}

void server_insert_id(socket_t * client,cJSON * jNew, int id){
cJSON * jText = open_JSON("Programmers.json");
cJSON_ReplaceItemInArray(jText,id-1,jNew);
server_send_JSON(client,jNew);

}

void server_send_jSON_status(socket_t * client,int st){ // 0 - success 1 - wrong
cJSON * status = open_JSON("status.json");
cJSON * status_item = cJSON_GetArrayItem(status,st);
server_send_JSON(client,status_item);
}

cJSON * open_JSON(char * name){
char * text = malloc(10000*sizeof(char));
FILE * fr = fopen(name, "r");
fread(text,1,10000,fr);
cJSON * jText = cJSON_Parse(text);
free(text);
return jText;
}

void server_send_JSON(socket_t * client,cJSON * jText){
    char homeBuf[15000];
    char * text = malloc(10000*sizeof(char));
    text = cJSON_Print(jText);

    sprintf(homeBuf,
        "HTTP/1.1 200 OK\n"
        "Content-Type: text/html/application/json\n"
        "Content-Length: %zu\n"
        "\n%s", strlen(text), text);
    socket_write_string(client, homeBuf);
    socket_close(client);
    free(text);

}

const char *
http_request_getArg(http_request_t  self, const char * key) {
    for (int i = 0; i < self.formLength; i++) {
        if (strcmp(self.form[i].key, key) == 0) {
            return self.form[i].value;
        }
    }
    return NULL;
}



void server_notFound(socket_t * client) {
    char homeBuf[1024];
    const char * pageText = "404 Page Not Found!";
    sprintf(homeBuf,
        "HTTP/1.1 404 \n"
        "Content-Type: text/html/application/json\n"
        "Content-Length: %zu\n"
        "\n%s", strlen(pageText), pageText);
    socket_write(client, homeBuf,sizeof(homeBuf));
    socket_close(client);
}

int data_check(programmer_t * st){
char * str;
char st_data[25];
strcpy(st_data,st->data_birth);
if (strlen(st->name) == 0 || strlen(st->surname) == 0 || strlen(st->data_birth) != 10 || strlen(st->name) > 25 || strlen(st->surname) > 25  || strlen(st->company.name) == 0|| strlen(st->company.name) > 25 || strlen(st->company.position) == 0 || strlen(st->company.position) > 25 ) return 0;
if (st->name == NULL || st->surname == NULL || st->data_birth == NULL || st->company.name == NULL || st->company.position == NULL) return 0;
str = strtok(st_data,"-");
if (strlen(str) != 4 || atoi(str) < 1 || atoi(str) > 2016 ) return 0;
str = strtok(NULL,"-");
if (strlen(str) != 2 || atoi(str) < 1 || atoi(str) > 12) return 0;
str = strtok(NULL,"\0");
if (strlen(str) != 2 || atoi(str) < 1 || atoi(str) > 31 ) return 0;
if (st->rating < 0.0 || st->rating > 10.0) return 0;
if (st->year <= 0 || st->year > 2016) return 0;
}

void server_reply(socket_t * client, http_request_t rs){
 if (strcmp(rs.method,"GET") == 0)
        {
            if (strcmp(rs.uri, "/students") == 0)
            {
                server_students(client);
            }
            else
            {
                char * startPtr = rs.uri;
                char * endPtr = strstr(rs.uri,"/students");
                if (endPtr == NULL)
                {
                    return;
                }
                ptrdiff_t len = startPtr - endPtr;
                if (len == 0)
                {
                    char numb = endPtr[10];
                    if ((numb - 48 == 1 || numb - 48 == 2 || numb - 48 == 3) && endPtr[11] == '\0')
                    {
                        server_student_id(client,numb-48);
                    }
                    else
                    {
                        server_notFound(client);

                    }


                }
                else
                {
                    server_notFound(client);
                }
            }


        }
        else if (strcmp(rs.method,"DELETE") == 0){
              char * startPtr = rs.uri;
                char * endPtr = strstr(rs.uri,"/students");
                if (endPtr == NULL)
                {
                   server_send_jSON_status(client,1);
                   return;
                }
                ptrdiff_t len = startPtr - endPtr;
                if (len == 0)
                {
                    char numb = endPtr[10];
                    if ((numb - 48 == 1 || numb - 48 == 2 || numb - 48 == 3) && endPtr[11] == '\0')
                    {
                        server_delete_id(client,numb-48);
                    }
                    else
                    {
                        server_send_jSON_status(client,1);
                    }


                }
                else
                {
                    server_send_jSON_status(client,1);
                }




        }
        else if (strcmp(rs.method,"POST") == 0){
        char strbuf[15000];
        programmer_t st = programmer_empty();
        st.name = http_request_getArg(rs, "name");
        st.surname = http_request_getArg(rs, "surname");
        st.company.name = http_request_getArg(rs, "company_name");
        st.company.position = http_request_getArg(rs, "position");
        st.year = atoi(http_request_getArg(rs, "year"));
        st.data_birth = http_request_getArg(rs, "birthdate");
        if (0 == data_check(&st)){
        server_send_jSON_status(client,2);
        return;
        }
        char * rating = http_request_getArg(rs, "rating");
        st.rating = atof(rating);
        const char * jSt = programmer_toJSON(&st);
        cJSON * jText = cJSON_Parse(jSt);

         char * startPtr = rs.uri;
                char * endPtr = strstr(rs.uri,"/students");
                if (endPtr == NULL)
                {
                   server_notFound(client);
                   return;
                }
                ptrdiff_t len = startPtr - endPtr;
                if (len == 0)
                {
                    char numb = endPtr[10];
                    if ((numb - 48 == 1 || numb - 48 == 2 || numb - 48 == 3) && endPtr[11] == '\0')
                    {
                        server_insert_id(client,jText,numb-48);
                    }
                    else
                    {
                       server_notFound(client);
                    }


                }
                else
                {
                   server_notFound(client);
                }
                free(jSt);
        }

}


>>>>>>> 4560f3ffce451268562c52d1c10c1bd29c7a5084
