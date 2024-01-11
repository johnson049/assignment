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
		pthread_mutex_lock(&mutex);
		printf("Thread 1 Func locked\n");
		printf("Before:thread1 x: %d\n",x);
		x=x+1;
		printf("After:thread1 x: %d\n",x);
		pthread_mutex_unlock(&mutex);
		printf("Thread 1 Func unlocked\n");
		sleep(2);
	}
	pthread_exit(NULL);
}
void* thread2func(void* z)
{
	int i=0;
	for (;i<10;i++)
	{
		pthread_mutex_lock(&mutex);
		printf("                                       Before:thread1 x: %d\n",x);
		x=x+1;
		printf("                                       After:thread1 x: %d\n",x);
		pthread_mutex_unlock(&mutex);
		sleep(2);
	}
	pthread_exit(NULL);
}
int main()
{
	pthread_t thread1,thread2;
	int rc;
	pthread_mutex_init(&mutex,NULL);
	rc=pthread_create(&thread1,NULL,thread1func,NULL);
	rc=pthread_create(&thread2,NULL,thread2func,NULL);
	printf("wait for threads to complete (before returning from the main)\n");
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	pthread_mutex_destroy(&mutex);
	return 0;
}
