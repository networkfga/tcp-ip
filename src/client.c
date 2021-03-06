#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <unistd.h>
#include "../inc/client.h"


int socketId = 0;
struct sockaddr_in serverAddress;
int bufferLength = 0;
char* messageReceived;
char messageSent[100];
int length = 100 ;

void recv_message(int socketId, char* message, int messageLength, int flag);

int main (int argc, char* const argv[])
{	
	char *serverIp = argv[1];
	unsigned short serverPort;
	serverPort = atoi(argv[2]);

    printf ("Client::::\n");
    const char* exit = "exit";
    
    do {
        printf(">> ");
        fflush(stdin);
        scanf("%s", messageSent);
        int messageLength = sizeof(messageSent);
        int flag = 0;
        fprintf(stderr, "%s\n",messageSent);
        int result = connect_to_socket(serverIp, serverPort);

        if (result > 0)
        {
            printf("Connection stablished!\n");
        }

        send_message(result, messageSent, messageLength, flag);
        recv_message(result, messageReceived,100,0);

    } while (strcmp(exit, messageSent) != 0);
}

int connect_to_socket(char *serverIp, unsigned short serverPort)
{
    socketId = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socketId < 0)
    {
        fprintf(stderr, "Erro na criacao do socket!\n");
        exit(0);
    }

    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr(serverIp);
    serverAddress.sin_port = htons(serverPort);

    if (connect(socketId, (struct sockaddr *) &serverAddress, 
                sizeof(serverAddress)) < 0)
    {
        fprintf(stderr, "Erro de Conexao.\n");
        exit(0);
    }

    return socketId;
}

void send_message(int socketId, char* message, int messageLength, int flag)
{
    int canSendMessage;
    canSendMessage = send(socketId, message, messageLength, flag);

    if (canSendMessage < 0)
    {
        fprintf(stderr, "Erro no envio da mensagem!\n");
    }
    
}

void recv_message(int socketId, char* message, int messageLength, int flag)
{
     message = (char*) malloc (100);
    int canRecvMessage;
    canRecvMessage = recv(socketId, message, messageLength, flag);

    if (canRecvMessage < 0)
    {
        fprintf(stderr, "Erro ao receber mensagem\n");
    }

    fprintf(stderr, "resultado é: %s\n",message );
    free(message);
}