/*Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve in input 2
stringhe e, dopo aver effettuato gli eventuali ed opportuni controlli (se necessari), rispedisce al Client il
messaggio di quale delle due stringhe è + lunga o più corta o se sono uguali.*/
//Client
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>
#include <stdbool.h>

#define DIM 512
#define SERVERPORT 1313

int main(int argc, char **argv)
{
    int sockeTrasporto;
    struct socketaddr_in 
    struct indirizzo;
    char str1[DIM], str2[DIM], risposta[DIM];
    sockeTrasporto=socket(AF_INET, SOCK_STREAM, 0);
    indirizzo.sin_family=AF_INET;
    indirizzo.sin_port=htons(SERVERPORT);
    connect(sockeTrasporto(struct sockaddr)*indirizzo, sizeof(indirizzo));
    printf("Inserisci una stringa: ");
    scanf("%s",str1);
    printf("Inserisci una stringa: ");
    scanf("%s",str2);
    write(socketTrasporto, str1, strlen(str1));
    write(socketTrasporto, str2, strlen(str2));
    read(socketTrasporto, risposta, sizeof(risposta));
    printf("Risposta ricevuta dal server: %s\n", risposta);
    close(socketTrasporto);
    return 0;
}

