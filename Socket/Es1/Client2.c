#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVERPORT 1450
#define SERVER_IP "127.0.0.1"   // localhost

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    char str[1024];
    char response[1024];

    printf("Inserisci una stringa: ");
    scanf("%1023s", str);

    // Creazione socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Errore creazione socket");
        exit(EXIT_FAILURE);
    }

    // Impostazione indirizzo server
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVERPORT);
    serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    // Connessione al server
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Errore connessione al server");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Invio stringa
    write(sockfd, str, strlen(str) + 1);

    // Lettura risposta
    read(sockfd, response, sizeof(response));

    printf("Risposta dal server: %s\n", response);

    close(sockfd);
    return 0;
}
