# Cliente/Servidor TCP-IP

## 1. Dependências

Para construir o sistema de cálculo _cliente/servidor_ é necessário possuir os seguintes requisitos:

* Sistema operacional Linux -> _Debian like_ (Distribuições Debian, ou feitas a partir do Debian)
* Compilador GCC
* Make

### 1.2 Preparando seu ambiente

Para que o sistema seja executado de forma correta, recomendamos que você siga os passos de instalação dos pacotes de dependência. 

#### 1.2.1 GCC

Para instalar o GCC em seu sistema operacional escreva a seguinte linha de comando:

```shell
$ sudo apt-get install gcc
```
As versões do GCC testadas foram a v4.1 e a mais recente dos sistemas Ubuntu v6.3.0. 

#### 1.2.2 Make

O Make é necessário para rodar o script de compilação do sistema de cálculo.
Para instalar o Make basta executar a linha de comando abaixo:

```shell
$ sudo apt-get install build-essential
```

## 2. Download do Sistema

Você pode baixar o sistema disponível no repositório do Github utilizando o seguinte comando:

```shell
$ git clone https://github.com/networkfga/tcp-ip.git
```

## 3. Compilação

Dentro da pasta execute o seguinte comando para compilar todos arquivos:

```
$ make
```

Se tudo ocorrer corretamente você verá um terminal assim:

```
freemanpivo@gnome:~/git/trab1_redes$ make
if test -d obj/; \
then echo exists; \
else mkdir obj; \
fi
exists
if test -d bin/; \
then echo exists; \
else mkdir bin/; \
fi
exists
gcc ./src/client.c ./inc/client.h -o \
	./bin/client.bin
gcc ./src/server.c ./inc/server.h -o \
	./bin/server.bin
freemanpivo@gnome:~/git/trab1_redes$
```

## 4. Execução

### 4.1 Servidor

Para executar nosso servidor, precisaremos definir uma porta que ele irá receber as requisições.

```
$ make exec_server port=PORTA
```

Se o servidor conseguir ficar em seu modo de espera você verá algo semelhante a esta mensagem:


```
freemanpivo@gnome:~/git/trab1_redes$ make exec_server port=9602
./bin/server.bin 9602
Feito!
Abrindo o socket local... Feito!
Ligando o socket a porta 9602... Feito!
Socket passivo... Feito!
Aguardando a conexao de um cliente... Feito!
```

### 4.2 Cliente

Para executar a calculadora cliente, você necessita de duas variáveis, a porta em que o servidor está rodando e o endereço IP do mesmo.

Para descobrir seu IP local (se o servidor foi rodado localmente) basta digitar o seguinte comando:

```
$ ifconfig
```
**SAÍDA**:
```
wlp3s0: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
        inet 192.168.0.20  netmask 255.255.255.0  broadcast 192.168.0.255
```
E Utilizar o IP logo a seguir da palavra "inet".

Partindo para a execuço do cliente basta executar o seguinte comando:

```
$ make exec_client ip=IP port=PORT
```
Se o cliente foi executado na mesma porta e endereço IP do servidor você verá algo assim:

```
freemanpivo@gnome:~/git/trab1_redes$ make exec_client ip=107.170.77.49 port=9602
./bin/client.bin 107.170.77.49 9602
Client::::
>> 
```

## 5. Exemplos

_IP_: 192.168.0.20
_PORT_: 9602

**Cliente: **

```
freemanpivo@gnome:~/git/trab1_redes$ make exec_client ip=192.168.0.20 port=9602
./bin/client.bin 192.168.0.20 9602
Client::::
>> 2+2
2+2
Connection stablished!
resultado é: 4

>> 9*8-69/2
9*8-69/2
Connection stablished!
resultado é: 37.5
>> (1+2)*3
(1+2)*3
Connection stablished!
resultado é: 9

>> 2/0
2/0
Connection stablished!
resultado é: 
>> 2^3
2^3
Connection stablished!
resultado é: 8

>> exit
exit
Connection stablished!
resultado é: 0

freemanpivo@gnome:~/git/trab1_redes$
```

**Servidor:** 

```
freemanpivo@gnome:~/git/trab1_redes$ make exec_server port=9602
./bin/server.bin 9602
Feito!
Abrindo o socket local... Feito!
Ligando o socket a porta 9602... Feito!
Socket passivo... Feito!
Aguardando a conexao de um cliente... Feito!
Conexão do Cliente 192.168.0.20
Tratando comunicacao com o cliente... Feito!
2+2 ===> 4

Fechando a conexao com o cliente... Feito
Aguardando a conexao de um cliente... Feito!
Conexão do Cliente 192.168.0.20
Tratando comunicacao com o cliente... Feito!
9*8-69/2 ===> 37.5000
Fechando a conexao com o cliente... Feito
Aguardando a conexao de um cliente... Feito!
Conexão do Cliente 192.168.0.20
Tratando comunicacao com o cliente... Feito!
(1+2)*3 ===> 9

Fechando a conexao com o cliente... Feito
Aguardando a conexao de um cliente... Feito!
Conexão do Cliente 192.168.0.20
Tratando comunicacao com o cliente... Feito!
Runtime error (func=(main), adr=5): Divide by zero
SYNTAX or BUFFER error!
2/0 ===> 
Fechando a conexao com o cliente... Feito
Aguardando a conexao de um cliente... Feito!
Conexão do Cliente 192.168.0.20
Tratando comunicacao com o cliente... Feito!
2^3 ===> 8

Fechando a conexao com o cliente... Feito
Aguardando a conexao de um cliente... Feito!
Conexão do Cliente 192.168.0.20
Tratando comunicacao com o cliente... Feito!
exit ===> 0

Fechando a conexao com o cliente... Feito

```



