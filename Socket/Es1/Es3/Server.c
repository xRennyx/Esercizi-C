//SERVER
#include <ctype.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define DIM 50
#define SERVERPORT 1313

void OrdinamentoAlfabetico(char *stringa, char *risultato) {
    int lunghezza = strlen(stringa);
    strcpy(risultato, stringa);

    int i, j, minPos;
    char temp;

    for (i = 0; i < lunghezza - 1; i++) {
        minPos= i;
        for (j = i + 1; j < lunghezza; j++) {
            if (tolower(risultato[j]) < tolower(risultato[minPos])) {
                minPos= j;
            }
        }
        if (minPos != i) {
            temp = risultato[i];
            risultato[i] = risultato[minPos];
            risultato[minPos] = temp;
        }
    }
}
int main() {
  struct sockaddr_in servizio, addr_remoto;

  servizio.sin_family = AF_INET;
  servizio.sin_addr.s_addr = htonl(INADDR_ANY);
  servizio.sin_port = htons(SERVERPORT);

  int socketfd, soa ;
  socklen_t fromlen = sizeof(servizio);
  char str[DIM], risposta[DIM];

  socketfd = socket(AF_INET, SOCK_STREAM, 0);

  bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
  listen(socketfd, 10);

  for (; ;) {
    printf("\n\nServer in ascolto...");
    fflush(stdout);

    soa = accept(socketfd, (struct sockaddr *)&addr_remoto, &fromlen);
    if (read(soa, str, sizeof(str)) > 0) {
      printf("\nStringa ricevuta: %s\n", str);
      OrdinamentoAlfabetico(str, risposta);
      write(soa, risposta, sizeof(risposta));
    }
    close(soa);
  }
  return 0;
}