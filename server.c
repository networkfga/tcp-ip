#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>



int socket_id;

int main (int argc, char* const argv[])
{
	unsigned short serverPort;
	struct sockaddr_in serverAddress;
  	serverPort= atoi(argv[1]);

	fprintf(stderr, "Feito!\n");
	
	fprintf(stderr, "Abrindo o socket local... ");
	socket_id = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(socket_id < 0)
	{
		fprintf(stderr, "Erro na criacao do socket!\n");
		exit(0);
	}
	fprintf(stderr, "Feito!\n");

	fprintf(stderr, "Ligando o socket a porta %d... ", serverPort);
	memset(&serverAddress, 0, sizeof(serverAddress)); // Zerando a estrutura de dados
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddress.sin_port = htons(serverPort);
	if(bind(socket_id, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) < 0)
	{
		fprintf(stderr, "Erro na ligacao!\n");
		exit(0);
	}
	fprintf(stderr, "Feito!\n");

	fprintf(stderr, "Socket passivo... ");

	if(listen(socket_id, 10) < 0)
	{
		fprintf(stderr, "Erro!\n");
		exit(0);
	}
	fprintf(stderr, "Feito!\n");

	while(1)
	{
		int socketClient;
		struct sockaddr_in clienteAddr;
		unsigned int clienteLength;

		fprintf(stderr, "Aguardando a conexao de um cliente... ");
		clienteLength = sizeof(clienteAddr);
		if((socketClient = accept(socket_id, (struct sockaddr *) &clienteAddr, &clienteLength)) < 0)
			fprintf(stderr, "Falha no accept().\n");
			fprintf(stderr, "Feito!\n");
		
		fprintf(stderr, "Conexão do Cliente %s\n", inet_ntoa(clienteAddr.sin_addr));
		
		fprintf(stderr, "Tratando comunicacao com o cliente... ");
		fprintf(stderr, "Feito!\n");
		
		int length = 100 ;
		char* receivedMessage;
	
		fprintf(stderr, "%d\n",length );
		receivedMessage = (char*) malloc (length);
		recv(socketClient,receivedMessage,length,0);
		fprintf(stderr, "%s",receivedMessage);
		free(receivedMessage);


		fprintf(stderr, "Fechando a conexao com o cliente... ");
		
		close(socketClient);
		fprintf(stderr, "Feito\n");

	}


	return 0;
}
