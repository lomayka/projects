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

char *
http_request_getArg(http_request_t  self, const char * key)
{
    for (int i = 0; i < self.formLength; i++)
    {
        if (strcmp(self.form[i].key, key) == 0)
        {
            return self.form[i].value;
        }
    }
    return NULL;
}

void server_programmers(socket_t * client, http_request_t rs, list_t * list)
{
    char homeBuf[10240];
    char text[5000];
    strcpy(text,"[\n");
    for (int i = 0; i < list_getSize(list); i++)
    {
        strcat(text,programmer_toJSON(list_getById(list,i)));
        strcat(text,",\n");
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
    else server_wrongIndex(client);

}

void server_wrongIndex(socket_t * client)
{
    char homeBuf[1024];
    const char * pageText = "{"
                            "\n\"Status:\" error\n"
                            "\"Reason\":wrong index\n"
                            "}";

    sprintf(homeBuf,
            "HTTP/1.1 404 \n"
            "Content-Type: text/html/application/json\n"
            "Content-Length: %zu\n"
            "\n%s", strlen(pageText), pageText);
    socket_write(client, homeBuf,sizeof(homeBuf));
    socket_close(client);

}

void server_programmers_insert(socket_t * client, http_request_t rs,list_t * list)
{
    programmer_t * programmer = programmer_new();
    programmer_set(programmer,http_request_getArg(rs, "name"),http_request_getArg(rs, "surname"),http_request_getArg(rs, "company"),http_request_getArg(rs, "language"),atof(http_request_getArg(rs, "rating")),atoi(http_request_getArg(rs, "year")),http_request_getArg(rs, "date"));
    if (data_check(programmer)) list_add(list,programmer);
    const char * pageText =  "HTTP/1.1 200 \n"
                             "Content-Type: text/html/application/json\n";
    socket_write((socket_t *)client, pageText,sizeof(pageText));
    socket_close((socket_t *)client);

}

void server_startPage(socket_t *client)
{
    char homeBuf[1024];
    const char * pageText = "Welcome user";
    sprintf(homeBuf,
            "HTTP/1.1 404 \n"
            "Content-Type: text/html/application/json\n"
            "Content-Length: %zu\n"
            "\n%s", strlen(pageText), pageText);
    socket_write((socket_t *)client, homeBuf,sizeof(homeBuf));
    socket_close((socket_t *)client);
}

int data_check(programmer_t * st)
{
    char * str;
    char st_data[25];
    strcpy(st_data,programmer_getDate(st));
    if (strlen(programmer_getName(st)) == 0 || strlen(programmer_getSurname(st)) == 0 || strlen(programmer_getDate(st)) != 10 || strlen(programmer_getName(st)) > 25 || strlen(programmer_getSurname(st)) > 25  || strlen(programmer_getCompany(st)) == 0|| strlen(programmer_getCompany(st)) > 25 ) return 0;
    if (programmer_getName(st)== NULL || programmer_getSurname(st) == NULL || programmer_getDate(st) == NULL || programmer_getCompany(st) == NULL) return 0;
    str = strtok(st_data,"-");
    if (strlen(str) != 4 || atoi(str) < 1 || atoi(str) > 2016 ) return 0;
    str = strtok(NULL,"-");
    if (strlen(str) != 2 || atoi(str) < 1 || atoi(str) > 12) return 0;
    str = strtok(NULL,"\0");
    if (strlen(str) != 2 || atoi(str) < 1 || atoi(str) > 31 ) return 0;
    if (programmer_getRating(st) < 0.0 || programmer_getRating(st) > 10.0) return 0;
    if (programmer_getYear(st)<= 0 || programmer_getYear(st)  > 2016) return 0;
    return 1;
}

char * textToBuffer_HTML(char * text)
{
    char * buffer = malloc(sizeof(char) * 10240);

    sprintf(buffer,
            "HTTP/1.1 200 OK\n"
            "Content-Type: text/html\n"
            "Content-Length: %zu\n"
            "\n%s", strlen(text), text);

    return buffer;
}

void server_homepage(socket_t * client)
{
    char buffer[1024] = "";
    char * pageText =
        "<h1>Hello, world of web!</h1>"
        "<a href=\"http://127.0.0.1:5000/programmers\">All programmers</a>";

    strcat(buffer, textToBuffer_HTML(pageText));

    socket_write_string(client, pageText);
    socket_close(client);
}



void server_programmers_delete_api(socket_t * client, http_request_t rs,list_t * list)
{
    char homeBuf[1024];
    char * part = strstr(rs.uri, "/api/programmers/");
    part = part + 17; // move pointer to get number
    int index = atoi(part);
    if( index > 0 && index <= list_getSize(list))
    {

        char * pageText = programmer_toJSON(list_delete(list,index-1));

        sprintf(homeBuf,
                "HTTP/1.1 404 \n"
                "Content-Type: text/html/application/json\n"
                "Content-Length: %zu\n"
                "\n%s", strlen(pageText), pageText);
        socket_write(client, homeBuf,sizeof(homeBuf));
        socket_close(client);

    }

}

void server_HTMLerror(socket_t * client)
{
    char buffer[1024] = "";
    char * pageText =
        "<h1>Wrong index</h1>";
    strcat(buffer, textToBuffer_HTML(pageText));

    socket_write_string(client, pageText);
    socket_close(client);
}

void server_programmers_delete(socket_t * client, http_request_t rs,list_t * list)
{
    char * part = strstr(rs.uri, "/programmers/");
    part = part + 13; // move pointer to get number
    int index = atoi(part);
    puts(part);
    if( index >= 0 && index <= list_getSize(list))
    {

        char pageText[1024] = "";
        strcat(pageText, programmer_toHTML(list_delete(list,index),index));
        //strcat(buffer, textToBuffer_HTML(pageText));

        //socket_write(client, buffer,sizeof(buffer));
        socket_close(client);

    }

}

void server_programmers_HTML_GETbyID(socket_t * client, http_request_t rs,list_t * list)
{
    char buffer[10240] = "";

    char * point = strstr(rs.uri, "/programmers/");
    point += 13;
    int index = atoi(point);

    if(index > 0 && index <= list_getSize(list))
    {

        char pageText[1024] = "";
        strcat(pageText, (char *)programmer_toHTML(list_getById(list,index-1),index-1));
        strcat(buffer, textToBuffer_HTML(pageText));
        socket_write_string(client, buffer);
        socket_close(client);


    }
    else
    {
        server_HTMLerror(client);
    }
}

void server_programmers_HTML(socket_t * client, http_request_t rs,list_t * list)
{
    char buffer[10240] = "";
    char pageText[1024] = "";
    for (int i = 0; i < list_getSize(list); i++)
    {
        sprintf(pageText, "<a href=\"http://127.0.0.1:5000/programmers/%i\">%s %s<br></a>\n", i+1, programmer_getSurname(list_getById(list,i)), programmer_getName(list_getById(list,i)));
        strcat(buffer, pageText);
    }
    socket_write_string(client, buffer);
    socket_close(client);
}

void server_programmers_returnPOST(socket_t * client, http_request_t rs,list_t * list)
{
    char buffer[10240] = "";
    char * pageText =
        "<form action=\"http://127.0.0.1:5000/programmers\" method=\"POST\">"
        "Name:<br>"
        "<input type=\"text\" name=\"name\" value='Ivan'><br>"
        "Surname:<br>"
        "<input type=\"text\" name=\"surname\" value='Ivanov'><br>"
        "Company:<br>"
        "<input type=\"text\" name=\"company\" value='Oracle'><br>"
        "Language:<br>"
        "<input type=\"text\" name=\"language\" value='C'><br>"
        "Year:<br>"
        "<input type=\"text\" name=\"year\" value='2010'><br>"
        "Rating:<br>"
        "<input type=\"text\" name=\"rating\" value='7.3'><br><br>"
        "Date:<br>"
        "<input type=\"text\" name=\"date\" value='1950-05-04'><br>"
        "<input type=\"submit\" value='Send POST request' />"
        "</form>";

    char * textHTML = textToBuffer_HTML(pageText);
    strcat(buffer, textHTML);
    socket_write_string(client, buffer);
    socket_close(client);

}
