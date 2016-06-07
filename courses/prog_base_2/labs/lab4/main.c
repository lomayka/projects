#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <windows.h>
#include <conio.h>
#include "List.h"
#include "server.h"
#include "programmer.h"



int main()
{
    lib_init();
    list_t * list = list_new();
    programmer_t * programmer[10];
    for (int i = 0; i < 10; i++){
     programmer[i] = programmer_new();
    }
     programmer_set(programmer[0],"John","McGill","IBM","Java",9.1,2014,"2015-05-16");
     programmer_set(programmer[1],"James","Wayne","Microsofr","C++",9.0,2015,"2015-08-19");
     programmer_set(programmer[2],"Robert","Loyton","Oracle","Java",9.2,2014,"2015-06-12");
    list_add(list,programmer[0]);
    list_add(list,programmer[1]);
    list_add(list,programmer[2]);
    //printf("%s",programmer_toJSON(list_getById(list,0)));
    socket_t * server = socket_new();
    socket_bind(server, 5000);
    socket_listen(server);


    char buf[10000];
    socket_t * client = NULL;
    while(1)
    {
        client = socket_accept(server);
        socket_read(client, buf, sizeof(buf));
        if (strlen(buf) != 0){
        http_request_t rs;
        rs = http_request_parse(buf);

        if (strcmp(rs.method,"GET") == 0 && strcmp(rs.uri, "/") == 0 )
        {
            server_homepage(client);
        }
        else if (strcmp(rs.method,"GET") == 0 && strcmp(rs.uri, "/api/programmers") == 0 )
        {
            server_programmers(client, rs,list);
        }
        else if (strcmp(rs.method,"GET") == 0 && strncmp(rs.uri, "/api/programmers/", 17) == 0)
        {
             server_programmer_byID(client,rs,list);
        }
        else if (strcmp(rs.method,"POST") == 0 && strcmp(rs.uri, "/api/programmers") == 0)
        {

             server_programmers_insert(client,rs,list);
        }
        else if(strcmp(rs.method,"GET") == 0 && strncmp(rs.uri, "/api/programmers/", 17) == 0){
            server_programmers_delete(client,rs,list);
        }
        else if(strcmp(rs.method,"GET") == 0 && strncmp(rs.uri, "/programmers/", 13) == 0){
            server_programmers_HTML_GETbyID(client,rs,list);
        }
        else if (strcmp(rs.method,"GET") == 0 && strcmp(rs.uri, "/programmers") == 0){
            server_programmers_HTML(client,rs,list);
        }
        else if (strcmp(rs.method,"GET") == 0 && strcmp(rs.uri, "/new-programmer") == 0)
        {
           server_programmers_returnPOST(client,rs,list);
        }
         else if (strcmp(rs.method,"POST") == 0 && strcmp(rs.uri, "/programmers") == 0)
        {
           server_programmers_insert(client,rs,list);
        }
        else if (strcmp(rs.method,"DELETE") == 0 && strncmp(rs.uri, "/programmers/", 13) == 0)
        {
           server_programmers_delete(client,rs,list);
        }
        else server_notFound(client);

        }
    }
    socket_free(server);
    socket_free(client);
    lib_free();

    getch();

    return 0;
}
