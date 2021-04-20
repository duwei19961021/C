#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *thread_run(void *arg)
{
	while(1)
	{
		printf("I am %s\n", (char*)arg);
		sleep(1);
	}
}

int main()
{
	pthread_t tid;
	pthread_create(&tid, NULL, thread_run, (void*)"thread 1");

	while(1)
	{
		printf("I am thread!\n");
		sleep(2);
	}
}

