/* ProducerConsumer.hpp (exercise 3.1.4)
Description:
	* Producer stores values in shared synchronised queue, consumer prints values to stdout.
*/


#ifndef PRODUCERCONSUMER_HPP
#define PRODUCERCONSUMER_HPP

#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include "SynchronisedQueue.hpp"

SynchronisedQueue<std::string> syncQueue;

class Producer
{
private:
	int m_id;
public:
	/////////////////////////////
	// Constructors/Destructor:
	/////////////////////////////
	Producer(int id) noexcept : m_id(id)
	{

	}
	virtual ~Producer()
	{

	}
	/////////////////////////////
	// Overloaded Operators:
	/////////////////////////////
	void operator()() noexcept					/* Put data into the synchronized queue. */
	{
		std::stringstream ss;
		int data = 0;
		while (data < 10)
		{
			ss.str("");
			ss << "Producer " << m_id << " data: " << data++;
			syncQueue.Enqueue(ss.str());
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		std::cout << "Producer finished. " << std::endl;
	}
};

class Consumer
{
private:
	int m_id;
public:
	/////////////////////////////
	// Constructors/Destructor:
	/////////////////////////////
	Consumer(int id) noexcept : m_id(id)
	{

	}
	virtual ~Consumer()
	{

	}
	/////////////////////////////
	// Overloaded Operators:
	/////////////////////////////
	void operator()() noexcept					/* Read data from the synchronised queue. */
	{
		int data = 0;
		while (data < 10)
		{
			std::cout << "Consumer " << m_id << " consumed: " << syncQueue.Dequeue() << std::endl;
			data++;
		}
		std::cout << "Done consuming." << std::endl;
	}
};

#endif