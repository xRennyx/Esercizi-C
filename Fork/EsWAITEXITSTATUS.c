#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int dim = 3;
    int v[dim];
    pid_t p2, p3, p4, p5, p6;

    printf("P1: mio PID=%d, sto generando il vettore V[]\n", getpid());
    for (int i = 0; i < dim; i++) {
        v[i] = rand() % 6; 
    }

    // P1 genera P2
    p2 = fork();
    if (p2 == 0) {
        printf("P2: mio PID=%d, mio padre P1 ha PID=%d\n", getpid(), getppid());

        // P2 genera P4
        p4 = fork();
        if (p4 == 0) {
            printf("P4: mio PID=%d, mio padre P2 ha PID=%d\n", getpid(), getppid());

            int prodotto = 1;
            for (int i = 0; i < dim; i++) {
                prodotto = prodotto*v[i];
            }
            printf("P4: il prodotto delle componenti di V[] è %d\n", prodotto);
            exit(0);
        }
        wait(&p4);

        // P2 genera P5
        p5 = fork();
        if (p5 == 0) {
            printf("P5: mio PID=%d, mio padre P2 ha PID=%d\n", getpid(), getppid());

            int somma = 0;
            for (int i = 0; i < dim; i++) {
                somma = somma+v[i];
            }
            float media = (float)somma / dim;
            printf("P5: la media delle componenti di V[] è %.2f\n", media);
            exit(0);
        }

        wait(&p5);
        exit(0);
    }

    // P1 genera P3
    p3 = fork();
    if (p3 == 0) {
        printf("P3: mio PID=%d, mio padre P1 ha PID=%d\n", getpid(), getppid());

        printf("P3: il vettore V[] è [");
        for (int i = 0; i < dim; i++) {
            printf("%d ", v[i]);
        }
        printf("]\n");

        // P3 genera P6
        p6 = fork();
        if (p6 == 0) {
            printf("P6: mio PID=%d, mio padre P3 ha PID=%d\n", getpid(), getppid());

            int somma = 0;
            for (int i = 0; i < dim; i++) {
                somma += v[i];
            }
            printf("P6: la somma delle componenti di V[] è %d\n", somma);
            exit(somma);
        }
        int status;
        wait(&status);
        int risultato = WEXITSTATUS(status);
        printf("P3: il risultato restituito da P6 = %d\n", risultato);
        exit(0);
    }
    wait(&p2);
    wait(&p3);

    printf("P1: tutti i processi figli hanno terminato\n");
    return 0;
}
