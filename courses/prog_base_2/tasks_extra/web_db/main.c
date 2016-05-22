#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "server.h"



int main()
{
    lib_init();
    socket_t * server = socket_new();
    socket_bind(server, 5000);
    socket_listen(server);

    char buf[10000];
    char pathBuf[256];
    socket_t * client = NULL;
    while(1)
    {
        client = socket_accept(server);
        socket_read(client, buf, sizeof(buf));
        http_request_t rs;
        rs = http_request_parse(buf);
        server_reply(client,rs);

    }
    socket_free(server);
    socket_free(client);
    lib_free();
    return 0;
}
