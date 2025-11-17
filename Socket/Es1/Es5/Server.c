//Server
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define DIM 512
#define SERVERPORT 1313
#define BUFFER_SIZE 1024

int confrontastringhe(char str1, char str2)
{
    if(strlen(str1)>strlen(str2))
    {
        return 1;
    }
    else if(if(strlen(str1)<strlen(str2)))
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int main() 
{
  struct sockaddr_in servizio, indirizzo;
  int socketTrasporto, client;
  socklen_t fromlen = sizeof(indirizzo);
  char stringa[DIM];
  char carattere;
  char buffer[BUFFER_SIZE];
  int caratteriContati;
  int dimensione;

  servizio.sin_family = AF_INET;
  servizio.sin_addr.s_addr = htonl(INADDR_ANY);
  servizio.sin_port = htons(SERVERPORT);

  socketTrasporto = socket(AF_INET, SOCK_STREAM, 0);
  if (socketTrasporto < 0) {
    perror("Errore nella creazione del socket");
    exit(1);
  }

  bind(socketTrasporto, (struct sockaddr *)&servizio, sizeof(servizio));

  listen(socketTrasporto, 10);
  for(;;)
  {
    printf("Server in ascolto sulla porta %d...", SERVERPORT);
    fflush(stdout);

    client=ccept(socketTrasporto, (struct sockaddr *)&indirizzo_remoto, &fromlen);

    dimensione=confrontastringhe;
 if (dimensione == 1) {
            sprintf(buffer, "La prima stringa \"%s\" è più lunga della seconda \"%s\".", stringa1, stringa2);
        } else if (dimensione == 2) {
            sprintf(buffer, "La seconda stringa \"%s\" è più lunga della prima \"%s\".", stringa2, stringa1);
        } else {
            sprintf(buffer, "Le due stringhe \"%s\" e \"%s\" sono uguali.", stringa1, stringa2);
        }
        if (send(client, buffer, strlen(buffer), 0) < 0) {
            perror("Errore nell'invio della risposta al client");
        }
        close(client);
    close(socketTrasporto);
    return 0;
}

