/* SynchronisedQueue.hpp (exercise 3.1.4)
Description:
	*


*/


#ifndef SYNCHRONISEDQUEUE_HPP
#define SYNCHRONISEDQUEUE_HPP

#include <queue>
#include <mutex>

template<typename T>
class SynchronisedQueue
{
private:
	std::queue<T> m_data;
	std::mutex m_mutex;
public:
	////////////////////////////
	// Constructors/Destructor:
	////////////////////////////
	SynchronisedQueue() : m_data(), m_mutex()
	{

	}
	SynchronisedQueue(const SynchronisedQueue &in) : m_data(in.m_data), m_mutex(in.m_mutex)
	{

	}
	virtual ~SynchronisedQueue()
	{

	}
	////////////////////////////
	// Misc. Methods:
	////////////////////////////
	void Enqueue(const T data_in)
	{

	}
	T Dequeue()
	{

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
