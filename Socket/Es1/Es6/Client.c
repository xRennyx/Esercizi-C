//CLIENT
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>
#define SERVERPORT 1450

int main()
{
    struct sockaddr_in servizio;
    char stringa[20];
    int socketfd, fromlen = sizeof(servizio);

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);

    if ((socketfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        printf("Chiamata fallita alla system call socket");
        exit(0);
    }

    if((connect(socketfd, (struct sockaddr*)&servizio, sizeof(servizio))) == -1){
        printf("Chiamata fallita alla system call connect");
        exit(0);
    }

    printf("Inserisci una stringa\n");
    scanf("%s",stringa);

    write(socketfd, stringa, strlen(stringa) + 1);
    
    read(socketfd, stringa, sizeof(stringa)); // Ricevi stringa minuscola
    printf("Stringa in minuscolo ricevuta: %s\n", stringa);

    // Leggi la seconda risposta (versione maiuscola)
    read(socketfd, stringa, sizeof(stringa)); // Ricevi stringa maiuscola
    printf("Stringa in maiuscolo ricevuta: %s\n", stringa);

    close(socketfd);
    return 0;
}
