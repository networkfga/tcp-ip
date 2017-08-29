#	Makefile script
#	Authors: Pedro Ivo
#			 Oziel

# Variables
CC=gcc
INCLUDE=./inc
SRC=./src
OBJ=./obj
BIN=./bin

# Compiler Flags
FLAGS=-Wall

#	*	 Compile Steps 	* 	#

Server:
	$(CC) $(SRC)/server.c $(INCLUDE)/server.h -o \
		$(BIN)/server.bin

Client:
	$(CC) $(SRC)/client.c $(INCLUDE)/client.h -o \
		$(BIN)/client.bin

clean:
	rm -f $(BIN)/client.bin $(BIN)/server.bin
