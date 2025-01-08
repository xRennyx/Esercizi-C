#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void ordina(int argc, char *argv[])
{
     int i, j;
    char *temp;

    for (i = 0; i < argc; i++)
    {
        for (j = 2; j < (argc - i - 1); j++)
        {
            if (strcmp(argv[j], argv[j + 1]) > 0)
            {
                temp = argv[j];
                argv[j] = argv[j + 1];
                argv[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    if(argc<2)
    {
        printf("Errore numero argomenti");
        exit(0);
    }
    ordina(argc, argv);
    
     int fd = open(argv[1], O_WRONLY | O_CREAT, 0644);
    
    for(int i=2; i<argc; i++)
    {
        write(fd, argv[i], strlen(argv[i]));
        write(1, argv[i], strlen(argv[i]));
    }
    close(fd);

return 0;
}
