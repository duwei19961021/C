#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

pthread_cond_t cond;
pthread_mutex_t lock;

void* thread_run(void* arg)
{
	const char* name = (char*)arg;
	while(1)
	{
		pthread_cond_wait(&cond, &lock);
		printf("%s, activing....\n",name);
		printf("\n");
	}
}

void* thread_run1(void* arg)
{
	const char* name = (char*)arg;
	while(1)
	{
		sleep(1);
		pthread_cond_signal(&cond);
		printf("%s, signal to thread done....\n",name);
		printf("\n");
	}
}

int main()
{
	pthread_t t1,t2,t3,t4;

	pthread_cond_init(&cond, NULL);

	pthread_mutex_init(&lock, NULL);

	pthread_create(&t1, NULL, thread_run1, (void *)"thread 1");

	pthread_create(&t2, NULL, thread_run, (void *)"thread 2");

	pthread_create(&t3, NULL, thread_run, (void *)"thread 3");

	pthread_create(&t4, NULL, thread_run, (void *)"thread 4");

	pthread_join(&t1, NULL);

	pthread_join(&t2, NULL);

	pthread_join(&t3, NULL);

	pthread_join(&t4, NULL);

	return 0;
}
