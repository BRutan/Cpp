/* ProducerConsumer.hpp (exercise 3.5.5)
Description:
	* Producer stores values in shared synchronised queue, consumer prints values to stdout.
*/


#ifndef PRODUCERCONSUMER_HPP
#define PRODUCERCONSUMER_HPP

#include <atomic>
#include <iostream>
#include <memory>
#include <shared_mutex>
#include <sstream>
#include <string>

std::atomic<bool> shopClosed;
std::atomic<unsigned> dequeued;

class Producer 
{
private:
	int m_id;
	std::shared_timed_mutex &s_mut;
public:
	/////////////////////////////
	// Constructors/Destructor:
	/////////////////////////////
	Producer(int id, std::shared_timed_mutex &in) noexcept : m_id(id), s_mut(in)
	{

	}
	virtual ~Producer()
	{

	}
	/////////////////////////////
	// Overloaded Operators:
	/////////////////////////////
	void operator()() noexcept
	{

	}
};

class Consumer				/* Barber class */
{
private:
	std::shared_timed_mutex &s_mut;
public:
	/////////////////////////////
	// Constructors/Destructor:
	/////////////////////////////
	Consumer(std::shared_timed_mutex &s_mut_in) noexcept : s_mut(s_mut_in)
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

	}
};

#endif