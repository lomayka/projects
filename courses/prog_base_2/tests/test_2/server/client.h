#include <winsock2.h>
#include <windows.h>

#define NO_FLAGS_SET 0
#define PORT 80
#define MAXBUFLEN 20480

SOCKET new_Socket();
void Connect(SOCKADDR_IN,SOCKET);
void sendFirstRequest(SOCKET recvSocket,const char * host_name);
void Recieve(SOCKET recvSocket, char * buffer );
SOCKADDR_IN setSocAddr(char * ip);
