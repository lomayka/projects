#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <windows.h>
#include <time.h>
#include "socket.h"
#include "server.h"
#include "client.h"
#include "quote.h"
#include "jSON_parce.h"

#define NO_FLAGS_SET 0
#define PORT 80
#define MAXBUFLEN 20480

int main()
{
    lib_init();
    socket_t * server = socket_new();
    socket_bind(server, 5000);
    socket_listen(server);
    char buf[10000];
    socket_t * client = NULL;
    WSADATA Data;
    SOCKADDR_IN recvSockAddr;
    SOCKET recvSocket;
    int status;
    struct hostent * remoteHost;
    char * ip;
    const char * host_name = "pb-homework.appspot.com";
    char buffer[MAXBUFLEN];
    memset(buffer,0,MAXBUFLEN);
    status = WSAStartup(MAKEWORD(2, 2), &Data);
    if(status != 0)
    {
        printf("ERROR: WSAStartup unsuccessful\r\n");
        return 0;
    }
    remoteHost = gethostbyname(host_name);
    ip = inet_ntoa(*(struct in_addr *)*remoteHost->h_addr_list);

    recvSockAddr = setSocAddr(ip);




    while(1)
    {
        client = socket_accept(server);
        socket_read(client, buf, sizeof(buf));
        printf("%s",buf);
        if (strlen(buf) != 0)
        {
            http_request_t rs;
            rs = http_request_parse(buf);
            if (strcmp(rs.method,"GET") == 0 && strcmp(rs.uri, "/info") == 0 )
            {
                server_info(client);
            }
            else if (strcmp(rs.method,"GET") == 0 && strcmp(rs.uri, "/external") == 0 )
            {
                recvSocket = new_Socket();

                Connect(recvSockAddr,recvSocket);

                sendFirstRequest(recvSocket,host_name);

                Recieve(recvSocket,buffer);
                quote_t * quote = quote_new();
                parse(buffer,quote);
                char * str = quote_toJSON(quote);
                server_external(client,str);
            }
            else if (strcmp(rs.method,"GET") == 0 && strcmp(rs.uri, "/database") == 0 )
            {

            }

        }
    }
    return 0;
}
