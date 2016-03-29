#include <winsock2.h>
#include <windows.h>

#pragma comment(lib, "ws2_32.lib")

#define NO_FLAGS_SET 0
#define PORT 80
#define MAXBUFLEN 20480 // How much is printed out to the screen

SOCKET new_Socket();
void Connect(SOCKADDR_IN,SOCKET);
void sendFirstRequest(SOCKET recvSocket,const char * host_name);
void Recieve(SOCKET recvSocket, char * buffer );
SOCKADDR_IN setSocAddr(char * ip);
char *findMax(char *);
void finalSend(SOCKET recvSocket, char* host_name, char * string);

int main(void) {
    WSADATA Data;
    SOCKADDR_IN recvSockAddr;
    SOCKET recvSocket;
    int status;
    int max = 0;
    char string[50];
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

    recvSocket = new_Socket();

    Connect(recvSockAddr,recvSocket);

    sendFirstRequest(recvSocket,host_name);

    Recieve(recvSocket,buffer);
    sendSecondRequest(recvSocket,host_name,buffer);
    Recieve(recvSocket,buffer);

    strcpy(string,findMax(buffer));
    finalSend(recvSocket,host_name,string);
    char buffer1[10000];
    Recieve(recvSocket,buffer1);
    printf("%s", buffer1);
    system("pause");
    return 0;
}

SOCKET new_Socket(){            // to create new socet
SOCKET recvSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(recvSocket == INVALID_SOCKET)
	{
		printf("ERROR: socket unsuccessful\r\n");
		system("pause");
		return NULL;
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
    sprintf(request, "GET /var/10 HTTP/1.1\r\nHost:%s\r\n\r\n", host_name);  // add Host header with host_name value
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

void sendSecondRequest(SOCKET recvSocket,const char * host_name, char * buffer){
    char request[200];
    char sec_word[100];
    strcpy( sec_word,strstr(buffer,"secret"));
    sprintf(request, "GET /var/10?%s HTTP/1.1\r\nHost:%s\r\n\r\n",sec_word, host_name);  // add Host header with host_name value
    send(recvSocket, request, strlen(request), 0);

}

char * findMax (char * buffer){
  char * pointer = strstr(buffer,"\r\n\r\n");
    char * str[1000];
    str[0] = strtok(pointer, "\n");
    int i = 1;
    while (str[i-1] != NULL){
        str[i] = strtok(NULL, "\n");
        i++;
    }
    char * number = malloc(100*sizeof(char));
    int arr[10][10];
    for (int j = 0; j < i-3; j++){
       number = strtok(str[j+2], " ");
          arr[j][0] = atoi(number);
          int k = 1;
          while(str[j+1] != NULL){
             arr[j][k] = atoi(strtok(NULL," "));
             k++;

          }
}
int max;
int index = 0;
for (int m = 0; m < i-3; m++){
max += arr[0][m];
}

for (int m = 1; m < i - 3; m++){
        int sum = 0;
    for (int n = 0; n < i-3; n++){
        sum += arr[m][n];
    }
if (sum > max){
        max = sum;
        index = m;
}
}
char convert[100];
char string[100];
strcpy(string,"\0");
for (int l = 0; l < index+1 ; l++){
	sprintf(convert, "%d ",arr[index][l]);
	strcat(string,convert);
}
string[strlen(string)-1] = '\0';
return string;

}

void finalSend(SOCKET recvSocket, char* host_name, char * string){
	char info[100];
	char request[200];
	printf("String is: %s\n", string);
	sprintf(info, "result=%s", string);
	//strcpy(info,"result=-8 1 3 556");
	sprintf(request, "POST /var/10 HTTP/1.0\r\n"
		"Host: %s\r\n"
		"Content-length: %d\r\n\r\n"
		"%s\r\n", host_name, strlen(info), info);
	send(recvSocket, request, strlen(request) + 1, 0);
}

