<<<<<<< HEAD
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
=======
#include "socket.h"
#include "cJSON.h"

typedef struct {
    char key[256];
    char value[256];
} keyvalue_t;

typedef struct {
    char method[8];
    char uri[256];
    keyvalue_t * form;
    int formLength;

} http_request_t;
http_request_t http_request_parse(const char * const request);
void server_students(socket_t * client);
void server_notFound(socket_t * client);
cJSON * open_JSON(char * name);
void server_send_JSON(socket_t * client,cJSON * jText);
>>>>>>> 4560f3ffce451268562c52d1c10c1bd29c7a5084
