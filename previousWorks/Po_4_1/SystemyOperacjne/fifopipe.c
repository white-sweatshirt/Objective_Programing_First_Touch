#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#define PAR_OF_DESCRIPTORS 2
#define READ 0
#define WRITE 1
int factorial(int n)
{
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}
void functionForChild1(int desc[], char fifoName[])
{
    printf("PID child 1 : %d\n", getpid());    close(desc[WRITE]);
    int n;
    int desca;
    while (1)
    {
        while(read(desc[READ], &n, sizeof(n))==0)
            ;
        n = factorial(n);
        desca = open(fifoName, O_WRONLY);
        
        write(desca, &n, sizeof(n));
        close(desca);
        sleep(2);
    }
}

void functionForChild2(char fifoName[])
{
    printf("PID child 2 : %d\n", getpid());
    int result = 0, desc = -1;
    while (1)
    {
        sleep(1);
        desc = open(fifoName, O_RDONLY);
        while(read(desc, &result, sizeof(result))==0)
            ;
        close(desc);
        printf("silnia wynosi: %d\n",result);
        fflush(stdout);
    }
}
int main(void)
{

    umask(0);
    int descriptorsTable[PAR_OF_DESCRIPTORS];
    pipe(descriptorsTable);
    char fifo[] = "fifoname";
    mkfifo(fifo, 0700);
    if (fork() == 0)
        functionForChild1(descriptorsTable, fifo);
    if (fork() == 0)
        functionForChild2(fifo);
    close(descriptorsTable[READ]);
    int n;
    sleep(1);
    while(1)
    {
        printf("\npodaj liczbe do silni: ");
        scanf("%d",&n);
        write(descriptorsTable[WRITE],&n,sizeof(n));
        sleep(1);
    }
    return 0;
}