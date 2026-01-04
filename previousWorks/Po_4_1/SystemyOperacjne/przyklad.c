#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(void)
{
char pid[10];

	if(fork()==0) // P1
	{
		printf("1 PID: %d, PPID: %d\n", getpid(), getppid());
		sleep(120);
		return 0;
	}
	if(fork()==0) // P2
	{
		printf("2 PID: %d, PPID: %d\n", getpid(), getppid());
		if(fork()==0) // P3
		{
			printf("3 PID: %d, PPID: %d\n", getpid(), getppid());
			if(fork()==0) // P4
			{
				printf("4 PID: %d, PPID: %d\n", getpid(), getppid());
				sleep(120);
				return 0;
			}
			sleep(120);
			return 0;
		}
		if(fork()==0) // P5
		{
			printf("5 PID: %d, PPID: %d\n", getpid(), getppid());
			sleep(120);
			return 0;
			
		}
		sleep(120);
		return 0;
	}
sleep(120);
return 0;
}