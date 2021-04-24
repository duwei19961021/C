#include <vector>
#include <semaphore.h>

template<class T>
class RingQueue
{
public:
	RingQueue(size_t cap = 10):_v(cap)
	{
		p_index = c_index = 0;
		_max_cap = cap;
		sem_init(&sem_data, 0, 0);	
		sem_init(&sem_blank, 0, _max_cap);
	}

	~RingQueue()
	{
		sem_destroy(&sem_data);
		sem_destroy(&sem_blank);	
		p_index = 0;
		c_index = 0;
	}

	void Get(T &out)
	{
		P(sem_data); // 取数据时，要将数据对应的信号量减1
		out = _v[c_index];
		c_index++;
		c_index %= _max_cap; // 数据减1时对应的装数据的格子增1
		V(sem_blank);
	}

	void Put(T &in)
	{
		P(sem_blank);
		_v[p_index] = in;
		p_index++;
		p_index %= _max_cap;
		V(sem_data);
	}

private:
	void P(sem_t &s)
	{
		sem_wait(&s);
	}

	void V(sem_t &s)
	{
		sem_post(&s);
	}
private:
	std::vector<T> _v;
	size_t _max_cap;	
	sem_t sem_data;
	sem_t sem_blank; 
	size_t p_index;
	size_t c_index;
};
