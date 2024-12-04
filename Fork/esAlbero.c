//Scrivi il codice sorgente di un programma che realizza lo schema disegnato alla lavagna.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int p1;
    int p2;
    int p3;
    int p4;
    int p5;
    
    p1=fork();
    
    if(p1>0)
    {
        printf("Sono il Padre PID= %d\n", getpid());
    }
    else if(p1==0)
    {
        printf("Sono il figlio A PID= %d\n", getpid());
        printf("Mio padre ha PID= %d\n", getppid());
        exit(0);
    }
    else
    {
        printf("Errore nella generazione");
    }
    
    p2=fork();
    
    if(p2==0)
    {
        printf("Sono il figlio B PID= %d\n", getpid());
        printf("Mio padre ha PID= %d\n", getppid());
        exit(0);
    }
    
    p3=fork();
    
    if(p3==0)
    {
        printf("Sono il nipote C PID= %d\n", getpid());
        printf("Mio padre ha PID= %d\n", p1);
        exit(0);
    }
    
    p4=fork();
    
    if(p4==0)
    {
        printf("Sono il nipote D PID= %d\n", getpid());
        printf("Mio padre ha PID= %d\n", p2);
        exit(0);
    }
    
    p5=fork();
    
    if(p5==0)
    {
        printf("Sono il nipote E PID= %d\n", getpid());
        printf("Mio padre ha PID= %d\n", p2);
        exit(0);
    }
    return 0;
}    