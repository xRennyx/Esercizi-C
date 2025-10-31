#include <stdio.h>       //std in-out
#include <stdlib.h>      //per utilizzo di certe funzioni:htonl,rand,....
#include <sys/socket.h>  //funz. accept+bind+listen
#include <sys/types.h>   //funz. accept
#include <netinet/in.h>  //definiscono la struttura degli indirizzi 
#include <string.h>      //funz. stringhe
#include <errno.h>       //gestioni errori connessione
#include <ctype.h>       //bind
#include <unistd.h>     // file header che consente l'accesso alle API dello standard POSIX
#define SERVERPORT 1450



int main(int argc, char** argv[])
{
    struct sockaddr_in serv; 
    int socketfd;
    int soa;
    char str1[]='ciao';
    char str2[30];
    //settagio socket locale
    //valorizzazione dei memebri della struttura
    serv.sin_family=AF_INET; //DOMINIO
    serv.sin_addr.s_addr=htnol(INADDR_ANY);//INDIRIZZO
    serv.sin_port=htnos(SERVERPORT);//CONVERTE IN BINARIO (htnos)
    socketfd=socket(AF_INET, SOCK_STREAM, 0);
    //Leghiamo l'indirizzo al transport endpoint
    bind(socketfd, (struct sockaddr*)&serv,sizeof(serv));
    listen(socketfd,10);//mettiamo in ascolto il socket attende fino a 10 client
    while(1)
    {
        printf("server in ascolto....\n");
        fflush(stdout);//pulisce la socket e il canale di comunicazione
        soa=accept(socketfd, (struct sockaddr*)&serv,sizeof(serv));
        read(soa, str2,sizeof(str2));
        printf("Stringa ricevuta: %s\n",str);
        close(soa);
    }
    return 0;
    
}