#ifndef SERVER_H_
#define SERVER_H_

char* interpret_with_bc(const char *expression);
void send_message(int socketId, char* message, int messageLength, int flag);
void recv_message(int socketId, char* message, int messageLength, int flag);

#endif
