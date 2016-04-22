#include <stddef.h>
#include <stdio.h>
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

     //req.form = malloc(1000*sizeof(char));
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
        printf("%s",kv.key);
        // get value
        eqPtr++;
        ptrdiff_t valueLen = pairEndPtr - eqPtr;
        memcpy(kv.value, eqPtr, valueLen);
        kv.value[valueLen] = '\0';
        printf("%s",kv.value);
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

void server_send_jSON_status(socket_t * client,int st){ // 0 - success 1 - wrong index
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
        printf("%s",st.name);
       // st.surname = http_request_getArg(&rs, "surname");
        //st.year = atoi(http_request_getArg(&rs, "year"));
       // const char * jSt = programmer_toJSON(&st);
        //printf("New student:\n%s\n", jSt);
     /*   sprintf(strbuf,
            "HTTP/1.1 200 OK\n"
            "Content-Type: application/json\n"
            "Content-Length: %zu\n"
            "Connection: keep-alive\n"
            "\n%s", strlen(jSt), jSt);*/
      //  free(jSt);
        }

}


