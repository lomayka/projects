#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "server.h"
#include "cJSON.h"
#include "programmer.h"
#include "List.h"



http_request_t http_request_parse(const char * const request)
{
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
    while (strlen(cur) > 0)
    {
        pairEndPtr = strchr(cur, '&');
        if (NULL == pairEndPtr)
        {
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

const char *
http_request_getArg(http_request_t  self, const char * key) {
    for (int i = 0; i < self.formLength; i++) {
        if (strcmp(self.form[i].key, key) == 0) {
            return self.form[i].value;
        }
    }
    return NULL;
}

void server_programmers(socket_t * client, http_request_t rs, list_t * list)
{
  char homeBuf[1024];
  char text[500];
  strcpy(text,"[\n");
  for (int i = 0; i < list_getSize(list); i++){
    strcat(text,programmer_toJSON(list_getById(list,i)));
    strcat(text,"\n");
  }
 strcat(text,"]\n");
  sprintf(homeBuf,
                    "HTTP/1.1 404 \n"
                    "Content-Type: text/html/application/json\n"
                    "Content-Length: %zu\n"
                    "\n%s", strlen(text), text);
            socket_write(client, homeBuf,sizeof(homeBuf));
            socket_close(client);
}




void server_notFound(socket_t * client)
{
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

void server_programmer_byID(socket_t * client, http_request_t rs,list_t * list)
{
    char homeBuf[1024];

        char * part = strstr(rs.uri, "/api/programmers/");
        part = part + 17; // move pointer to get number
        int index = atoi(part);
         printf("%d", index);
        if( index > 0 && index <= list_getSize(list))
        {
            char * pageText = programmer_toJSON(list_getById(list,index-1));
            sprintf(homeBuf,
                    "HTTP/1.1 404 \n"
                    "Content-Type: text/html/application/json\n"
                    "Content-Length: %zu\n"
                    "\n%s", strlen(pageText), pageText);
            socket_write(client, homeBuf,sizeof(homeBuf));
            socket_close(client);

        }
        else server_notFound(client);

}

void server_programmers_insert(socket_t * client, http_request_t rs,list_t * list)
{
programmer_t * programmer = programmer_new();
programmer_set(programmer,http_request_getArg(rs, "name"),http_request_getArg(rs, "surname"),"test","test",9.0);
list_add(list,programmer);
}


