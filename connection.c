#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <unistd.h>

char serverIp[] = "192.168.0.11";
int socketId = 0;
struct sockaddr_in serverAddress;
int bufferLength = 0;
unsigned short serverPort = 9600;

int connect_to_socket(void){
    socketId = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socketId < 0){
        fprintf(stderr, "Erro na criacao do socket!\n");
        exit(0);
    }

    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr(serverIp);
    serverAddress.sin_port = htons(serverPort);

    if (connect(socketId, (struct sockaddr *) &serverAddress, 
                sizeof(serverAddress)) < 0){
        fprintf(stderr, "Erro de Conexao.\n");
        exit(0);
    }

    return socketId;
}
