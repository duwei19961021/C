#include <iostream>
#include <queue>
#include <pthread.h>
#include <cmath>
#include <unistd.h>

class Task
{
public:
	int base;
public:
	Task() = default;
	Task(int num): base(num){} 
	void Run()
	{
		std::cout << "thread id[" << pthread_self() <<"]" << "thread run done...... : base# " << base << " pow is # " << pow(base, 2)  << std::endl;	
		usleep(100);
	}

};

class ThreadPool
{
private:
	pthread_mutex_t lock;
	pthread_cond_t cond; // 只能让消费者等，如果作为服务器时，生产者等待那么就无法接收外部请求了
	std::queue<Task> q;
	size_t max_num;
public:
	void LockQueue()
	{
		pthread_mutex_lock(&lock);
	}

	void UnLockQueue()
	{
		pthread_mutex_unlock(&lock);
	}

	void ThreadWait()
	{
		pthread_cond_wait(&cond, &lock);
	}

	void WakeUpThread()
	{
		pthread_cond_signal(&cond);
	}

	bool IsEmpty()
	{
		return q.size() == 0;
	}	

	// threadpool
	void Get(Task &out)
	{
		out = q.front();
		q.pop();
	}
	
	// server
	void Put(Task &in)
	{
		LockQueue();
		q.push(in);
		UnLockQueue();
		WakeUpThread(); // 生产者塞任务进入队列之后，需要通知消费者。
	}
	
public:
	ThreadPool(int num = 5): max_num(num)
	{}

	static void* Routine(void *arg)
	{
		ThreadPool *this_p = (ThreadPool*)arg;		
		while(true)
		{
			this_p->LockQueue();
			while(this_p->IsEmpty())
			{
				this_p->ThreadWait();
			}

			Task t;
			this_p->Get(t);
			this_p->UnLockQueue();
			t.Run();
		}
	}

	void ThreadPoolInit()
	{
		pthread_cond_init(&cond, nullptr);
		pthread_mutex_init(&lock, nullptr);	
		pthread_t t;
		for(size_t i = 0; i < max_num; i++)
		{
			pthread_create(&t, nullptr, Routine, this);
		}
	}

	~ThreadPool()
	{
		pthread_cond_destroy(&cond);
		pthread_mutex_destroy(&lock);
	}
};
