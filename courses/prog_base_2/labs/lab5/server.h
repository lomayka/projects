#include "socket.h"
#include "cJSON.h"

typedef struct {
    char key[256];
    char value[256];
} keyvalue_t;

typedef struct {
    char method[20];
    char uri[256];
    keyvalue_t * form;
    int formLength;

}

http_request_t;
http_request_t http_request_parse(const char * const request);

char *
http_request_getArg(http_request_t  self, const char * key);
