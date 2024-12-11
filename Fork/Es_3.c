#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/fcntl.h>
#include <ctype.h>
#include <string.h>

void converti(char str[])
{
    for(int i=0; i<strlen(str); i++)
    {
        str[i]=toupper(str[i]);
    }
}

int main(int argc, char *argv[])
{
    if(argc!=2)
    {
        printf("Errore degli argomenti");
    }
    
    int p;
    p=fork();
    
    if(p==0)
    {
       converti(argv[1]);
       printf("Parola maiuscola: %s", argv[1]);
       exit(0);
    }
    else
    {
        wait(&p);
    }
    
    
return 0;    
}
