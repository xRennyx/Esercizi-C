#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/fcntl.h>
#include <ctype.h>
#include <string.h>

int ricerca(int num,int a[])
{
    for(int i=0; i<10; i++)
    {
        if(a[i]==num)
        {
            return i;
        }
    }
}

int main(int argc, char *argv[])
{
    if(argc!=2)
    {
        printf("Errore degli argomenti");
    }
    
    int posizione;
    int a[]={1,2,3,4,5,6,7,8,9,10};
    int num=atoi(argv[1]);
    int p;
    p=fork();
    
    if(p==0)
    {
       posizione=ricerca(num, a);
       printf("il numero %d si trova in posizione %d", num, posizione);
       exit(0);
    }
    else
    {
        wait(&p);
    }
    
    
return 0;    
}
