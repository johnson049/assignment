#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void parentMethod()
{
	int i;
	printf("parentpid is %d\n",getpid());
	for (i=0;i<5;i++)
	{
		printf("%d\t",i);
	}
}
void childMethod()
{
	int j;
	printf("Childpid is %d\n",getpid());
	for (j=5;j<10;j++)
	{
		printf("%d\t",j);
		sleep(5);
	}
	printf("i am out of sleep");
}
int main() {
    int status;
    pid_t pid = fork();
    if (pid ==0)
    {
    	childMethod();
    }
    else 
    {
    	parentMethod();
    }
    return 0;
    
}
