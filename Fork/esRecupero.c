/* Scrivi il codice sorgente di un programma in cui il processo padre genera tre processi figli.
I processi dovranno visualizzare rispettivamente:
_ "Io sono il padre A, il mio PID=..."
_ "Io sono il figlio B, il mio PID=..., il mio nome è Qui"
_ "Io sono il figlio C, il mio PID=..., il mio nome è Quo"
_ "Io sono il figlio D, il mio PID=..., il mio nome è Qua"
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int p1;
    int p2;
    int p3;
    
    p1=fork();
    
    if(p1>0)
    {
        printf("Io sono il padre A: %d\n", getpid());    
    }
    else if(p1==0)
    {
        printf("Sono il figlio B PID= %d, il mio nome è Qui\n", getpid());
        exit(0);
    }
    else
    {
        printf("Errore nella generazione del processo");
    }
    wait(&p1);
    
    p2=fork();
    
    if(p2==0)
    {
        printf("Io sono il figlio C PID= %d, il mio nome è Quo\n", getpid());
        exit(0);
    }
    else
    {
        wait(&p2);
    }
    
    p3=fork();
    
    if(p3==0)
    {
        printf("Io sono il figlio D PID= %d, il mio nome è Qua\n", getpid());
        exit(0);
    }
    else 
    {
        wait(&p3);
    }
    

    return 0;
}
