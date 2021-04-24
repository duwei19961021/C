#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include "BlockQueue.hpp"
#include <stdlib.h>
using namespace std;

void* Pro_run(void *arg)
{
	BlockQueue<int> *q = (BlockQueue<int>*)arg;
	while(true)
	{
		int data = rand()%110;
		q->Put(data);
		cout << "Pro put: " << data << endl;
		sleep(1);
	}
}

void* Con_run(void *arg)
{
	BlockQueue<int> *q = (BlockQueue<int>*)arg;
	while(true)
	{
		int data = 0;
		q->Get(data);
		cout << "Con get: " << data << endl;
	}
}

int main()
{
	pthread_t con,pro;

	BlockQueue<int> *bq = new BlockQueue<int>(10);

	pthread_create(&pro, nullptr, Pro_run, (void*)bq);

	pthread_create(&con, nullptr, Con_run, (void*)bq);

	pthread_join(con, nullptr);
	pthread_join(pro, nullptr);

	delete bq;

	return 0;
}
