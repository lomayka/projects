#ifndef HTTP_H_INCLUDED
#define HTTP_H_INCLUDED
#include "socket.h"
typedef struct {
    char method[8];
    char uri[256];
} http_request_t;

http_request_t http_request_parse(const char * const request);
void server_homepage(socket_t * client, char * text);
void server_notFound(socket_t * client);

#endif // HTTP_H_INCLUDED
