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

Baixe o repositório utilizando:

```shell
$ git clone https://github.com/networkfga/tcp-ip.git
```

Dentro da pasta execute o seguinte comando para compilar todos arquivos:

```
$ make
```

## 3. Execução

### 3.1 Cliente


```
$ make exec_client ip=IP
```


### 3.2 Servidor
```
$ make exec_server port=PORTA
```
Exemplo:
```
$ make exec_server port=2152
$ make exec_client ip=192.168.0.65
```


