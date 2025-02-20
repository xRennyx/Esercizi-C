#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int f1,f2,f3,f4;
    int n1=0;
    int n2=0;
    do
    {
        n1=rand() % 21;
        n2=rand() % 21;
    }while(n1==n2);
    printf("Sono il padre mio PID=%d\n", getpid());
    printf("N1 ha valore= %d\nN2 ha valore= %d", n1, n2);
return 0;    
}