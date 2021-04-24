#ifndef __BLOCK_QUEUE_H__
#define __BLOCK_QUEUE_H__

#include <queue>
#include <iostream>
#include <pthread.h>

template<class T>
class BlockQueue
{
public:
	BlockQueue(size_t cap = 5): _cap(cap)
	{
		pthread_mutex_init(&lock, nullptr);
		pthread_cond_init(&c_cond, nullptr);
		pthread_cond_init(&p_cond, nullptr);
	}

	~BlockQueue()
	{
		pthread_mutex_destroy(&lock);
		pthread_cond_destroy(&c_cond);
		pthread_cond_destroy(&p_cond);
	}

	void Put(T &data)
	{
		LockQueue();
		while(Full())
		{
			WakeUpCon();
			ProWait();
		}
		q.push(data);
		unLockQueue();
	}

	void Get(T &data)
	{
		LockQueue();
		while(Empty())
		{
			WakeUpPro(); // 先唤醒生产者
			ConWait(); // 再休眠消费者
		}
		data = q.front();
		q.pop();
		unLockQueue();
	}

private:
	void ProWait()
	{
		pthread_cond_wait(&p_cond, &lock);
		/*
		 * 1、为什么要等？条件不满足
		 * 2、怎么知道条件是否满足？要判断是否满足条件就必须进入临界区，需要持有锁进入
		 * 3、如果条件不满足就需要阻塞等待，但是不能持有锁去等待！！！(锁被你拿着，其它线程无法获取锁就无法进入临界区，条件就无法发生改变，因此进入死锁状态)，因此wait时必须释放锁。
		 * 4、因此这个函数需要传入一个lock
		 *
		 * 1、在调用该函数时会自动释放锁。
		 * 2、当该函数返回时，返回到了临界区内，所以该函数会让该线程重新持有该锁。
		 */
	}

	void ConWait()
	{
		pthread_cond_wait(&c_cond, &lock);
	}

	void WakeUpPro()
	{
		pthread_cond_signal(&p_cond);
		std::cout << "signal productor" << std::endl;
	}

	void WakeUpCon()
	{
		pthread_cond_signal(&c_cond);
		std::cout << "signal consumer" << std::endl;
	}

	bool Empty()
	{
		return q.empty();
	}

	bool Full()
	{
		return q.size() == _cap;
	}

	void LockQueue()
	{
		pthread_mutex_lock(&lock);
	}

	void unLockQueue()
	{
		pthread_mutex_unlock(&lock);
	}
private:
	pthread_mutex_t lock;
	pthread_cond_t c_cond; // 消费者在该条件下等
	pthread_cond_t p_cond; // 生产者在该条件下等
	std::queue<T> q;
	size_t _cap;
};


#endif
