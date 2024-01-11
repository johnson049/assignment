#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_mutex_t mutex;
int x=10;

void* thread1func(void* z)
{
	int i=0;
	for (;i<10;i++)
	{
		printf("Before:thread1 x: %d\n",x);
		x=x+1;
		printf("After:thread1 x: %d\n",x);
		sleep(2);
	}
	pthread_exit(NULL);
}
void* thread2func(void* z)
{
	int i=0;
	for (;i<10;i++)
	{
		printf("                                       Before:thread1 x: %d\n",x);
		x=x+1;
		printf("                                       After:thread1 x: %d\n",x);
		sleep(2);
	}
	pthread_exit(NULL);
}
int main()
{
	pthread_t thread1,thread2;
	int rc;
	
	rc=pthread_create(&thread1,NULL,thread1func,NULL);
	rc=pthread_create(&thread2,NULL,thread2func,NULL);
	printf("wait for threads to complete (before returning from the main)\n");
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	return 0;
}
