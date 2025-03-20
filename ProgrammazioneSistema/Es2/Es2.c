#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Errore numero argomenti");
    }
    #define DIM_BUFFER 1024
    int fd;
    int p1p0[2];
    int p2p0[2];
    int pid;
    int nread;
    char buffer[DIM_BUFFER];
    pipe(p1p0);

    pid=fork();

    if(pid==0)
    {
        close(p1p0[0]);
        close(1);
        dup(p1p0[1]);
        close(p1p0[1]);
        execl("bin/cat", "cat", argv[1]);
        return -1;
    }
    pipe(p2p0);

    pid=fork();

    if(pid==0)
    {
        close(p1p0[1]);
        close(0);
        dup(p1p0[0]);
        close(p1p0[0]);

        close(p2p0[1]);
        close(0);
        dup(p2p0[0]);
        close(p2p0[0]);
        exelc("bin/wc", "wc");
        return -1;
    }
    close(p1p0[0]);
    close(p1p0[1]);
    close(p2p0[1]);

    fd=open("wc.txt", O_WRONLY, 0777);
    while(nread=read(p2p0[0], buffer, sizeof(buffer))>0)
    {
        write(fd, buffer, nread);
    }
    close(p2p0[0]);
    close(fd);
return 0;
}