#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <windows.h>
#include <conio.h>
#include "server.h"
#include "socket.h"
#include "db_manager.h"

int main()
{
    lib_init();
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
            db_t * db = db_new("programmers.db");
            server_send(client,db_getProgrammers(db));
        }
         else if (strcmp(rs.method,"GET") == 0 && strcmp(rs.uri, "/programmers") == 0 )
        {
            db_t * db = db_new("programmers.db");
            socket_write_string(client, textToBuffer_HTML(db_getProgrammers_HTML(db)));
            socket_close(client);
        }
        else if (strcmp(rs.method,"GET") == 0 && strncmp(rs.uri, "/api/programmers/", 17) == 0 )
        {
            db_t * db = db_new("programmers.db");
            char * part = strstr(rs.uri, "/api/programmers/");
            part = part + 17; // move pointer to get number
            int index = atoi(part);
            if (index > 0) {
            server_send(client,db_getProgrammerById(db,index));
            }
            else server_send(client,"{\"Status\": \"Error\",\n\"Reason:\" \"Wrong index\"}");
        }
        else if (strcmp(rs.method,"GET") == 0 && strncmp(rs.uri, "/programmers/", 13) == 0 )
        {
            db_t * db = db_new("programmers.db");
            char * part = strstr(rs.uri, "/programmers/");
            part = part + 13; // move pointer to get number
            int index = atoi(part);
            if (index > 0) {
            socket_write_string(client, textToBuffer_HTML(db_getProgrammerById_HTML(db,index)));
            socket_close(client);
            }
            else server_send(client,"{\"Status\": \"Error\",\n\"Reason:\" \"Wrong index\"}");
        }
        else if (strcmp(rs.method,"DELETE") == 0 && strncmp(rs.uri, "/programmers/", 13) == 0)
        {
            db_t * db = db_new("programmers.db");
            char * part = strstr(rs.uri, "/programmers/");
            part = part + 13; // move pointer to get number
            int index = atoi(part);
            if (index > 0) {
            db_deleteProgrammer(db,index);
            }
        }
        else if (strcmp(rs.method,"DELETE") == 0 && strncmp(rs.uri, "/api/programmers/", 17) == 0)
        {
            db_t * db = db_new("programmers.db");
            char * part = strstr(rs.uri, "/api/programmers/");
            part = part + 17; // move pointer to get number
            int index = atoi(part);
            if (index > 0) {
            db_deleteProgrammer(db,index);
            }
        }
        else if (strcmp(rs.method,"GET") == 0 && strcmp(rs.uri, "/new-programmer") == 0)
        {
           server_programmers_returnPOST(client,rs);
        }
        else if (strcmp(rs.method,"POST") == 0 && strcmp(rs.uri, "/programmers") == 0)
        {
           db_t * db = db_new("programmers.db");
           server_programmers_insert(client,rs,db);
        }
        else if (strcmp(rs.method,"POST") == 0 && strcmp(rs.uri, "/api/programmers") == 0)
        {
           db_t * db = db_new("programmers.db");
           server_programmers_insert(client,rs,db);
        }
        else if (strcmp(rs.method,"GET") == 0 && strncmp(rs.uri, "/api/programmers?", 17) == 0 )
        {
           db_t * db = db_new("programmers.db");
           char * part = strstr(rs.uri, "/api/programmers?");
           part = part + 17;
           char * str = strtok(part,"&");
           char * exp = strtok(NULL,"\n");
           str = strstr(str,"=");
           str += 1; // language
           exp = strstr(exp,"%");
           exp += 1;
           //printf("%s",exp);
           char * test = malloc(sizeof(char) * 10000);
           test[0] = '\0';
           if (exp[0] == '3' && exp[1] == 'E'){
                exp += 2;
                int e = atoi(exp);
                const char * sqlQuery = "SELECT * FROM Programmers WHERE Year > ? AND Language = ?;";
                test = db_getProgrammersTask(db,e,str,sqlQuery);
           }
           else if (exp[0] == '3' && exp[1] == 'C'){
                exp += 2;
                int e = atoi(exp);
                const char * sqlQuery = "SELECT * FROM Programmers WHERE Year < ? AND Language = ?;";
                test = db_getProgrammersTask(db,e,str,sqlQuery);
           }
           socket_write_string(client, textToBuffer_HTML(test));
           socket_close(client);


         free(test);
        }



        }



    }

    return 0;
}
