/* ProducerConsumer.hpp (exercise 3.1.4)
Description:
	* Producer stores values in shared synchronised queue, consumer prints values to stdout.
*/


#ifndef PRODUCERCONSUMER_HPP
#define PRODUCERCONSUMER_HPP

#include <atomic>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include "SynchronisedQueue.hpp"

SynchronisedQueue<unsigned> syncQueue; /* Queue containing customer ids */
std::atomic<bool> shopClosed;

class Producer /* Customer class */
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
		std::this_thread::sleep_for(std::chrono::seconds());
		if (!syncQueue.Full() && !shopClosed->load())
		{
			std::cout << "Customer " << m_id << ": Has entered shop." << std::endl;
			freeChairs->store(freeChairs->load() - 1);
			std::cout << "Customer " << m_id << ": Has left." << std::endl;
		}
		else if (!freeChairs->load())
		{
			std::cout << "Customer: " << m_id << " Left since shop is full." << std::endl;
		}
		else if (shopClosed->load())
		{
			std::cout << "Customer: Left since shop has closed." << std::endl;
		}
	}
};

class Consumer				/* Barber class */
{
private:
	int m_id;
public:
	/////////////////////////////
	// Constructors/Destructor:
	/////////////////////////////
	Consumer(int id) noexcept : m_id(id)
	{
		shopClosed.store(false);
	}
	virtual ~Consumer()
	{

	}
	/////////////////////////////
	// Overloaded Operators:
	/////////////////////////////
	void operator()() noexcept					/* Read data from the synchronised queue. */
	{
		unsigned serviceCount = 0;
		while (serviceCount < 100)
		{
			// Wait for customers to arrive:
			std::cout << "Barber: Waiting for customers to arrive..." << std::endl;
			while (syncQueue.Size() == 0)
			{
				// wait until customer has arrived.
			}
			while (syncQueue.Size() && serviceCount < 100)
			{
				std::cout << "Barber: Cutting hair..." << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(5));
				std::cout << "Barber: Finished cutting hair." << std::endl;
				serviceCount++;
			}
			
		}
		std::cout << "Barber: Closed shop. " << std::endl;
		shopClosed.store(true);
	}
};

#endif