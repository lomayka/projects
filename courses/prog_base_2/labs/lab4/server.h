#include "socket.h"
#include "cJSON.h"
#include "List.h"



typedef struct {
    char key[256];
    char value[256];
} keyvalue_t;

typedef struct {
    char method[20];
    char uri[256];
    keyvalue_t * form;
    int formLength;

} http_request_t;
http_request_t http_request_parse(const char * const request);
void server_notFound(socket_t * client);
cJSON * open_JSON(char * name);
void server_send_JSON(socket_t * client,cJSON * jText);
void server_programmers_returnPOST(socket_t * client, http_request_t rs,list_t * list);
int data_check(programmer_t * st);
char * textToBuffer_HTML(char * text);
void server_homepage(socket_t * client);
void server_programmers_delete_api(socket_t * client, http_request_t rs,list_t * list);
void server_programmers_delete(socket_t * client, http_request_t rs,list_t * list);
void server_programmers_HTML_GETbyID(socket_t * client, http_request_t rs,list_t * list);
void server_programmers_HTML(socket_t * client, http_request_t rs,list_t * list);
void server_programmers_returnPOST(socket_t * client, http_request_t rs,list_t * list);
void server_wrongIndex(socket_t * client);
void server_HTMLerror(socket_t * client);
void server_programmer_byID(socket_t * client, http_request_t rs,list_t * list);
void server_notFound(socket_t * client);
void server_programmers(socket_t * client, http_request_t rs, list_t * list);
char *
http_request_getArg(http_request_t  self, const char * key);
void server_programmers_insert(socket_t * client, http_request_t rs,list_t * list);
