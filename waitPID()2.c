#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int dim = 5;
    int v[dim];
    int somma = 0;
    float media;

    int p2 = fork();
    if (p2 == 0)  
    {
        printf("Sono P2 PID= %d, mio padre ha PID=%d\n", getpid(), getppid());
        somma = 0;

        
        for (int i = 0; i < dim; i++)
        {
            printf("Inserisci numero: ");
            scanf("%d", &v[i]);
            somma = somma + v[i];
        }

        
        printf("Vettore: ");
        for (int i = 0; i < dim; i++)
        {
            printf("%d ", v[i]);
        }
        printf("\n");

        int p3 = fork();
        if (p3 == 0) 
        {
            printf("Sono P3 PID= %d, mio padre ha PID=%d\n", getpid(), getppid());
            for (int i = 0; i < dim; i++)
            {
                int minPos = i;
                for (int j = i; j < dim; j++)
                {
                    if (v[minPos] > v[j])
                    {
                        minPos = j;
                    }
                }
                int temp = v[minPos];
                v[minPos] = v[i];
                v[i] = temp;
            }
            printf("Valore minimo: %d\n", v[0]);
            exit(0);  
        }
        int p4=fork();
        if(p4==0)
        {
            printf("Sono P4 PID= %d, mio padre ha PID=%d\n", getpid(), getppid());
            for (int i = 0; i < dim; i++)
            {
                int maxPos = i;
                for (int j = i; j < dim; j++)
                {
                    if (v[maxPos] < v[j])
                    {
                        maxPos = j;
                    }
                }
                int temp = v[maxPos];
                v[maxPos] = v[i];
                v[i] = temp;
            }
            printf("Valore massimo: %d\n", v[0]);
            exit(0);  
        }
        int p5=fork();
        if(p5==0)
        {
            printf("Sono P5 PID= %d, mio padre ha PID=%d\n", getpid(), getppid());
            media= (float) somma/dim;
            printf("Media: %.2f\n", media);
        }

        
        wait(NULL);
        exit(somma);  
    }
    else 
    {
        
        int status;
        waitpid(p2, &status, 0);

        if (WIFEXITED(status))
        {
            somma = WEXITSTATUS(status);
        }

        printf("Somma: %d\n", somma);
    }

    return 0;
}