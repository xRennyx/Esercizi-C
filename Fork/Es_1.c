#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/fcntl.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    int p;
    p=fork();
    
    if(p==0)
    {
        printf("Il carattere in maiuscolo %c\n", toupper(argv[1][0]));
        exit(0);
    }
    else
    {
        wait(&p);
    }
    printf("Mio figlio ha terminato");
    
return 0;    
}
