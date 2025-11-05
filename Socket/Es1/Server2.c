#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>   // contiene htons, htonl, inet_addr, ecc.

#define SERVERPORT 1450

int is_palindrome(const char *str) {
    int len = strlen(str);
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return 0;  // non palindroma
        }
    }
    return 1; // palindroma
}

int main() {
    int sockfd, new_sock;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t cli_len;
    char buffer[1024];
    char response[1024];

    // Creazione socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Errore creazione socket");
        exit(EXIT_FAILURE);
    }

    // Preparazione indirizzo server
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(SERVERPORT);

    // Binding
    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Errore nel bind");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // In ascolto
    listen(sockfd, 5);
    printf("Server in ascolto sulla porta %d...\n", SERVERPORT);

    while (1) {
        cli_len = sizeof(cli_addr);
        new_sock = accept(sockfd, (struct sockaddr*)&cli_addr, &cli_len);
        if (new_sock < 0) {
            perror("Errore nell'accept");
            continue;
        }

        memset(buffer, 0, sizeof(buffer));
        read(new_sock, buffer, sizeof(buffer));

        printf("Stringa ricevuta dal client: %s\n", buffer);

        if (is_palindrome(buffer))
            strcpy(response, "La stringa è palindroma.\n");
        else
            strcpy(response, "La stringa NON è palindroma.\n");

        write(new_sock, response, strlen(response) + 1);

        close(new_sock);
    }

    close(sockfd);
    return 0;
}
