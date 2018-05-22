/* SynchronisingQueue.hpp (exercise 3.5.4)
Description:
	*


*/

#ifndef SYNCHRONISINGQUEUE_HPP
#define SYNCHRONISINGQUEUE_HPP

#include <mutex>
#include <condition_variable>
#include <queue>


template<typename T>
class SynchronisingQueue
{
private:
	std::condition_variable cond;
	std::mutex mut;
	std::priority_queue<T> pq;
public:
	////////////////////////////////
	// Constructors/Destructor:
	////////////////////////////////
	SynchronisingQueue()
	{

	}
	SynchronisingQueue(const SynchronisingQueue &in) : pq(in.pq), cond(in.cond), mut(in.mut)
	{

	}
	virtual ~SynchronisingQueue()
	{

	}
	////////////////////////////////
	// Misc Methods:
	////////////////////////////////
	void Enqueue(const T &in)
	{
		std::lock_guard<std::mutex> lock(mut);
		mut.lock();
		pq.push(in);
		mut.unlock();
	}
	T Dequeue()
	{
		std::lock_guard<std::mutex> lock(mut);
		mut.lock();
		return pq.front();
	}
	////////////////////////////////
	// Overloaded Operators:
	////////////////////////////////
	SynchronisingQueue& operator=(const SynchronisingQueue &in)
	{
		if (this != &in)
		{
			this->cond = in.cond;
			this->mut = in.mut;
			this->pq = in.pq;
		}
		return *this;
	}
};



#endif
