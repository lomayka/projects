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

