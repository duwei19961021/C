#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_run(void* arg)
{
	while(1)
	{
		printf("thread 1: %lu, pid: %d\n",pthread_self(), getpid());
		sleep(1);
	}
	
//	pthread_exit((void*)99); // 终止线程
//	return (void*)10;
}

int main()
{
	pthread_t tid;

	int i;

	pthread_create(&tid, NULL, thread_run, "thread 1");

	while(1)
	{
		printf("main thread: %lu, pid: %d\n",pthread_self(), getpid());
		sleep(10);
		break;
	}
	
	pthread_cancel(tid);

	void* ret = NULL;

	pthread_join(tid, &ret);

	printf("thread return number: %d\n", (long long)ret);

	return 0;
}
