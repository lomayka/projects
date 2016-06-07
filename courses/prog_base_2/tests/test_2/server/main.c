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
#include "list.h"
#include "db_manager.h"
#include "files.h"

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
              list_t * list = list_new();
              const char * dbFile = "programmers.db";
              db_t * db = db_new(dbFile);
              db_getProgrammers(db,list);

char homeBuf[10240];
    char text[5000];
    strcpy(text,"[\n");
    for (int i = 0; i < list_getSize(list); i++)
    {
        strcat(text,programmer_toJSON(list_getByID(list,i)));
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
        else if (strcmp(rs.method,"GET") == 0 && strncmp(rs.uri, "/files/", 7) == 0)
        {
            char * part = strstr(rs.uri, "/files/");
            char path[200];
            part+=7;
            strcat(path,"C:\\Progs\\OP\\projects\\courses\\prog_base_2\\labs\\lab4\\files\\");
            strcat(path,part);
            if (file_exists(path))
            {
                printf("OD");
              char name[30];
              strcpy(name,part);

              int size = file_getSize(path);

              time_t time = file_getCreateTime(path);

    cJSON * jFile = cJSON_CreateObject();
    cJSON_AddItemToObject(jFile, "name", cJSON_CreateString(name));
    cJSON_AddItemToObject(jFile, "size", cJSON_CreateNumber(size));
    char * t = ctime(&time);
    t[strlen(t)-1] = '\0';
    cJSON_AddItemToObject(jFile, "time", cJSON_CreateString(t));
    char * jsonString = cJSON_Print(jFile);
    server_external(client,jsonString);




            }
            else {
            server_external(client,"{\n\"Status\": \"Error\",\n\"Reason\":\"File not exist\"\n}");
            }
            server_info(client);
        }
        else
        {
            server_notFound(client);
        }

        }
    }
    return 0;
}
