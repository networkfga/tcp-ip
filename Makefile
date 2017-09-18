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
Server: Client
	$(CC) $(SRC)/server.c $(INCLUDE)/server.h -o \
		$(BIN)/server.bin

Client: bin_folder
	$(CC) $(SRC)/client.c $(INCLUDE)/client.h -o \
		$(BIN)/client.bin

bin_folder: obj_folder
	if test -d bin/; \
	then echo exists; \
	else mkdir bin/; \
	fi

obj_folder:
	if test -d obj/; \
	then echo exists; \
	else mkdir obj; \
	fi

clean:
	rm -f $(BIN)/client.bin $(BIN)/server.bin

exec_server:
	./bin/server.bin $(port)

exec_client:
	./bin/client.bin $(ip)
