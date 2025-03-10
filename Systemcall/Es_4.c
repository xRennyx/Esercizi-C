#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[])
{

    if (argc < 4)
    {
        printf("Numero argomenti sbagliato\n");
        exit(0);
    }

    int fd, ct = 0;
    char carattere, output[512];
    for (int i = 1; i < argc - 2; i++)
    {
        fd = open(argv[i], O_RDONLY);
        if (fd < 0)
        {
            printf("Errore nell'apertura del file");
            exit(0);
        }

        while (read(fd, &carattere, sizeof(carattere)) > 0)
        {
            if (carattere == argv[argc - 2][0])
            {
                ct++;
            }
        }

        close(fd);
    }

    sprintf(output, "Il carattere '%c' compare %d volte nei files forniti.\n", argv[argc - 2][0], ct);

    write(1, output, strlen(output));

    fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
    {
        perror("Errore nella creazione");
        exit(0);
    }
    write(fd, output, strlen(output));
    close(fd);

    return 0;
}
