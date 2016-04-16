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
