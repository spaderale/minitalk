
# 🗣️ Minitalk


O Minitalk é um projeto da 42 School
 que implementa um sistema de comunicação entre dois processos — um cliente e um servidor — usando apenas sinais UNIX (SIGUSR1 e SIGUSR2).
Cada caractere da mensagem é convertido em bits e transmitido bit a bit entre os processos.

## ⚙️ Objetivo

Criar dois programas que se comuniquem via sinais (SIGUSR1 e SIGUSR2).

Converter caracteres em bits e enviá-los do cliente para o servidor.

O servidor deve reconstruir a mensagem e exibi-la no terminal.

Na versão bônus, o servidor envia uma confirmação (ACK) de volta ao cliente ao receber a mensagem completa.

## 📂 Estrutura do Projeto

| Raíz   |
| :---------- |
├── client.c  | 
├── server.c          
├── client_bonus.c    
├── server_bonus.c    
├── utils_bonus.c     
├── minitalk.h        
├── Makefile
└── README.md



## 🧠 Conceitos Principais
Conceito	Explicação
Sinais UNIX	Mecanismo de comunicação entre processos. Aqui usamos SIGUSR1 e SIGUSR2.\
Bit Shifting (>>, <<)	Move os bits de um valor para acessar posições específicas.# 🧠 Minitalk

🌟 Versão Bônus — Confirmação de Entrega (ACK)

Na versão bônus, o servidor envia um sinal de volta para o cliente ao terminar de receber a mensagem.
Isso garante que a transmissão foi recebida com sucesso.

O servidor responde com SIGUSR1 quando o caractere '\0' é recebido.

O cliente fica em pause() até receber o ACK, depois exibe:

Mensagem entregue! 🕒

💥 Testes com Mensagens Longas e Emojis

O projeto foi testado com textos extensos, acentuação e emojis UTF-8, como:

"Olá, mundo! 😄🚀 Estou testando o Minitalk bônus — será que funciona com acentuação e emojis? ÁÉÍÓÚ àèìòù ç ãõ 👍✨" && "Neque porro quisquam est qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit...🚀🚀🚀🚀🚀"


O servidor reconstrói todos os caracteres corretamente, byte a byte.

⚙️ Compilação\
make            # Compila versão normal\
make bonus      # Compila versão bônus\
make clean      # Remove arquivos objeto\
make fclean     # Remove binários e objetos\
make re         # Recompila tudo\

🧰 Funções Permitidas\
write\
ft_printf (ou equivalente próprio)\
signal\
sigemptyset\
sigaddset\
sigaction\
kill\
getpid\
malloc\
free\
pause\
sleep\
usleep\
exit

## 💬 Exemplo de Execução

🖥️ Servidor

```bash
  ./server
```
Saída:

```bash
Server PID: 12345
```
💬 Cliente
```bash
./client 12345 "Olá, mundo! 😄🚀"
```
📡 Servidor imprime:
Olá, mundo! 😄🚀

📈 Extras no Repositório

Além do projeto original, foi adicionado (fora da versão avaliada pela 42) um timer opcional que mede o tempo total de envio da mensagem usando gettimeofday(), exibido com o ft_printf personalizado:

Mensagem entregue! 🕒 Tempo total: 178 ms (53 bytes)

💡 Aprendizados

Durante o desenvolvimento deste projeto, aprendi sobre:

Manipulação de bits para converter caracteres em sinais.

Comunicação entre processos sem sockets.

Diferença entre signal() e sigaction().

Uso de static para manter estado entre chamadas de sinal.

Sincronização simples entre processos (ACK).

Testes com UTF-8 e emojis.

Importância de pequenos delays (usleep) para confiabilidade.

🧑‍💻 Autor

Alexandre Broslavetz Spader\
📍 42 Porto — Common Core

“Aprender a fazer dois processos conversarem foi o primeiro passo para entender como os sistemas realmente se comunicam.” 💬



