/* SynchronisedQueue.hpp (exercise 3.1.4)
Description:
	* 


*/


#ifndef SYNCHRONISEDQUEUE_HPP
#define SYNCHRONISEDQUEUE_HPP

#include <atomic>
#include <queue>
#include <mutex>

template<typename T>
class SynchronisedQueue
{
private:
	std::queue<T> m_data;
	std::mutex m_mutex;
	std::condition_variable m_cond;
	unsigned remainingIters;
	std::atomic<bool> stop;
public:
	////////////////////////////
	// Constructors/Destructor:
	////////////////////////////
	SynchronisedQueue() : m_data(), m_mutex(), m_cond(), remainingIters(1000)
	{

	}
	SynchronisedQueue(const SynchronisedQueue &in) : m_data(in.m_data), m_mutex(in.m_mutex), m_cond(in.m_cond), remainingIters(in.remainingIters)
	{

	}
	virtual ~SynchronisedQueue()
	{

	}
	////////////////////////////
	// Misc. Methods:
	////////////////////////////
	void Enqueue(const T &data_in)
	{
		m_data.push(data_in);
		// Notify other threads that data has been added:
		cond.notify_one();
	}
	T Dequeue()												/* Add data to queue and notify consumer threads that data */
	{
		std::unique_lock<std::mutex> lock(m_mutex);
		// Wait for producers to add data to the queue:
		while (!m_data.size())
		{
			m_cond.wait(lock);
		}
		T result = m_data.front();
		m_data.pop();

		return result;
	}
	std::atomic<bool> CheckCond()
	{
		return stop;
	}
	////////////////////////////
	// Overloaded Operators:
	////////////////////////////
	SynchronisedQueue& operator=(const SynchronisedQueue &in)
	{
		if (this != &in)
		{
			this->m_data = in.m_data;
			this->m_mutex = in.m_mutex;
		}
		return *this;
	}
};

#endif
