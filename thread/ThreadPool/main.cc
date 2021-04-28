#include <iostream>
#include "ThreadPool.hpp"
using namespace std;

int main()
{
	ThreadPool *p = new ThreadPool();
	p->ThreadPoolInit();

	// server
	while(true)
	{
		int x = rand()%20+1;

		Task t(x);
		p->Put(t);
	}
	return 0;
}
