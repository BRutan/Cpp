/* ProducerConsumer.hpp (exercise 3.1.4)
Description:
	* 



*/


#ifndef PRODUCERCONSUMER_HPP
#define PRODUCERCONSUMER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include "SynchronisedQueue.hpp"

class Producer
{
private:
	int m_id;
	SynchronisedQueue<std::string> *m_data;
public:
	/////////////////////////////
	// Constructors/Destructor:
	/////////////////////////////
	Producer(int id, SynchronisedQueue<std::string> *items) : m_id(id), m_data(items)
	{

	}
	virtual ~Producer()
	{

	}
	/////////////////////////////
	// Overloaded Operators:
	/////////////////////////////
	void operator()()					/* Put data into the synchronized queue. */
	{
		std::stringstream ss;
		int data = 0;
		while (m_data->CheckCond())
		{
			ss.clear();
			ss << "Producer " << m_id << " data: " << data++;
			m_data->Enqueue(ss.str());
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	}
};

template<typename T>
class Consumer
{
private:
	int m_id;
	SynchronisedQueue<T> *m_data;
public:
	/////////////////////////////
	// Constructors/Destructor:
	/////////////////////////////
	Consumer(int id, SynchronisedQueue<T> *items) : m_id(id), m_data(items)
	{

	}
	virtual ~Consumer()
	{

	}
	/////////////////////////////
	// Overloaded Operators:
	/////////////////////////////
	void operator()()					/* Read data from the synchronised queue. */
	{
		while (m_data->CheckCond())
		{
			std::cout << "Consumer " << m_id << " consumed: " << m_data->Dequeue() << std::endl;
		}
	}
};


#endif