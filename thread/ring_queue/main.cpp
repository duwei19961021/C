#include "RingQueue.hpp"
#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

void* Productor(void *arg)
{
	RingQueue<int> *q = (RingQueue<int>*)arg;
	while(true)
	{
		int data = rand() % 100;
		q->Put(data);
		cout << "Productor Put data: " << data << endl;
	}
}

void* Consumer(void *arg)
{
	RingQueue<int> *q = (RingQueue<int>*)arg;
	while(true)
	{
		int data;
		q->Get(data);
		cout << "Consumer Get data: " << data << endl;
		sleep(1);
	}
}

int main()
{
	RingQueue<int> *rq = new RingQueue<int>;

	pthread_t pro, con;

	pthread_create(&pro, nullptr, Productor, (void*)rq);

	pthread_create(&con, nullptr, Consumer, (void*)rq);

	pthread_join(pro, nullptr);

	pthread_join(con, nullptr);

	return 0;
}
