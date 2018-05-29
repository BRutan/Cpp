/* SynchronisedQueue.hpp (exercise 3.1.4)
Description:
	* Thread safe FIFO queue.
Member Objects:
	* mutex m_mutex: mutual exclusion object to ensure thread safe enqueueing and dequeing.
	* condition_variable m_cond: to signify tasks have finished.
	* queue<T> m_data: FIFO queue to store data.
Class Methods:
	* SynchronisedQueue(): default constructor.
	* ~SynchronisedQueue(): destructor.
	* T Dequeue(): thread safe dequeue, returning top object to caller. 
	* void Enqueue(const T&): thread safe enqueue, adding to back of queue.
*/

#ifndef SYNCHRONISEDQUEUE_HPP
#define SYNCHRONISEDQUEUE_HPP

#define MAXFREECHAIRS 20

#include <queue>
#include <mutex>

std::mutex m_mutex;
std::condition_variable m_cond;

template<typename T>
class SynchronisedQueue
{
private:
	std::queue<T> m_data;
public:
	////////////////////////////
	// Constructors/Destructor:
	////////////////////////////
	SynchronisedQueue() noexcept : m_mutex(), m_cond(), m_data()	/* Default constructor. */
	{

	}
	SynchronisedQueue(const SynchronisedQueue &in) = delete;		/* Deleted copy constructor. */
	virtual ~SynchronisedQueue()
	{

	}
	////////////////////////////
	// Misc. Methods:
	////////////////////////////
	T Dequeue()													/* Return top element in thread-safe manner. */
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
	void Enqueue(const T &data_in)								/* Thread safe enqueue. */
	{
		std::lock_guard<std::mutex> mLock(m_mutex);
		m_data.push(data_in);
		// Notify other threads that data has been added:
		m_cond.notify_one();
	}
	bool Full() noexcept
	{
		return m_data.size() == MAXFREECHAIRS;
	}
	std::size_t Size() noexcept
	{
		return m_data.size();
	}
	////////////////////////////
	// Overloaded Operators:
	////////////////////////////
	SynchronisedQueue& operator=(const SynchronisedQueue &in) = delete; /* Deleted assignment operator. */
};

#endif