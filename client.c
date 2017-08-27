#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <unistd.h>

int connect_to_socket();
void send_message(int socketId, char* message, int messageLength, int flag);

char serverIp[] = "192.168.0.11";
int socketId = 0;
struct sockaddr_in serverAddress;
int bufferLength = 0;
unsigned short serverPort = 9601;

void main (void){
    printf ("Client::::\n");
    int result = connect_to_socket();
    
    char message[] = "2 + 3";
    int messageLength = sizeof(message);
    printf("%d", messageLength);
    int flag = 0;

    send_message(result, message, messageLength, flag);

    if (result > 0){
        printf("Connection stablished!\n");
    }
}

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

void send_message(int socketId, char* message, int messageLength, int flag){
    int canSendMessage;
    canSendMessage = send(socketId, message, messageLength, flag);

    if (canSendMessage < 0){
        fprintf(stderr, "Erro no envio da mensagem!\n");
    }
    
}
