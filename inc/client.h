#ifndef CLIENT_H_
#define CLIENT_H_

int connect_to_socket(char *serverIp, unsigned short serverPort);
void send_message(int socketId, char* message, int messageLength, int flag);

#endif
