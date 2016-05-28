#include <winsock2.h>
#include <windows.h>
#include <stdio.h>

#define NO_FLAGS_SET 0
#define PORT 80
#define MAXBUFLEN 20480

SOCKET new_Socket(){            // to create new socet
SOCKET recvSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(recvSocket == INVALID_SOCKET)
	{
		printf("ERROR: socket unsuccessful\r\n");
		system("pause");
	}

return recvSocket;
}

void Connect (SOCKADDR_IN recvSockAddr, SOCKET recvSocket){
 if(connect(recvSocket,(SOCKADDR*)&recvSockAddr,sizeof(SOCKADDR_IN)) == SOCKET_ERROR)
    {
        printf("ERROR: socket could not connect\r\n");
        closesocket(recvSocket);
        WSACleanup();
    }
}

void sendFirstRequest(SOCKET recvSocket,const char * host_name){
    char request[200];
    sprintf(request, "GET /test/var/7?format=json HTTP/1.1\r\nHost:%s\r\n\r\n", host_name);  // add Host header with host_name value
    send(recvSocket, request, strlen(request), 0);


}

void Recieve(SOCKET recvSocket, char * buffer ){
 int numrcv = 0, status;
 numrcv = recv(recvSocket, buffer, MAXBUFLEN, NO_FLAGS_SET);
       if (numrcv == SOCKET_ERROR)
    {
        printf("ERROR: recvfrom unsuccessful\r\n");
        status = closesocket(recvSocket);
        if(status == SOCKET_ERROR)
			printf("ERROR: closesocket unsuccessful\r\n");
        status = WSACleanup();
        if (status == SOCKET_ERROR)
			printf("ERROR: WSACleanup unsuccessful\r\n");
        system("pause");
    }

}

SOCKADDR_IN setSocAddr(char * ip){
    SOCKADDR_IN recvSockAddr;
    memset(&recvSockAddr, 0, sizeof(recvSockAddr));
    recvSockAddr.sin_port=htons(PORT); // specify the port portion of the address
    recvSockAddr.sin_family=AF_INET; // specify the address family as Internet
    recvSockAddr.sin_addr.s_addr= inet_addr(ip); // specify ip address
    return recvSockAddr;
}
